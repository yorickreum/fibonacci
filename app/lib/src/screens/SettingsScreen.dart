import 'dart:convert';
import 'dart:developer';
import 'dart:typed_data';
import 'package:flutter/material.dart';
import 'package:flutter_bluetooth_serial/flutter_bluetooth_serial.dart';

class SettingsScreen extends StatefulWidget {
  final BluetoothDevice device;

  const SettingsScreen({this.device});

  @override
  _SettingsScreen createState() => new _SettingsScreen();
}

class _SettingsScreen extends State<SettingsScreen> {
  static final clientID = 0;
  BluetoothConnection connection;

  bool isConnecting = true;

  bool get isConnected => connection != null && connection.isConnected;
  bool isDisconnecting = false;

  String _messageBuffer = '';
  String _lastMessage;

  bool isLedOn = false;

  @override
  void initState() {
    super.initState();

    BluetoothConnection.toAddress(widget.device.address).catchError((error) {
      log("Something went wrong while connection, error: " + error.toString());
    }).then((_connection) {
      print('Connected to the device');
      connection = _connection;
      setState(() {
        isConnecting = false;
        isDisconnecting = false;
      });

      connection.input.listen(_onDataReceived).onDone(() {
        // Example: Detect which side closed the connection
        // There should be `isDisconnecting` flag to show are we are (locally)
        // in middle of disconnecting process, should be set before calling
        // `dispose`, `finish` or `close`, which all causes to disconnect.
        // If we except the disconnection, `onDone` should be fired as result.
        // If we didn't except this (no flag set), it means closing by remote.
        if (isDisconnecting) {
          print('Disconnecting locally!');
        } else {
          print('Disconnected remotely!');
        }
        if (this.mounted) {
          setState(() {});
        }
      });
    }).catchError((error) {
      print('Cannot connect, exception occured');
      print(error);
    });
  }

  @override
  void dispose() {
    // Avoid memory leak (`setState` after dispose) and disconnect
    if (isConnected) {
      isDisconnecting = true;
      connection.dispose();
      connection = null;
    }

    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
            title: (isConnecting
                ? Text('Connecting to ' + widget.device.name + '...')
                : isConnected
                    ? Text('Change settings of ' + widget.device.name)
                    : Text('Not connected to ${widget.device.name}!'))),
        body: SafeArea(
          child: !isConnected
              ? const Text("No connection! Wait a bit..")
              : ListView(children: <Widget>[
                  SwitchListTile(
                    title: const Text('Toggle LED'),
                    value: isLedOn,
                    onChanged: (bool newIsLedOn) {
                      newIsLedOn
                          ? this._sendCommand("on")
                          : this._sendCommand("off");
                      this.setState(() {
                        isLedOn = newIsLedOn;
                      });
                    },
                  ),
                  Divider(
                    color: Theme.of(context).primaryColor,
                  ),
                  ListTile(
                    title: const Text("Last message from device"),
                    subtitle: Text(_lastMessage ?? "–"),
                  )
                ]),
        ));
  }

  void _onDataReceived(Uint8List data) {
    // Allocate buffer for parsed data
    int backspacesCounter = 0;
    data.forEach((byte) {
      if (byte == 8 || byte == 127) {
        backspacesCounter++;
      }
    });
    Uint8List buffer = Uint8List(data.length - backspacesCounter);
    int bufferIndex = buffer.length;

    // Apply backspace control character
    backspacesCounter = 0;
    for (int i = data.length - 1; i >= 0; i--) {
      if (data[i] == 8 || data[i] == 127) {
        backspacesCounter++;
      } else {
        if (backspacesCounter > 0) {
          backspacesCounter--;
        } else {
          buffer[--bufferIndex] = data[i];
        }
      }
    }

    // Change message if there is new line character
    String dataString = String.fromCharCodes(buffer);
    int index = buffer.indexOf(13);
    if (~index != 0) {
      // \r\n
      setState(() {
        DateTime now = new DateTime.now();
        String _lastMessageText = backspacesCounter > 0
            ? _messageBuffer.substring(
                0, _messageBuffer.length - backspacesCounter)
            : _messageBuffer + dataString.substring(0, index);
        _lastMessage = "at " + now.toIso8601String() + ": " + _lastMessageText.replaceAll("\n", "");
        _messageBuffer = dataString.substring(index);
      });
    } else {
      _messageBuffer = (backspacesCounter > 0
          ? _messageBuffer.substring(
              0, _messageBuffer.length - backspacesCounter)
          : _messageBuffer + dataString);
    }
  }

  void _sendCommand(String command) async {
    command = command.trim();

    if (command.length > 0) {
      try {
        connection.output.add(utf8.encode(command)); // + "\r\n"
        await connection.output.allSent;
      } catch (e) {
        // Ignore error, but notify state
        setState(() {});
      }
    }
  }
}
