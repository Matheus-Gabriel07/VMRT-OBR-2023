// Funções dos motores

void frente(int move) {
  motorLeft.move(move);
  motorRight.move(-move);
}

void reverso (int move) {
  motorLeft.move(-move);
  motorRight.move(move);
}

void statico () {
  motorLeft.move(0);
  motorRight.move(0);
}

void curvaDir (int move) { //Curva para esquerda em um eixo
  motorLeft.move(move);
  motorRight.move(move);
}

void curvaEsq (int move) { //Curva para esquerda em um eixo
  motorLeft.move(-move);
  motorRight.move(-move);

 //Serial.println(motorSteps);
}

void noventinhaEsq(int move){
  unsigned long grausatual = graus;

  while((graus - grausatual) < 362){
    curvaEsq(move);
    Serial.println(graus);
  }
}

void noventinhaDir(int move){
  unsigned long grausatual = graus;

  while((graus - grausatual) < 362){
    curvaDir(move);
    Serial.println(graus);
  }
}
void setup(){
  Serial.begin(115200);
}
void loop(){ 

}