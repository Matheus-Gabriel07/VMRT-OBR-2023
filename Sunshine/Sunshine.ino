#include <HCSR04.h>
#include <QTRSensors.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
#include "Button_class.h"
#include "Led_class.h"

MPU6050 mpu6050(Wire);
long timer = 0;
double gyro;
int alvo;

// Declaração dos sensores refletância - Preto
#define sensor1 A12
#define sensor2 A11
#define sensor3 A9
#define sensor4 A8
#define sensorMeio A10

// Declaração dos sensores refletância - Verde
#define cor1 A14
#define cor2 A15

// Declaração dos botões
button startButton(43);
button bumper(42);
button F1(39);
button F2(37);
button F3(35);

// Declaração dos leds
led redLEDesq(36);
led greenLEDcenter(34);
led redLEDdir(32);

// Declaração dos sensores ultrasônicos
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


//REGULAGEM DO ROBÔ COMEÇA AQUI
float GiroX = 0.0;  // GIRO os copium X
float GiroZ = 0.0;  // Giro os copium Z
int preto = 650;    //define valor de refletância para o preto. mudar aqui, após testar os sensores
int corte = 905;    //define valor que o sensor de refletância, descarta. usamos para acertar os redutores de velocidade
int l_linha = 300;  //define extensão da linha, perpendicularmente ao robô. tempo que o robô tem que andar, para ultrapassar uma linha em um cruzamento
int ajuste = 100;   //distância que regula a posição do sensor de cor
int verde1 = 820;
int verde2 = 880;        //leitura do verde
int corte_verde1 = 10000;  //corte para o verde
int corte_verde2 = 10000;  //corte para o verde

int vel_motor = 20;
int vel_curva=15;
int tempo_atual = 0;
int tempo = 0;
int graus = 0;
boolean rampa = false;

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