void run() {
  int i = 0;

  while (i == 0) {
    float d = distancia_frente();
    tempo_atual = millis();

    while (rampa == false) {
      setupMotor(1);
      int tempo_atual = millis();

      if (F2.pressed()){
        setupMotor(0);
        aguardo();
      }

      int leitura_verdade = leitura_sensor();  // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
      Serial.println(leitura_verdade);         // imprime as leituras em serial
      segue_linha(leitura_verdade);            // sobe condição da leitura atual no segue linha

      int dif = tempo_atual - tempo;

      if (dif > 400) {
        tempo = tempo_atual;
        d = distancia_frente();
        Serial.println(d);
      }
      if (d < 6 && d > 1) {
        frear(0);
        desviaObstaculo();
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
