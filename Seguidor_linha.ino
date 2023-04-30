 
/* este segue linha, foi projetado para seguir o branco e é dinâmicamente acionado, sem uso de delays no caso de correções de curso.
  Para o caso de fazer curvas de 90º, usa delay mas tb se apoia em um sensor no centro do robô, portanto, essa lógica foi desenhada
  para um robô que possui 4 sensores em linha.*/


// caso não haja nenhum sensor acionado

void segue_linha(int leitura_verdade) {
  if (leitura_verdade == 0) {
    frente(F1, F2);
  }

  // somente sensor da extrema direita acionado

  else if (leitura_verdade == 1) {
    virar_direita(F1, F2);
  }
  //segundo sensor à direita acionado

  else if (leitura_verdade == 10) {
    virar_direita(F1, F2);  // correcao de curso
  }


  //dois sensores a direita sobre a linha preta

  else if (leitura_verdade == 11) {

    frente(F1, F2);                             //vai para frente para posicionar o sensor de cor sobre a fita verde
    delay(ajuste);
    frear();
    delay(500);
    int caso_cor = leitura_cor();
    int linha = leitura_sensor();

    if (caso_cor == 0) {                        //não é acionado o sensor de cor


      frente (F1, F2);                          //avança até o final da linha preta
      delay(l_linha);

      while (linha < 99 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
        virar_direita(F1, F2);
        linha = leitura_sensor();
      }
    }

    else if (caso_cor == 1) {                   //acionado o sensor de cor da direita
      frente(F1,F2);
      delay(l_linha);
      noventadireita();              //curva a direita em 80% da curva de 90º.... evitar que ultrapasse a linha

      while (linha < 99) {
        virar_direita(F1, F2);                 // procura linha com o 3º sensor de refletância
        linha = leitura_sensor();
      }

      frente(F1,F2);
      delay(l_linha);
      
    }

    else if (caso_cor==10){
        reverso(F1,F2);
        delay(1000);
        }
  }

  //sensor intermediário à esquerda sobre a linha

  else if (leitura_verdade == 100) {
    virar_esquerda(F1, F2); // correção
  }

  //leitura inviável pela tabela verdade. Segue em frente

  else if (leitura_verdade == 101) {
    frente(F1, F2);
    //delay(1000);
  }

  //leitura inviável pela tabela verdade. Segue em frente

      else if (leitura_verdade == 110) {
  frente(F1, F2);
  //delay(1000);
  }

  //sensores à direita e sensor intermediário a direita acionados

  else if (leitura_verdade == 111) {
   
   //delay(1000);
   
    
    frente(F1, F2);                             //vai para frente para posicionar o sensor de cor sobre a fita verde
    delay(ajuste);
    int caso_cor = leitura_cor();
    int linha = leitura_sensor();

    if (caso_cor == 0) {                        //não é acionado o sensor de cor


      frente (F1, F2);                          //avança até o final da linha preta
      delay(l_linha);

      while (linha > 101 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
        virar_direita(F1, F2);
        linha = leitura_sensor();
      }
    }

    else if (caso_cor == 1) {                   //acionado o sensor de cor da direita
      
      frente(F1,F2);
      delay(l_linha);
      noventadireita();              //curva a direita em 80% da curva de 90º.... evitar que ultrapasse a linha
        while (linha < 99) {
        virar_direita(F1, F2);                 // procura linha com o 3º sensor de refletância
        linha = leitura_sensor();
      }
    }

      else if (caso_cor==10){
        reverso(F1,F2);
        delay(1000);
        }
     
      
    
  }


  //sensor da extrema esquerda acionado

  else if (leitura_verdade == 1000) {
    virar_esquerda(F1, F2); // correção
  }

  //leitura inviável pela tabela verdade. Volta e refaz a leitura

  else if (leitura_verdade == 1001) {
    frente(F1, F2);
    //delay(1000);
  }
  //leitura inviável pela tabela verdade. Pequena ré

  else if (leitura_verdade == 1010) {
    frente(F1, F2);
    //delay(1000);
  }

  //leitura inviável pela tabela verdade. Pequena ré

  else if (leitura_verdade == 1011) {
    frente(F1, F2);
    //delay(1000);
  }

  //caso sensores extremo e intermediário da esquerda estejam acionados

  else if (leitura_verdade == 1100) {
    tempo = 0;
    frente(F1, F2);                             //vai para frente para posicionar o sensor de cor sobre a fita verde
    delay(ajuste);
    frear();
    delay(500);
    int caso_cor = leitura_cor();
    int linha = leitura_sensor();

    if (caso_cor == 0) {                        //não é acionado o sensor de cor


      frente (F1, F2);                          //avança até o final da linha preta
      delay(l_linha);

      while (linha > 12 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
        virar_esquerda(F1, F2);
        linha = leitura_sensor();
      }
    }

    else if (caso_cor == 10) {                   //acionado o sensor de cor da ESQUERDA
      frente(F1, F2);
      delay(l_linha);
      noventaesquerda();              //curva a direita em 80% da curva de 90º.... evitar que ultrapasse a linha

      while (linha > 12 || linha == 0) {
        virar_esquerda(F1, F2);                 // procura linha com o 3º sensor de refletância
        linha = leitura_sensor();
      }
      frente(F1,F2);
      delay(l_linha);
      
    }
  }


  //leitura inviável pela tabela verdade. Volta e refaz a leitura

  else if (leitura_verdade == 1101) {
    frente(F1, F2);
  }

  //caso exceto o sensor da estrema direita não esteja acionado

  else if (leitura_verdade == 1110) {
  
  //delay(1000);
    
    frente(F1, F2);                             //vai para frente para posicionar o sensor de cor sobre a fita verde
    delay(ajuste);
    int caso_cor = leitura_cor();
    int linha = leitura_sensor();

    if (caso_cor == 0) {                        //não é acionado o sensor de cor


      frente (F1, F2);                          //avança até o final da linha preta
      delay(l_linha);

      while (linha > 12 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
        virar_esquerda(F1, F2);
        linha = leitura_sensor();
      }
    }
    else if (caso_cor == 1) {
      reverso(F1,F2);
    }
    else if (caso_cor == 10) {                   //acionado o sensor de cor da esquerda
      frente(F1, F2);
      delay(l_linha);
      noventaesquerda();//curva a direita em 80% da curva de 90º.... evitar que ultrapasse a linha

      while (linha >12 || linha == 0) {
        virar_esquerda(F1, F2);                 // procura linha com o 2º sensor de refletância
        linha = leitura_sensor();
      }
    }
  }

  //caso todos os sensores estejam acionados

  else if (leitura_verdade == 1111) {
    frente(F1, F2);                             //vai para frente para posicionar o sensor de cor sobre a fita verde
    delay(ajuste);
    frear();
    delay(500);
    int caso_cor = leitura_cor();
    int linha = leitura_sensor();

    if (caso_cor == 0) {                        //não é acionado o sensor de cor

      frente(F1, F2);
      delay(2000);

    }

    else if (caso_cor == 1) {                   //acionado o sensor de cor da direita
      frente(F1, F2);
      delay(l_linha);
      noventadireita();              //curva a direita em 70% da curva de 90º.... evitar que ultrapasse a linha
      frente(F1,F2);
      delay (l_linha);
      while (linha < 99) {
        virar_direita(F1, F2);                 // procura linha com o 3º sensor de refletância
        linha = leitura_sensor();
      }
    }

    else if (caso_cor == 10) {                   //acionado o sensor de cor da esquerda

      frente(F1, F2);
      delay(l_linha);
      noventaesquerda();

      while (linha > 11 || linha == 0) {
        virar_esquerda(F1, F2);                 // procura linha com o 2º sensor de refletância
        linha = leitura_sensor();
      }
      frente(F1,F2);
      delay(l_linha);
    }

    else if (caso_cor == 11) {
      frear();
      delay(250);
      reverso(F1,F2);
      delay(l_linha);
      frear();
      delay(250);
      noventaesquerda();
            

      while (linha > 12 || linha == 0) {
        virar_esquerda(F1, F2);                 // procura linha com o 2º sensor de refletância
        linha = leitura_sensor();
      }
      while (linha > 99 || linha == 0) {
        virar_direita(F1, F2);                 // procura linha com o 2º sensor de refletância
        linha = leitura_sensor();
      }
    }
  }
}



