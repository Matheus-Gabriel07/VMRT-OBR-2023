/* função para desvio do obstáculo */
// Renomear algumas variáveis;


void desvia() {

  int dist = 0;
  int i = 0;
  
      frear();
      //virar_direita(F1, F2);
      //delay(curva_direita);
      noventaesquerda(); //1
      frear();
      delay(100);
      float dist_lat = distancia_lateral();
      while (dist_lat > distancia_parada + 10){
      dist_lat = distancia_lateral();
      frente(F1, F2);
      delay (2400);
      }

      while (dist_lat < distancia_parada + 10){
      frente(F1, F2);
      delay (2400);
      dist_lat = distancia_lateral();
      }
     
      //virar_esquerda(F1, F2);
      //delay(curva_esquerda);
      noventadireita(); //2
      frear();
      while (dist_lat > distancia_parada + 10){
      frente(F1, F2);
      delay (2400);
      dist_lat = distancia_lateral();
      }

      while (dist_lat < distancia_parada + 10){
      frente(F1, F2);
      delay (1800);
      dist_lat = distancia_lateral();
      }
      //virar_esquerda(F1, F2);
      //delay(curva_esquerda);
      noventadireita(); //3
      frear();
      frente(F1, F2);                     //ultrapassa a linha
      delay(500);
  
              int ler = leitura_sensor();
                  while(ler == 0){        //retorno para continuar a seguir linha
                  frente(F1, F2);
                  ler = leitura_sensor();
                  }
  
      frente(F1, F2);                     //ultrapassa a linha
      delay(l_linha);
      frear();
      //virar_direita(F1, F2);              //curva a direita para voltar a seguir linha
      //delay(curva_direita);
      noventaesquerda();
      frear();
      reverso(F1*0.70 , F2*0.70);
      delay(1000);
}
