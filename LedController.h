class LedField {
  public:
    LedField( byte p ) : pinR(p), pinY(p + 1), pinB(p + 2)
    {
      pinMode(pinR, OUTPUT);
      digitalWrite(pinR, LOW);
      pinMode(pinY, OUTPUT);
      digitalWrite(pinY, LOW);
      pinMode(pinB, OUTPUT);
      digitalWrite(pinB, LOW);
    }
    void update(char s) {
      digitalWrite(pinR, LOW);
      digitalWrite(pinY, LOW);
      digitalWrite(pinB, LOW);
      this->state = s;
      switch (s) {
        case 'r':
          digitalWrite(pinR, HIGH);
          break;
        case 'y':
          digitalWrite(pinY, HIGH);
          break;
        case 'b':
          digitalWrite(pinB, HIGH);
          break;
        default:
          break;
      }
    }
    char getState( void ) {
      return state;
    }
  private:
    char state;
    short pinR;
    short pinY;
    short pinB;
};


class LedController {
  public:
    LedController() :
      fieldArray( {
      LedField(0), LedField(3), LedField(6), LedField(9), LedField(12)
    }) {
    }
    void update(FibValues fs) {
      FibValues f = this->optimizeFields(fs);
      calcNewStates( f );
    }
    String getController( void ) {
      String states = "";
      for (int lc = 0; lc < 5; lc++) {
        states += fieldArray[lc].getState();
      }
      return states;
    }
  private:
    LedField fieldArray[5];

    FibValues optimizeFields(FibValues fs) {
      
      
      // 5 aufteilen:
      if ( fs.fieldStates[4][0] && fs.fieldStates[4][1] ) {
        for ( int i = 1; i >= 0; i-- ) {
          if ( !fs.fieldStates[3][i] ) {
            if ( !fs.fieldStates[2][i] ) {
              fs.setField(i, 5, false);
              fs.setField(i, 4, true);
              fs.setField(i, 3, true);
              break;
              
            }
            else {
              if(!fs.fieldStates[0][i] && !fs.fieldStates[1][i]){
                fs.setField(i, 5, false);
                fs.setField(i, 4, true);
                fs.setField(i, 2, true);
                fs.setField(i, 1, true);
                break;
              }
              
            }
          }
        }
      }

      // 3 aufteilen:
      if ( fs.fieldStates[3][0] && fs.fieldStates[3][1] ) {
        for ( int i = 1; i >= 0; i-- ) {
          if ( !fs.fieldStates[2][i] ) {
            if ( !fs.fieldStates[1][i] ) {
              fs.setField( i, 4, false );
              fs.setField( i, 3, true );
              fs.setField( i, 2, true );
              break;
              
            }
            else {
              if(fs.fieldStates[0][i]){
                fs.setField( i, 4, false );
                fs.setField( i, 3, true );
                fs.setField( i, 1, true );
                break;
              }
            }
          }
        }
      }
      
      // 2 aufteilen:
      if ( fs.fieldStates[2][0] && fs.fieldStates[2][1] ) {
        for ( int i = 1; i >= 0; i-- ) {
          if ( !fs.fieldStates[0][i] && !fs.fieldStates[1][i] ) {
            fs.setField( i, 3, false);
            fs.setField( i, 2, true);
            fs.setField( i, 1, true);
            break;
          }
        }
      }
      
      // 1.2 aufteilen:
      if ( fs.fieldStates[1][0] && fs.fieldStates[1][1] ) {
        for ( int i = 1; i >= 0; i-- ) {
          if ( !(fs.fieldStates[0][i]) ) {
            fs.setField(i, 2, false);
            fs.setField(i, 1, true);
            break;
          }
        }
      }
      
      return fs;
    }

    void calcNewStates(FibValues fs) {
      for (int lc = 0; lc < 5; lc++) {
        if ( fs.fieldStates[lc][0] ) {
          if ( fs.fieldStates[lc][1] ) {
            fieldArray[lc].update('y');
          }
          else {
            fieldArray[lc].update('r');
          }
        }
        else {
          if ( fs.fieldStates[lc][1] ) {
            fieldArray[lc].update('b');
          }
          else {
            fieldArray[lc].update('o');
          }
        }
      }
    }

};
