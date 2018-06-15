

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
  public:
  Pat(){}
  int buzpin=16;
  int tl=500;
  void note(int f,int lae){
    tone(buzpin,f,lae*tl);
    delay(lae*tl);
    }
  void pause(int lae){
    delay(lae*tl);
    }
  void schwan(void){
    this->tl=500;
    this->note(gi,2);
    this->note(gesi,2);
    this->note(hi,2);
    this->note(ei,2);
    this->note(di,2);
    this->note(g,2);

    this->note(a,5);
    this->note(h,1);
    this->note(ci,4);
    this->pause(2);

    this->note(e,4);
    this->note(f,1);
    this->note(g,1);
    this->note(a,1);
    this->note(h,1);
    this->note(ci,1);
    this->note(di,1);
    this->note(ei,1);
    this->note(gesi,1);

    this->note(hi,7);
    this->pause(5);

    this->note(gi,2);
    this->note(gesi,2);
    this->note(h,2);
    this->note(ei,2);
    this->note(di,2);
    this->note(g,2);
    
    this->note(b,5);
    this->note(h,1);
    this->note(desi,6);
//
//schlechter Klang:
    this->note(d,3);
    this->note(as,1);
    this->note(b,1);
    this->note(h,1);
    this->note(desi,1);
    this->note(di,1);
    this->note(ei,1);
    this->note(fi,1);
    this->note(asi,1);
    this->note(bi,1);

    this->note(dii,7);
    this->pause(5);
    }
    void cantina(void){
      this->tl=150;
      this->note(gesii,2);
      this->note(hii,2);
      this->note(gesii,2);
      this->note(hii,2);

      this->note(gesii,1);
      this->note(hii,2);
      this->note(gesii,1);
      this->pause(1);
      this->note(fii,1);
      this->note(gesii,2);

      this->note(gesii,1);
      this->note(fii,1);
      this->note(gesii,1);
      this->note(eii,1);
      this->pause(1);
      this->note(esii,1);
      this->note(eii,1);
      this->note(desii,1);

      this->note(dii,3);
      this->note(hi,5);

      this->note(gesii,2);
      this->note(hii,2);
      this->note(gesii,2);
      this->note(hii,2);

      this->note(gesii,1);
      this->note(hii,2);
      this->note(gesii,1);
      this->pause(1);
      this->note(fii,1);
      this->note(gesii,2);

      this->note(eii,2);
      this->note(eii,3);
      this->note(esii,1);
      this->note(eii,2);

      this->note(aii,1);
      this->note(gii,2);
      this->note(gesii,2);
      this->note(eii,3);

      this->note(gesii,2);
      this->note(hii,2);
      this->note(gesii,2);
      this->note(hii,2);

      this->note(gesii,1);
      this->note(hii,2);
      this->note(gesii,1);
      this->pause(1);
      this->note(fii,1);
      this->note(gesii,2);

      this->note(aii,2);
      this->note(aii,2);
      this->note(gesii,1);
      this->note(eii,2);

      this->note(dii,3);
      this->note(hi,5);

      this->note(hi,4);
      this->note(dii,4);

      this->note(gesii,4);
      this->note(aii,4);

      this->note(ciii,2);
      this->note(hii,2);
      this->note(fii,1);
      this->note(gesii,2);
      this->note(dii,1);
    }
};




