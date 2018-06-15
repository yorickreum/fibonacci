#include "RtcController.h"
#include "TimeConverter.h"
#include "LedController.h"
#include "wecker.h"

int WECKSTUNDE=25;
int WECKMINUTE=61;
bool alarm=false;




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

      if(h==WECKSTUNDE && m==WECKMINUTE){
        alarm=true;
      }

    //Debugging
//      Serial.println( "H:" + (String) h + " M:" + (String) m );
//      for(int lc = 1; lc < 6; lc++) {
//        Serial.println( "Feld " + (String) lc + " H:  " + (String) fs.fieldStates[lc-1][0] + "M: " + (String) fs.fieldStates[lc-1][1] );
//      }
//      Serial.println(laccy.getController());
//      Serial.println(); 
    }
   private:
    RtcController rtc;
    LedController laccy;
};

void setup()
{
  alarm=true;
   
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


Fibonacci fib;


void loop()
{

  
  delay(5000);
  
  fib.update();

  if(alarm){
   Partitur song;
   song.cantina(); 
   //alarm=false;

  }

}
