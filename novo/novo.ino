#include <Encoder.h>
#include <HCSR04.h>
#include <QTRSensors.h>

//Sensor de Giroscópico
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
long timer = 0;
double gyro;
int alvo;

//DECLARAÇÃO DOS SENSORES DE REFLETÂNCIA
#define sensor1 A12
#define sensor2 A11
#define sensor3 A9
#define sensor4 A8
#define sensorMeio A10

//DECLARAÇÃO DOS SENSORES DE COR
#define cor1 A14  //CABO AZUL
#define cor2 A15  //CABO VERDE

//DECLARAÇÃO DOS MOTORES 

#define G1 12   //motor GARRA
#define G2 13   //motor GARRA
Encoder encoderM1(18, 19);
Encoder encoderM2(20, 21);
#define C1 10  //motor comporta
#define C2 11  //motor comporta

//declaração ultrassonicos (Mudar portas)

#define T_PIN_frente 45
#define E_PIN_frente 44
UltraSonicDistanceSensor u_frente(T_PIN_frente, E_PIN_frente);
#define T_PIN_lat 51
#define E_PIN_lat 50
UltraSonicDistanceSensor u_Esq(T_PIN_lat, E_PIN_lat);
#define T_PIN_late 48
#define E_PIN_late 49
UltraSonicDistanceSensor u_Dir(T_PIN_late, E_PIN_late);
#define T_PIN_late 46
#define E_PIN_late 47
UltraSonicDistanceSensor u_Top(T_PIN_late, E_PIN_late);

boolean rampa = false;
int ultima_medida, contador = 0;
int dist_esq, dist_dir = 10000;
int dist_garra = 20;


// olhar o robô, , de frente para onde sobe a fiação dos motores. motor a direita, é o que está a sua direita. esquerda a mesma coisa, mas a esquerda


//REGULAGEM DO ROBÔ COMEÇA AQUI
float GiroX = 0.0;  // GIRO os copium X
float GiroZ = 0.0;  // Giro os copium Z
int preto = 640;    //define valor de refletância para o preto. mudar aqui, após testar os sensores
int corte = 905;    //define valor que o sensor de refletância, descarta. usamos para acertar os redutores de velocidade
int l_linha = 300;  //define extensão da linha, perpendicularmente ao robô. tempo que o robô tem que andar, para ultrapassar uma linha em um cruzamento
int ajuste = 100;   //distância que regula a posição do sensor de cor
int verde1 = 570;
int verde2 = 750;        //leitura do verde
int corte_verde1 = 10000;  //corte para o verde
int corte_verde2 = 10000;  //corte para o verde
//Velocidade dos Motores
int vel_motor = 25;
int vel_curva=15;
int FG = 150;
int FC = 100;
int tempo_atual = 0;
int tempo = 0;
int contadorGyro = 0;
float obst = 0;
float distancia_parada = 11;


//Valores dos obstáculos
int curvanoventa = 1650;  //número de pulsos do encoder para uma curva de noventa graus
int curvanoventaesqu = 1450;
int curva_direita = 2000;   //período que o robô leva para fazer uma curva de 90º direita
int curva_esquerda = 1700;  //período que o robô leva para fazer uma curva de 90º esquerda
int comp_obs = 5000;        //comprimento do obstáculo
int larg_obs = 4750;        //largura do obstáculo

//REGULAGEM DO ROBÔ ACABA AQUI

//Classe do botão

class button {
  private:
    byte debounce;
    unsigned long nextRead;
    bool _hasEstade;

    void init() {
      pinMode(pin, INPUT_PULLUP);
    }

  public:
  byte pin;
  bool estado;

  button(byte _pin, byte _debounce = 10) {
    this->pin = _pin;
    this->debounce = _debounce;
    this->init();
  }

  bool read() {
    if (millis() > nextRead && digitalRead(pin) != estado) {
      estado = !estado;
      _hasEstade = true;
      nextRead = millis() + debounce;
    }
    return estado;
  }

  bool hasEstade() {
    read();
    if (_hasEstade) {
      _hasEstade = true;
      return true;
    }
    return false;
  }

  bool pressed() {  //Se esta precionado
    read();
    return !estado;
  }

  bool released() {  //Se esta solto
    read();
    return estado;
  }

  bool risingEdge() {  //Indica se houve uma borda de subida
    return !read() && hasEstade();
  }

  bool fallingEdge() {  //Indica se houve uma borda de descida
    return read() && hasEstade();
  }

