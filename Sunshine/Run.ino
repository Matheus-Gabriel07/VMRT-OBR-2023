void run() {
  int i = 0;

  Serial.println("parado");

  /*float d = distancia_frente();
  Serial.println(d);
  if (d < 10 && d > 0) {

    i = 0;
    delay(1500);
  }*/

  while (i == 0) {
    float d = distancia_frente();
    tempo_atual = millis();

    setupMotor(1);
    while (rampa == false) {
      setupMotor(1);
      int tempo_atual = millis();

      Serial.print("Meio: ");
      Serial.print(analogRead(sensorMeio));
      Serial.println("________________________ ");

      if (F2.pressed()){
        setupMotor(0);
        aguardo();
      }

      if (F2.pressed() && F1.pressed()) {
        loop();
      }

      int leitura_verdade = leitura_sensor();  // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
      Serial.println(leitura_verdade);         // imprime as leituras em serial
      arrayCor1[posIn1++] = analogRead(cor1);
      arrayCor2[posIn2++] = analogRead(cor2);
      segue_linha(leitura_verdade);            // sobe condição da leitura atual no segue linha

      int dif = tempo_atual - tempo;

      if (dif > 400) {

        tempo = tempo_atual;
        d = distancia_frente();
        Serial.println(d);
      }

      if (d < 6 && d > 1) {
        frear(0);
        desvia();
      }
    }
  }
}

void aguardo() {
  redLEDesq.on();
  greenLEDcenter.on();
  redLEDdir.on();
  delay(200);
  redLEDesq.off();
  greenLEDcenter.off();
  redLEDdir.off();
  delay(200);
}
