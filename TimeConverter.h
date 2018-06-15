class FibValues {
  public:
    FibValues() {
      
    }
    void setField(byte t, byte n, bool state) { // t == 0 == hour
      if( t <= 1 ) {
        this->fieldStates[n-1][t] = state; 
      }
    }
    void setFieldHour(int n, bool state) {
      this->fieldStates[n-1][0] = state;
    }
    void setFieldMinute(int n, bool state) {
      this->fieldStates[n-1][1] = state;
    }
    //TODO: private setzen, optimieren
    bool fieldStates[5][2] = {
      // H       M
        {false, false},
        {false, false},
        {false, false},
        {false, false},
        {false, false}
      };
};

class TimeConverter {
  public:
    TimeConverter(byte h, byte m) : hour(h), minute(m) {
      
    }
    FibValues getFibTime( void ) {
      this->calcFieldStated();
      return this->fs;
    }
  private:
    byte hour;
    byte minute;
    FibValues fs;
    
    void calcFieldStated() {
      //hours:
        if( this->hour > 11 ) {
          this->hour -= 12; //normieren auf 0 bis 11 Stunden
        }
        if( this->hour - 5 >= 0 ) {
          fs.setFieldHour(5,true);
          this->hour -= 5;
        }
        if( this->hour - 3 >= 0 ) {
          fs.setFieldHour(4,true);
          this->hour -= 3;
        }
        if( this->hour - 2 >= 0 ) {
          fs.setFieldHour(3,true);
          this->hour -= 2;
        }
        if( this->hour - 1 >= 0 ) {
          fs.setFieldHour(2,true);
          this->hour -= 1;
        }
        if( this->hour - 1 == 0 ) {
          fs.setFieldHour(1,true);
          this->hour -= 1;
        }
        //minutes:

        if( this->minute - 25 >= 0 ) {
          fs.setFieldMinute(5,true);
          this->minute -= 25;
        }
        if( this->minute - 15 >= 0 ) {
          fs.setFieldMinute(4,true);
          this->minute -= 15;
        }
        if( this->minute - 10 >= 0 ) {
          fs.setFieldMinute(3,true);
          this->minute -= 10;
        }
        if( this->minute - 5 >= 0 ) {
          fs.setFieldMinute(2,true);
          this->minute -= 5;
        }
        if( this->minute - 5 == 0 ) {
          fs.setFieldMinute(1,true);
          this->minute -= 5;
        }

    }
};
