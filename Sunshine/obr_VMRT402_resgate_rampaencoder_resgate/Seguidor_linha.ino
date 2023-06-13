 
/* este segue linha, foi projetado para seguir o branco e é dinâmicamente acionado, sem uso de delays no caso de correções de curso.
  Para o caso de fazer curvas de 90º, usa delay mas tb se apoia em um sensor no centro do robô, portanto, essa lógica foi desenhada
  para um robô que possui 4 sensores em linha.*/


// caso não haja nenhum sensor acionado

void segue_linha(int leitura_verdade) {
  if (leitura_verdade == 0 || leitura_verdade == 110) {
      frente(vel_motor);
  }

  // somente sensor da extrema direita acionado

  else if (leitura_verdade == 1) {
      curvaDir(vel_curva);
  }
  //segundo sensor à direita acionado

  else if (leitura_verdade == 10) {
      curvaDir(vel_curva);  // correcao de curso
  }


  //dois sensores a direita sobre a linha preta

  else if (leitura_verdade == 11) {
    frear(0);
    delay(ajuste);
    int le_cor = leitura_cor();
    int linha = leitura_sensor();
    Serial.println(le_cor);

    if(le_cor >= 10 && le_cor < 12 ){
      frente (vel_motor);                          //avança até o final da linha preta
      long unsigned millis(l_linha);  

      while (linha > 101 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
        curvaDir(vel_motor);
        linha = leitura_sensor();
      } 
      //Serial.println("Conseguui");
    }

    if(le_cor == 0) {
      frente (vel_motor);                          //avança até o final da linha preta
      long unsigned millis(l_linha);  
      
      while (linha > 101 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
        curvaDir(vel_motor);
        linha = leitura_sensor();
      }
    }
    frente(vel_curva);
  }

  //sensor intermediário à esquerda sobre a linha

  else if (leitura_verdade == 100) {
    curvaEsq(vel_motor);  // correção
  }

  //sensores à direita e sensor intermediário a direita acionados

  else if (leitura_verdade == 111) {
   
   //delay(1000);
   
    
    frente(vel_motor);                             //vai para frente 100osicionar o sensor de cor sobre a fita verde
    delay(ajuste);
    int caso_cor = leitura_cor();
    int linha = leitura_sensor();

    if (caso_cor == 0) {                        //não é acionado o sensor de cor


      frente (vel_motor);                          //avança até o final da linha preta
      delay(l_linha);
      
      while (linha > 101 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
          curvaDir(vel_motor);
        linha = leitura_sensor();
      }
    }

    else if (caso_cor == 1) {                   //acionado o sensor de cor da direita
      
      frente(vel_motor);
      noventadireita();              //curva a direita em 80% da curva de 90º.... evitar que ultrapasse a linha
        while (linha < 99) {
          curvaDir(vel_motor);                 // procura linha com o 3º sensor de refletância
        linha = leitura_sensor();
      }
    }

      else if (caso_cor==10){
        reverso(0);
        }
     
      
    
  }


  //sensor da extrema esquerda acionado

  else if (leitura_verdade == 1000) {
    curvaEsq(vel_curva);  // correção
  }

  //leitura inviável pela tabela verdade. Volta e refaz a leitura

  else if (leitura_verdade == 1001) {
      frente(vel_motor);
    //delay(1000);
  }
  //leitura inviável pela tabela verdade. Pequena ré

  else if (leitura_verdade == 1010) {
      frente(vel_motor);
    //delay(1000);
  }

  //leitura inviável pela tabela verdade. Pequena ré

  else if (leitura_verdade == 1011) {
      frente(vel_motor);
    //delay(1000);
  }

  //caso sensores extremo e intermediário da esquerda estejam acionados

  else if (leitura_verdade == 1100) {
    frear(0);
    delay(ajuste);
    
    int le_cor = leitura_cor();
    int linha = leitura_sensor();
    Serial.println(le_cor);

    if(le_cor >= 10 && le_cor < 12 ){
      frente (vel_motor);                          //avança até o final da linha preta
      delay(l_linha);
      
      while (linha > 101 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
        curvaEsq(vel_motor);
        linha = leitura_sensor();
      } 
      //Serial.println("Conseguui");
    }

    if(le_cor == 0) {
      frente (vel_motor);                          //avança até o final da linha preta
      delay(l_linha);
      
      while (linha > 101 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
        curvaEsq(vel_motor);
        linha = leitura_sensor();
      }
    }
    frente(vel_curva);
  }


  //leitura inviável pela tabela verdade. Volta e refaz a leitura

  else if (leitura_verdade == 1101) {
      frente(vel_motor);
  }

  //caso exceto o sensor da estrema direita não esteja acionado

  else if (leitura_verdade == 1110) {
    frente(vel_motor);
  }

  //caso todos os sensores estejam acionados

  else if (leitura_verdade == 1111) {
    frente(vel_motor);
  }
}


void segue_rampa(int leitura_verdade) {
  if (leitura_verdade == 0) {
    frente(vel_motor);
  }

  // somente sensor da extrema direita acionado

  else if (leitura_verdade == 1) {
    curvaDir(vel_motor);
  }
  //segundo sensor à direita acionado

  else if (leitura_verdade == 10) {
    curvaDir(vel_motor);  // correcao de curso
  }


  //dois sensores a direita sobre a linha preta

  else if (leitura_verdade == 11) {
    curvaDir(vel_motor);                             //vai para frente 100osicionar o sensor de cor sobre a fita verde
  }

  //sensor intermediário à esquerda sobre a linha

  else if (leitura_verdade == 100) {
    curvaEsq(vel_motor); // correção
  }

  //sensores à direita e sensor intermediário a direita acionados

  else if (leitura_verdade == 111) {
    curvaDir(vel_motor); // correção
  }


  //sensor da extrema esquerda acionado

  else if (leitura_verdade == 1000) {
    curvaEsq(vel_motor); // correção
  }

  //leitura inviável pela tabela verdade. Volta e refaz a leitura

  else if (leitura_verdade == 1001) {
    frente(vel_motor);
  }

  //leitura inviável pela tabela verdade. Pequena ré

  else if (leitura_verdade == 1010) {
    frente(vel_motor);
  }

  //leitura inviável pela tabela verdade. Pequena ré

  else if (leitura_verdade == 1011) {
    frente(vel_motor);
  }

  //caso sensores extremo e intermediário da esquerda estejam acionados

  else if (leitura_verdade == 1100) {
    curvaEsq(vel_motor);
  }


  //leitura inviável pela tabela verdade. Volta e refaz a leitura

  else if (leitura_verdade == 1101) {
    frente(vel_motor);
  }

  //caso exceto o sensor da estrema direita não esteja acionado

  else if (leitura_verdade == 1110) {
    frente(vel_motor);                             //vai para frente 100osicionar o sensor de cor sobre a fita verde  
  }

  //caso todos os sensores estejam acionados

  else if (leitura_verdade == 1111) {
    frente(vel_motor);                             //vai para frente 100osicionar o sensor de cor sobre a fita verde

  }
}