  void waitForPress(void (*doWhileWait)() = ([]() -> void {})) {  //Espera o botão ser pressionado enquando executa uma ação
    while (!pressed()) {
      doWhileWait();
    }
  }


  void waitForRealease(void (*doWhileWait)() = ([]() -> void {})) {  //Espera o botão ser solto enquando executa uma ação
    while (!released()) {
      doWhileWait();
    }
  }

  void waitForPressAndRealease(void (*doBeforePress)() = ([]() -> void {}), void (*doBeforeRealease)() = ([]() -> void {})) {  //Espera o botão ser pressionado enquanto executa uma ação e depois espera ser solto executando outra ação (lambda)
    while (!pressed()) {
      doBeforePress();
    }
    while (!released()) {
      doBeforeRealease();
    }
  }
};

//Declaração dos botões
button startButton(43);
button bumper(42);
button F1(39);
button F2(37);
button F3(35);

//Classe led
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

//Declaração dos LEDs
led redLEDesq(36);
led greenLEDcenter(34);
led redLEDdir(32);

// Amarzenamento
int arrayCor1[256] = {0};
int arrayCor2[256] = {0};
unsigned char posIn1 = 0, posIn2 = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  
  setupMotor(0);

  //Sensores de refletancia
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensorMeio, INPUT);

  //Leds
  redLEDesq.on();
  greenLEDcenter.on();
  redLEDdir.on();

  /*
    qtr.setTypeRC();
    qtr.setSensorPins((const uint8_t[]){2,3, 4, 5, 6, 7, 8, 9}, SensorCount);
    qtr.setEmitterPin(2);

    int FT = 100;*/
}

void debugLoop() {
  Serial.print("sensor1: ");
  Serial.print(analogRead(sensor1));
  Serial.print(" ") ; 
  Serial.print("sensor2: ");
  Serial.print (analogRead(sensor2));
  Serial.print(" ");
  Serial.print("sensor3: ");
  Serial.print(analogRead(sensor3));
  Serial.print(" ");
  Serial.print("sensor4");
  Serial.print(analogRead(sensor4));
  Serial.print("sensorMeio: ");
  Serial.print(analogRead(sensorMeio));
  Serial.print(" ");
  Serial.print("sensorCor1: ");
  Serial.print(analogRead(cor1));
  Serial.print(" ");
  Serial.print("sensorCor2: ");
  Serial.print(analogRead(cor2));
  Serial.print(" ");
  Serial.println(" "); 
}

void loop() {
  aguardo();

  if(F2.pressed()){
    debugLoop();
  }
  
  if(F1.pressed()){
    run();
  }
}

/*
  while (rampa == false) {



    int leitura_verdade = leitura_sensor();          // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
    Serial.println(leitura_verdade);                 // imprime as leituras em serial
    segue_linha(leitura_verdade);                    // sobe condição da leitura atual no segue linha



    tempo_atual = millis();


    tempo = tempo_atual - ultima_medida;
  }
    //Serial.println(tempo);
   /*
    if (tempo > 50) {
      ultima_medida = tempo_atual;
      tempo = 0;
      obst = distancia_frente();
      dist_dir = distancia_lateral();
      dist_esq = esq_distancia_lateral();
      Serial.println("entrei");
        if (obst < distancia_parada && obst!=0 ) {
          Serial.println("DESVIA");
          desvia();
        }



        if (dist_dir < 10 || dist_esq < 10 && dist_dir != 0 && dist_esq != 0){
          contador = contador + 1;
          Serial.println(contador);
          Serial.println(dist_dir);
          Serial.println(dist_esq);
          }
          else{
            contador = 0;
            }

            if (contador > 10){
              rampa = true;
              }


    }

    Serial.println(leitura_verdade);
    Serial.println(obst);
  }

  while (rampa == true){

    int leitura_verdade = leitura_sensor();          // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
    Serial.println(contador);
    Serial.println("rampa");                 // imprime as leituras em serial
    segue_rampa(leitura_verdade);                    // sobe condição da leitura atual no segue linha
    tempo_atual = millis();
    tempo = tempo_atual - ultima_medida;
    if (tempo > 100) {
      ultima_medida = tempo_atual;
      tempo = 0;
      dist_dir = distancia_lateral();
      dist_esq = esq_distancia_lateral();
      Serial.println(dist_esq);
        if (dist_esq > 10 ){
          contador = contador + 1;

          }
          else{
            contador = 0;
            }

         if (contador > 10){
           rampa = false;
              }
    }
  }

  while (rampa == false){

  delay(10000);
  resgate();
  }
*/
