class led {
  private:
    unsigned long lastBlink;

    void init() {
      //Configura o pino do LED
      pinMode(pin, OUTPUT);
    }

  public:
    byte pin;     //Pino do led
    bool state;      //Indica o estado do LED

    led(byte _pin) {
      this-> pin = _pin;
      this-> init();
    }

    void set(bool _state) {
      state = _state;
      digitalWrite(pin, state);
    }

    /*
        Liga o LED
    */
    void on(){
      state = 1;
      digitalWrite(pin, state);
    }

    /*
       Desliga o LED
    */
    void off(){
      state = 0;
      digitalWrite(pin, state);
    }

    /*
       Inverte o estado do LED
    */
    void toggle() {
      state = !state;
      digitalWrite(pin, state);
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

led redLEDesq(27);
led greenLEDcenter(28);
led redLEDdir(29);