void loop() {
  /*
  while (rampa == false) {



    int leitura_verdade = leitura_sensor();          // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
    Serial.println(leitura_verdade);                 // imprime as leituras em serial
    segue_linha(leitura_verdade);                    // sobe condição da leitura atual no segue linha



    tempo_atual = millis();


    tempo = tempo_atual - ultima_medida;
  }
    //Serial.println(tempo);
   /*
    if (tempo > 50) {
      ultima_medida = tempo_atual;
      tempo = 0;
      obst = distancia_frente();
      dist_dir = distancia_lateral();
      dist_esq = esq_distancia_lateral();
      Serial.println("entrei");
        if (obst < distancia_parada && obst!=0 ) {
          Serial.println("DESVIA");
          desvia();
        }



        if (dist_dir < 10 || dist_esq < 10 && dist_dir != 0 && dist_esq != 0){
          contador = contador + 1;
          Serial.println(contador);
          Serial.println(dist_dir);
          Serial.println(dist_esq);
          }
          else{
            contador = 0;
            }

            if (contador > 10){
              rampa = true;
              }


    }

    Serial.println(leitura_verdade);
    Serial.println(obst);
  }

  while (rampa == true){

    int leitura_verdade = leitura_sensor();          // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
    Serial.println(contador);
    Serial.println("rampa");                 // imprime as leituras em serial
    segue_rampa(leitura_verdade);                    // sobe condição da leitura atual no segue linha
    tempo_atual = millis();
    tempo = tempo_atual - ultima_medida;
    if (tempo > 100) {
      ultima_medida = tempo_atual;
      tempo = 0;
      dist_dir = distancia_lateral();
      dist_esq = esq_distancia_lateral();
      Serial.println(dist_esq);
        if (dist_esq > 10 ){
          contador = contador + 1;

          }
          else{
            contador = 0;
            }

         if (contador > 10){
           rampa = false;
              }
    }
  }

  while (rampa == false){

  delay(10000);
  resgate();
  }
*/
}