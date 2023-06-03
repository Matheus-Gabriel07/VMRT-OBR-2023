// Funções dos motores

void frente(int move) {
  motorLeft.move(move);
  motorRight.move(-move);
}

void reverso (int move) {
  motorLeft.move(-move);
  motorRight.move(move);
}

void statico (int move) {
  motorLeft.move(0);
  motorRight.move(0);
}

void curvaEsq(int move) { //Curva para esquerda em um eixo
  motorLeft.move(move);
  motorRight.move(0);
}

void curvaDir(int move) { //Curva para direita em um eixo
  motorLeft.move(0);
  motorRight.move(-move);
}
