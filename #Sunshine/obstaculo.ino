/*função para desvio do obstáculo
 * 
 */


void desvia() {

  int dist = 0;
  int i = 0;
  
      frear(0);
      //virar_direita(0);
      //delay(curva_direita);
      noventaesquerda(); //1
      frear(0);
      delay(100);
      float dist_lat = distancia_lateral();
      while (dist_lat > distancia_parada + 10){
      dist_lat = distancia_lateral();
      frente(0);
      delay (2400);
      }

      while (dist_lat < distancia_parada + 10){
      frente(0);
      delay (2400);
      dist_lat = distancia_lateral();
      }
     
      //virar_esquerda(0);
      //delay(curva_esquerda);
      noventadireita(); //2
      frear(0);
      while (dist_lat > distancia_parada + 10){
      frente(0);
      delay (2400);
      dist_lat = distancia_lateral();
      }

      while (dist_lat < distancia_parada + 10){
      frente(0);
      delay (1800);
      dist_lat = distancia_lateral();
      }
      //virar_esquerda(0);
      //delay(curva_esquerda);
      noventadireita(); //3
      frear(0);
      frente(0);                     //ultrapassa a linha
      delay(500);
  
              int ler = leitura_sensor();
                  while(ler == 0){        //retorno para continuar a seguir linha
                  frente(0);
                  ler = leitura_sensor();
                  }
  
      frente(0);                     //ultrapassa a linha
      delay(l_linha);
      frear(0);
      //virar_direita(0);              //curva a direita para voltar a seguir linha
      //delay(curva_direita);
      noventaesquerda();
      frear(0);
      delay(1000);
      reverso(100*0.70);
}
