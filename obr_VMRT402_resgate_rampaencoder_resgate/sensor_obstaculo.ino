
//função para leitura dos sensores ultrassonicos


float distancia_frente() {

  float cmMsec = u_frente.measureDistanceCm();
  return cmMsec;

}

float distancia_lateral() {

  float cmMsec = u_lat.measureDistanceCm();
  return cmMsec;

}

float esq_distancia_lateral() {

  float cmMsec = u_late.measureDistanceCm();
  
  return cmMsec;

}
