class Led {
  private:
    unsigned long lastBlink;

    void init() {
      //Configura o pino do LED
      pinMode(ledPin, OUTPUT);
    }

  public :
    byte ledPin;     //Pino do led
    bool state;      //Indica o estado do LED

    led(byte ledPin) {
      this-> ledPin = ledPin;
      this-> init();
    }

    void set(bool _state) {
      state = _state;
      digitalWrite(ledPin, state);
    }

    /*
        Liga o LED
    */

    void on(){
      state = 1;
      digitalWrite(ledPin, state);
    }

    /*
       Desliga o LED
    */

    void off(){
      state = 0;
      digitalWrite(ledPin, state);
    }

    /*
       Inverte o estado do LED
    */
    void toggle() {
      state = !state;
      digitalWrite(ledPin, state);
    }

    /*
       Piscar LED
    */
    void blink(int timeout = 150) {
      if (millis() < lastBlink + timeout) {
        return;
      }

      this->toggle();
      lastBlink = millis;
    }
};