void segue_rampa(int leitura_verdade) {
  if (leitura_verdade == 0) {
    frente(225, 225);
  }

  // somente sensor da extrema direita acionado

  else if (leitura_verdade == 1) {
    virar_direita(225, 225);
  }
  //segundo sensor à direita acionado

  else if (leitura_verdade == 10) {
    virar_direita(0, 225);  // correcao de curso
  }


  //dois sensores a direita sobre a linha preta

  else if (leitura_verdade == 11) {
    virar_direita(225, 225);                             //vai para frente para posicionar o sensor de cor sobre a fita verde
  }

  //sensor intermediário à esquerda sobre a linha

  else if (leitura_verdade == 100) {
    virar_esquerda(225, 0); // correção
  }

  //leitura inviável pela tabela verdade. Segue em frente

  else if (leitura_verdade == 101) {
    frente(225, 225);
  }

  //leitura inviável pela tabela verdade. Segue em frente

      else if (leitura_verdade == 110) {
     frente(225, 225);
  }

  //sensores à direita e sensor intermediário a direita acionados

  else if (leitura_verdade == 111) {
    virar_direita(0, 225); // correção
  }


  //sensor da extrema esquerda acionado

  else if (leitura_verdade == 1000) {
    virar_esquerda(225, 225); // correção
  }

  //leitura inviável pela tabela verdade. Volta e refaz a leitura

  else if (leitura_verdade == 1001) {
    frente(225, 225);
  }

  //leitura inviável pela tabela verdade. Pequena ré

  else if (leitura_verdade == 1010) {
    frente(225, 225);
  }

  //leitura inviável pela tabela verdade. Pequena ré

  else if (leitura_verdade == 1011) {
    frente(225, 225);
  }

  //caso sensores extremo e intermediário da esquerda estejam acionados

  else if (leitura_verdade == 1100) {
    virar_esquerda(225,225);
  }


  //leitura inviável pela tabela verdade. Volta e refaz a leitura

  else if (leitura_verdade == 1101) {
    frente(225, 225);
  }

  //caso exceto o sensor da estrema direita não esteja acionado

  else if (leitura_verdade == 1110) {
    frente(225, 225);                             //vai para frente para posicionar o sensor de cor sobre a fita verde  
  }

  //caso todos os sensores estejam acionados

  else if (leitura_verdade == 1111) {
    frente(225, 225);                             //vai para frente para posicionar o sensor de cor sobre a fita verde

  }
}
