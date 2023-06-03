/*
    Função da leitura dos sensores ultrassonicos, com visualização em LED;


int distanciaFrente() {
  
  float cmMsec;
  long microsec = sensorFrente.timing();
  cmMsec = u_frente.convert(microsec, Ultrasonic::CM);
  return cmMsec;
  
  distace = sensorFrente.measureDistanceCm();

  if (distace <= alvo && distace > 5) {
    Serial.println(distace);
    digitalWrite(LED_green, HIGH);
    delay (100);
  } else {
    digitalWrite(LED_redDir, LOW);
    digitalWrite(LED_redEsq, LOW);
    delay(100);
  }

  else if (distace < 5) {
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_redDir, HIGH);
    digitalWrite(LED_redEsq, HIGH);
    delay(150);
    digitalWrite(LED_redDir, LOW);
    digitalWrite(LED_redEsq, LOW);
    delay(150);
  }

}

int distancia_lateral() {

  float cmMsec;
  long microsec = u_lat.timing();
  cmMsec = sensorEsq.convert(microsec, Ultrasonic::CM);
  return cmMsec;

}

int esq_distancia_lateral() {

  float cmMsec;
  long microsec = u_late.timing();
  cmMsec = sensorDir.convert(microsec, Ultrasonic::CM);
  return cmMsec;

}*/
