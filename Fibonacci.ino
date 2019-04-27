#include "RtcController.h"
#include "TimeConverter.h"
#include "LedController.h"
#include "AlarmClock.h"

class Fibonacci {
  RtcController rtc;
public:
  Fibonacci(RtcController rtc) { 
    this->rtc = rtc;
  }
  
  void update( void ) {
    byte h = rtc.getHour();
      byte m = rtc.getMinute(); //TODO: change to minutes!
      //byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year
//      rtc.setTime(0,23,0,7,27,4,2019);
      TimeConverter tc(h, m);
      FibValues fs = tc.getFibTime();
      laccy.update( fs );

    //Debugging
//      Serial.println( "H:" + (String) h + " M:" + (String) m );
//      for(int lc = 1; lc < 6; lc++) {
//        Serial.println( "Feld " + (String) lc + " H:  " + (String) fs.fieldStates[lc-1][0] + "M: " + (String) fs.fieldStates[lc-1][1] );
//      }
//      Serial.println(laccy.getController());
//      Serial.println(); 
    }
  private:
    LedController laccy;
  };

  void setup()
  {
//  Serial.begin(9600);
   
  // set the initial time here:
//   DS3231 seconds, minutes, hours, day, date, month, year
  // setDS3231time(0,54,19,5,26,4,18);
//   //fib

// Uhr stellen:
//   DS3231 seconds, minutes, hours, day, date, month, year
//RtcController rtc1;
  //Serial.begin(9600);
//rtc1.setTime(0,5,16,4,31,5,18);
//Uhr stellen ENDE


  }

  RtcController rtc;
  Fibonacci fib(rtc);
  AlarmClock alarmClock(rtc, 2, 3);

  void loop()
  {
    delay(5000);
    
    fib.update();

    if(alarmClock.isAlarmTime()){
     Partitur partitur(16);
     partitur.playCantina(); 
   }

 }
