/*

void resgate(){
  int distF = distancia_frente();
  boolean procura = false;
  int canto = 0;
  
  while (procura == false){
  
  
  while(distF > 35 || distF==0){
    
    distF = distancia_frente();
    while(distF==0){
    frente(F1,F2*0.7);
    distF = distancia_frente();
    Serial.println(distF);
    }
    frente(F1,F2);
    delay(100);
    Serial.println(distF);
    }
    frear(F1, F2);
    delay(200);
    quarentaecincoesquerda();
    frente (F1,F2);
    delay(1500);
    
    frear(F1, F2);
    delay(500);
    int dist = distancia_lateral();
    while(dist==0){
    dist = distancia_lateral();
    Serial.println(dist);
    Serial.print("lateral");
    delay(1000);
    }
    if (dist < 10){
      canto = 0;
      procura = true;
      Serial.println("achou");
      delay(2000);
      }
    frente(F1,F2);
    delay(1000);
    frear(F1, F2);
    delay(100);
    quarentaecincoesquerda();
    frear(F1, F2);
    para_garra();
    abaixa_garra(100);
    delay(1000);
    distF = 0;
    }


    
boolean sempre = true;
    int re, subtracao = 0;
    
    while( sempre == true){
    
     // distF = distancia_frente();  
      contador = 0;
      
      frear(F1, F2);
            
    if (re > 4000){
      re = 200;
      }
      contador = 0;
      while(contador < 3){  
      
            
      para_garra();
      abaixa_garra(50);
      delay(20);
      para_garra();
      delay(200);
      abaixa_garra(150);
      delay(200);
        frente(F1*0.9,F2*0.7);
        delay(7000);  
        reverso(F1,F2);
        delay(500);
        frear(F1, F2);
        delay(500);
        para_garra();
        levanta_garra();
        delay(200);
            
        if (contador == 2){
        delay(200);
        } 
        else{
          delay(re);
          re = re+1000;
          }
        contador = contador+1;
        noventaesquerda();
        Serial.println(contador);
      }
      
     //noventaesquerda();
        
        frear(F1, F2);
        delay(200);
        frente(F1,F2);
        delay(2500);
        quarentaecincoesquerda();
        noventaesquerda();
        reverso(F1,F2);
        delay(1500);
        frear(F1, F2);
        delay(200);
        abaixa_garra(50);
        delay(500);
        levanta_comporta();
        delay(1000);
        abaixa_comporta();
        delay(1000);
        frente(F1,F2);
        delay(2000);
        noventadireita();
        contador = 0;
    }
  }
   */
