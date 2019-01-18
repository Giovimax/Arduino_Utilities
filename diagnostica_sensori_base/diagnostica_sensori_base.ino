bool stat = false;
long lastAct = 0;

class sensore {
public:
  int pin; //pin del sensore, va dichiarato
  int stat; //stato corrente del sensore
  int prev_stat; //ultimo stato del sensore
  int lastActivationTime; //millis in cui stat è diventato true
  sensore(int pinNum) {
    pin = pinNum;
  }
  void set() { //imposta il pin come imput e setta prev_stat
    pinMode(pin, INPUT);
    prev_stat = false;
  }
  int getStatus(){//legge il valore del pin del sensore
    stat = digitalRead(pin);
  }
  int core(){//
    getStatus();//iniziamo a rilevare lo stato
    if (prev_stat != stat) {//se lo stato è cambiato
      Serial.print("State changed on pin ");
      Serial.println(pin);
      if(stat == true){//se da false passa a true
        Serial.println(stat);
        prev_stat = true;//aggiorno prev_stat
        lastActivationTime = millis();//salvo il tempo di cambio di stato
      }
      else if (stat == false) {//se cambiamo da true a false
        prev_stat = false;//aggiorno prev_stat
        Serial.println(stat);
        int toRet = millis()-lastActivationTime;
        Serial.print("Time passed: ");
        Serial.println(lastActivationTime);
      }
    }
    else if(prev_stat){//non è davvero necessario descrivere questo caso

    }
  }

  long currentM = millis();
};
//creazione delle istanze
sensore sensoreUno(2); //creation of an istance


void setup() {
Serial.begin(9600);
//per ogni sensore
sensoreUno.set();//setting the parameters and the pinMode
sensoreUno.getStatus();//setting the prev_stat

}

void loop() {
  sensoreUno.core();

}
