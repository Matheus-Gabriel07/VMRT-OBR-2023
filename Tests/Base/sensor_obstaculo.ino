
//função para leitura dos sensores ultrassonicos


int distancia_frente() {

  float cmMsec;
  long microsec = u_frente.timing();
  cmMsec = u_frente.convert(microsec, Ultrasonic::CM);
  return cmMsec;

}

int distancia_lateral() {

  float cmMsec;
  long microsec = u_lat.timing();
  cmMsec = u_lat.convert(microsec, Ultrasonic::CM);
  return cmMsec;

}

int esq_distancia_lateral() {

  float cmMsec;
  long microsec = u_late.timing();
  cmMsec = u_lat.convert(microsec, Ultrasonic::CM);
  return cmMsec;

}
