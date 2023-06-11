/*
  Situações que o robô pode passar que necesseite da intervenção humana, ou de casos especificos que 
  possa vir a ocorrer e de funções epecificas que necessita fazer.
*/

void erro() {
  //O robô não conseguiu se encontrar
  redLEDesq.blink();
  greenLEDcenter.blink();
  redLEDdir.blink();
}

void perdido() {
  //se o robô se perder da linha e demorar para encontrar a linha novamente
  while (l_linha == 0) {
    curvaEsq(30);
    l_linha = leitura_sensor();
    millis();

    if (millis() > 7000) {
      erro();
    }
  }
}

void prints() {
  //Printar valores especificos
}