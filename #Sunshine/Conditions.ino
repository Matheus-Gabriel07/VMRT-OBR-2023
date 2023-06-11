/*
  Condições de funcionamento do robô. Ou seja, casos que o robô possa entrar mas que não necessite de 'Situations' 
  e que ele mesmo se resolva, usando lógica de casos e vetores.
*/

void start(){
  startButton.waitForPress([]() -> void {
    loop();
  });

  //colocar casos de interveções
}

void debugLoop() {
  mpu6050.update();
  gyro = mpu6050.getGyroAngleZ();
  alvo = 360;

  while (abs(gyro) < 274) {
    mpu6050.update();
    gyro = mpu6050.getGyroAngleZ();
    alvo = 360;
    curvaDir(40);
    Serial.println(gyro);
  }
  frear(0);
}

void rampa() {
  int leitura_verdade = leitura_sensor();  // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
  Serial.println(leitura_verdade);         // imprime as leituras em serial
  segue_linha(leitura_verdade);            // sobe condição da leitura atual no segue linha

  frente(40);

  void resgateInd() {
    int max = 10;
    int conditions = 0; 
    bool continuar = true;

    while (distancia_lateral <= max || esq_distancia_lateral <= max) {
      int leitura_verdade = leitura_sensor();  // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
      Serial.println(leitura_verdade);         // imprime as leituras em serial
      segue_linha(leitura_verdade);            // sobe condição da leitura atual no segue linha
      tempo_atual = millis();
      tempo = tempo_atual - ultima_medida;

      frente(35);
      garra();

      if (leitura_verdade = resgate) {
        condtions = 1;
        continuar = false;
      }
    }
  }

  switch (conditions) {
    case 0:
      return resgateInd();

    case 1:
      resgate();
      break;

    default:
      return resgateInd();
  }
}

void sucesso() {
  //caso termine e resgate as vitimas
}

void surprise() {
  //desafio surpresa
}