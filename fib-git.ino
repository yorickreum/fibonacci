#include "RtcController.h"
#include "TimeConverter.h"
#include "LedController.h"

// git test

class Fibonacci {
  public:
    Fibonacci() { }
    void update( void ) {
      byte h = rtc.getHour();
      byte m = rtc.getMinute(); //TODO: change to minutes!
      // rtc.setTime(0,16,19,5,17,5,2018);
      TimeConverter tc(h, m);
      FibValues fs = tc.getFibTime();
      laccy.update( fs );

    //Debugging
//      Serial.println( "H:" + (String) h + " M:" + (String) m );
      /*for(int lc = 1; lc < 6; lc++) {
        Serial.println( "Feld " + (String) lc + " H:  " + (String) fs.fieldStates[lc-1][0] + "M: " + (String) fs.fieldStates[lc-1][1] );
      }*/ /*
      Serial.println(laccy.getController());
      Serial.println(); */
    }
   private:
    RtcController rtc;
    LedController laccy;
};

void setup()
{
   
  // set the initial time here:
  // DS3231 seconds, minutes, hours, day, date, month, year
  // setDS3231time(0,54,19,5,26,4,18);
   //fib
//  Serial.begin(9600);
}


Fibonacci fib;
void loop()
{
  delay(5000);
  fib.update();
}
