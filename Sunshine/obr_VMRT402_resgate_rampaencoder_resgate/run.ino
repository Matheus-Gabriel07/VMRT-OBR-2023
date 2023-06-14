void run() {
  setupMotor(1);
  while (rampa == false) {
    Serial.print("Meio: ");
    Serial.print(analogRead(sensorMeio));
    Serial.println("________________________ ");

    int leitura_verdade = leitura_sensor();  // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
    Serial.println(leitura_verdade);         // imprime as leituras em serial
    segue_linha(leitura_verdade);            // sobe condição da leitura atual no segue linha

    tempo_atual = millis();

    tempo = tempo_atual - ultima_medida;
  }
}

void aguardo() {
  redLEDesq.on();
  greenLEDcenter.on();
  redLEDdir.on();
  delay(150);
  redLEDesq.off();
  greenLEDcenter.off();
  redLEDdir.off();
  delay(150);
}

void debugLoop() {
  mpu6050.update();
  gyro = mpu6050.getGyroAngleZ();
  alvo = 360;

  while(abs(gyro) < 274) {
    mpu6050.update();
    gyro = mpu6050.getGyroAngleZ();
    alvo = 360;
    curvaDir(40);
    Serial.println(gyro);
  }
  frear(0);
}