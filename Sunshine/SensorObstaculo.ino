float distancia_frente() {
  float cmMsec = u_frente.measureDistanceCm();
  return cmMsec;
}

float distancia_lateral() {
  float cmMsec = u_Esq.measureDistanceCm();
  return cmMsec;
}

float esq_distancia_lateral() {
  float cmMsec = u_Dir.measureDistanceCm();
  return cmMsec;
}
