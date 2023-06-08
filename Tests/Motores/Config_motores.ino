void frente(int forcaM1, int forcaM2) {             //seguir em frente
  motorLeft.move(-100);
  motorRight.move(100);
}

void frear() {                                      //parar robo
  motorLeft.move(0);
  motorRight.move(0);
}

void reverso(int forcaM1, int forcaM2) {            //andar de ré
  motorLeft.move(100);
  motorRight.move(-100);
}

void virar_direita(int forcaM1, int forcaM2) {      //virar a direita no seu eixo
  motorLeft.move(0);
  motorRight.move(100);
}

void virar_esquerda(int forcaM1, int forcaM2) {     //virar a esquerda no seu eixo
  motorLeft.move(-100);
  motorRight.move(0);
}
