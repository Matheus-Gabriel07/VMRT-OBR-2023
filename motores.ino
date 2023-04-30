void frente(int forcaM1, int forcaM2) {             //seguir em frente
  analogWrite(M1, forcaM1);                           
  analogWrite(M2, forcaM2);
  digitalWrite(PWM1, HIGH);                          //SENTIDO DE ROTACAO EM FRENTE -> LOW
  digitalWrite(PWM2, HIGH);
}

void frear() {                                      //parar robo
  analogWrite(M1, LOW);
  analogWrite(M2, LOW);
}

void reverso(int forcaM1, int forcaM2) {            //andar de ré
  analogWrite(M1, forcaM1);
  analogWrite(M2, forcaM2);
  digitalWrite(PWM1, LOW);                         //SENTIDO DE ROTACAO REVERSO -> HIGH
  digitalWrite(PWM2, LOW);
  }

void virar_direita(int forcaM1, int forcaM2) {      //virar a direita no seu eixo
  analogWrite(M1, forcaM1);
  analogWrite(M2, forcaM2);
  digitalWrite(PWM1, LOW);                         //SENTIDO DE ROTACAO
  digitalWrite(PWM2, HIGH);
}

void virar_esquerda(int forcaM1, int forcaM2) {     //virar a esquerda no seu eixo
  analogWrite(M1, forcaM1);
  analogWrite(M2, forcaM2);
  digitalWrite(PWM1, HIGH);                          //SENTIDO DE ROTACAO
  digitalWrite(PWM2, LOW);
}

void levanta_garra(){
  analogWrite(G2, FG);
  analogWrite(G1, 0);
  }

void abaixa_garra(int fgarra){
  analogWrite(G2, 0);
  analogWrite(G1, fgarra);
  }

void para_garra(){
  analogWrite(G1, 0);
  analogWrite(G2, 0);
  }

void levanta_comporta(){
  analogWrite(C1,FC);
  analogWrite(C2,0);
  }

void abaixa_comporta(){
  analogWrite(C1,0);
  analogWrite(C2,FC);
  }
