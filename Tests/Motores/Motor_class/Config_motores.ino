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

void curvaEsq (int move) { //Curva para esquerda em um eixo
  motorLeft.move(-move);
  motorRight.move(-move);
}

void curvaDir (int move) { //Curva para direita em um eixo
  motorLeft.move(move);
  motorRight.move(move);
}

void setup(){
  Serial.begin(115200);
}
void loop(){
  while(millis()<5000){
  frente(100);
  }
  while(millis()<10000){
  statico();
  }
  while(millis()<15000){
  curvaDir(100);
  }

  while(millis()<20000){
  curvaEsq(100);
  }
  
  statico();
  statico();
}
