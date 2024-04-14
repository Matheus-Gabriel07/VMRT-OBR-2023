#include "Motor_class.h"
// Configuração dos motores

stepperMotor motorLeft(
  3,    // Step pin
  6,    // Direction pin
  8,    // Enable pin
  400,  // Resolution
  4490, // Minimum velocity
  256   // Maximum velocity
);

stepperMotor motorRight(
  2,    // Step pin
  5,    // Direction pin
  8,    // Enable pin
  400,  // Resolution
  4490, // Minimum velocity
  256   // Maximum velocity
);

// Métodos dos motores

void frente(int move) {
  motorLeft.move(move);
  motorRight.move(-move);
}

void reverso (int move) {
  motorLeft.move(-move);
  motorRight.move(move);
}

void frear (int move) {
  motorLeft.move(0);
  motorRight.move(0);
}


void curvaDireita(int move) {
  motorLeft.move(move);
  motorRight.move(move);
}

void curvaEsquerda(int move){
  motorLeft.move(-move);
  motorRight.move(-move);
}

void curvaNoventaEsquerda(int move){
  unsigned long grausatual = graus;

  while((graus - grausatual) < 362){
    curvaEsquerda(move);
    Serial.println(graus);
  }
  frear(0);
}

void curvaNoventaDireita(int move){
  unsigned long grausatual = graus;

  while((graus - grausatual) < 362){
    curvaDireita(move);
    Serial.println(graus);
  }
  frear(0);
}

void setupMotor(int state){
  if(state ==  0){
    motorLeft.off();
    motorRight.off();
  }
  if(state == 1){
     motorLeft.on();
    motorRight.on();
  }
}
