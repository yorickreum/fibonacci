class AlarmClock {
  int WECKSTUNDE;
  int WECKMINUTE;
  RtcController rtc;
public:
  AlarmClock(RtcController rtc, int WECKSTUNDE, int WECKMINUTE) {
    this->rtc = rtc;
    this->WECKSTUNDE = WECKSTUNDE;
    this->WECKMINUTE = WECKMINUTE;
  }
  boolean isAlarmTime() {
    int h = this->rtc.getHour();
    int m = this->rtc.getMinute();
    if(h==this->WECKSTUNDE && m==this->WECKMINUTE){
      return true;
    } else {
      return false;
    }
  };
private:
 
};




//Noten:
float c=130.84;
float des=138.59;
float d=146.83;
float es   =155.56;
float e   =164.81;
float f   =174.61;
float ges = 185.00;
float g   =196.00;
float as  =207.65;
float a   =220.00;
float b   =233.08;
float h   =246.94;
float ci   =261.63;
float desi=   277.18;
float di  =293.66;
float esi = 311.13;
float ei  =329.63;
float fi  =349.23;
float gesi=   369.99;
float gi  =392.00;
float asi = 415.30;
float ai  =440.00;
float bi  =466.16;
float hi  =493.88;
float cii = 523.25;
float desii   =554.37;
float dii   =587.33;
float esii  =622.25;
float eii   =659.26;
float fii   =698.46;
float gesii   =739.99;
float gii   =783.99;
float asii  =830.61;
float aii   =880.00;
float bii   =932.33;
float hii   =987.77;
float ciii   =1046.50;
float desiii  =1108.73;
float diii  =1174.66;
float esiii   =1244.51;
float eiii  =1318.51;
float fiii  =1396.91;
float gesiii  =1479.98;
float giii  =1567.98;
float asiii   =1661.22;
float aiii  =1760.00;
float biii  =1864.66;
float hiii  =1975.53;

class Partitur{
  int buzpin=16;
public:
  Partitur(int buzpin){
    this->buzpin =  buzpin;
  }
  int tl=500;
  void playNote(int f,int lae){
    tone(buzpin,f,lae*tl);
    delay(lae*tl);
  }
  void pause(int lae){
    delay(lae*tl);
  }
  void playSchwan(void){
    this->tl=500;
    this->playNote(gi,2);
    this->playNote(gesi,2);
    this->playNote(hi,2);
    this->playNote(ei,2);
    this->playNote(di,2);
    this->playNote(g,2);

    this->playNote(a,5);
    this->playNote(h,1);
    this->playNote(ci,4);
    this->pause(2);

    this->playNote(e,4);
    this->playNote(f,1);
    this->playNote(g,1);
    this->playNote(a,1);
    this->playNote(h,1);
    this->playNote(ci,1);
    this->playNote(di,1);
    this->playNote(ei,1);
    this->playNote(gesi,1);

    this->playNote(hi,7);
    this->pause(5);

    this->playNote(gi,2);
    this->playNote(gesi,2);
    this->playNote(h,2);
    this->playNote(ei,2);
    this->playNote(di,2);
    this->playNote(g,2);
    
    this->playNote(b,5);
    this->playNote(h,1);
    this->playNote(desi,6);
//
//schlechter Klang:
    this->playNote(d,3);
    this->playNote(as,1);
    this->playNote(b,1);
    this->playNote(h,1);
    this->playNote(desi,1);
    this->playNote(di,1);
    this->playNote(ei,1);
    this->playNote(fi,1);
    this->playNote(asi,1);
    this->playNote(bi,1);

    this->playNote(dii,7);
    this->pause(5);
  }
  void playCantina(void){
    this->tl=150;
    this->playNote(gesii,2);
    this->playNote(hii,2);
    this->playNote(gesii,2);
    this->playNote(hii,2);

    this->playNote(gesii,1);
    this->playNote(hii,2);
    this->playNote(gesii,1);
    this->pause(1);
    this->playNote(fii,1);
    this->playNote(gesii,2);

    this->playNote(gesii,1);
    this->playNote(fii,1);
    this->playNote(gesii,1);
    this->playNote(eii,1);
    this->pause(1);
    this->playNote(esii,1);
    this->playNote(eii,1);
    this->playNote(desii,1);

    this->playNote(dii,3);
    this->playNote(hi,5);

    this->playNote(gesii,2);
    this->playNote(hii,2);
    this->playNote(gesii,2);
    this->playNote(hii,2);

    this->playNote(gesii,1);
    this->playNote(hii,2);
    this->playNote(gesii,1);
    this->pause(1);
    this->playNote(fii,1);
    this->playNote(gesii,2);

    this->playNote(eii,2);
    this->playNote(eii,3);
    this->playNote(esii,1);
    this->playNote(eii,2);

    this->playNote(aii,1);
    this->playNote(gii,2);
    this->playNote(gesii,2);
    this->playNote(eii,3);

    this->playNote(gesii,2);
    this->playNote(hii,2);
    this->playNote(gesii,2);
    this->playNote(hii,2);

    this->playNote(gesii,1);
    this->playNote(hii,2);
    this->playNote(gesii,1);
    this->pause(1);
    this->playNote(fii,1);
    this->playNote(gesii,2);

    this->playNote(aii,2);
    this->playNote(aii,2);
    this->playNote(gesii,1);
    this->playNote(eii,2);

    this->playNote(dii,3);
    this->playNote(hi,5);

    this->playNote(hi,4);
    this->playNote(dii,4);

    this->playNote(gesii,4);
    this->playNote(aii,4);

    this->playNote(ciii,2);
    this->playNote(hii,2);
    this->playNote(fii,1);
    this->playNote(gesii,2);
    this->playNote(dii,1);
  }
};
