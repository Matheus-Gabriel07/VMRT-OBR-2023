void desviaObstaculo() {
  curvaNoventaDireita(vel_motor);
  setupMotor(0);
  setupMotor(1);
  unsigned int pp = graus;

  while ((graus - pp) < 360) {
    frente(vel_motor);
  }
  setupMotor(0);
  setupMotor(1);
  curvaNoventaEsquerda(vel_motor);
  pp = graus;

  while ((graus - pp) < 700) {
    frente(vel_motor);
  }
  curvaNoventaEsquerda(vel_motor);
  pp = graus;

  while ((graus - pp) < 360) {
    frente(vel_motor);
  }

  int bl = leitura_sensor();
  while (bl < 1) {
    curvaDireita(vel_motor);
    bl = leitura_sensor();
  }
}
