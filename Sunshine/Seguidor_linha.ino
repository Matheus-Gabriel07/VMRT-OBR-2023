 
/* este segue linha, foi projetado para seguir o branco e é dinâmicamente acionado, sem uso de delays no caso de correções de curso.
  Para o caso de fazer curvas de 90º, usa delay mas tb se apoia em um sensor no centro do robô, portanto, essa lógica foi desenhada
  para um robô que possui 4 sensores em linha.*/


// caso não haja nenhum sensor acionado
void segue_linha(int leitura_verdade) {
  if (leitura_verdade == 0) {
    frente(40);

    if (millis() > 7000){
      perdido();
    }
  }

  // somente sensor da extrema direita acionado
  else if (leitura_verdade == 1) {
      curvaDir(40);
  }

  //segundo sensor à direita acionado
  else if (leitura_verdade == 10) {
      curvaDir(40);  // correcao de curso
  }


  //dois sensores a direita sobre a linha preta
  else if (leitura_verdade == 11) {
    frente(40);                             //vai para frente posicionar o sensor de cor sobre a fita verde
    delay(ajuste);
    frear(0);
    delay(500);
    int caso_cor = leitura_cor();
    int linha = leitura_sensor();

    if (caso_cor == 0) {                   //não é acionado o sensor de cor
      frente(40);                          //avança até o final da linha preta
      delay(l_linha);
      
      while (linha < 99 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
        curvaDir(40);
        linha = leitura_sensor();
      }
    }

    else if (caso_cor == 1) {                   //acionado o sensor de cor da direita
      frente(40);
      noventadireita();              //curva a direita em 80% da curva de 90º.... evitar que ultrapasse a linha

      while (linha < 99) {
        curvaDir(40);                 // procura linha com o 3º sensor de refletância
        linha = leitura_sensor();
      }

      frente(40);
      
    }

    else if (caso_cor==10){
        reverso(0);
        }
  }

  //sensor intermediário à esquerda sobre a linha

  else if (leitura_verdade == 100) {
    curvaEsq(40);  // correção
  }

  //sensores à direita e sensor intermediário a direita acionados

  else if (leitura_verdade == 111) {
   
   //delay(1000);
   
    
    frente(100);                             //vai para frente 100osicionar o sensor de cor sobre a fita verde
    delay(ajuste);
    int caso_cor = leitura_cor();
    int linha = leitura_sensor();

    if (caso_cor == 0) {                        //não é acionado o sensor de cor


      frente (40);                          //avança até o final da linha preta
      delay(l_linha);
      
      while (linha > 101 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
          curvaDir(40);
        linha = leitura_sensor();
      }
    }

    else if (caso_cor == 1) {                   //acionado o sensor de cor da direita
      
      frente(40);
      noventadireita();              //curva a direita em 80% da curva de 90º.... evitar que ultrapasse a linha
        while (linha < 99) {
          curvaDir(40);                 // procura linha com o 3º sensor de refletância
        linha = leitura_sensor();
      }
    }

      else if (caso_cor==10){
        reverso(0);
        }
     
      
    
  }


  //sensor da extrema esquerda acionado

  else if (leitura_verdade == 1000) {
    curvaEsq(40);  // correção
  }

  //leitura inviável pela tabela verdade. Volta e refaz a leitura

  else if (leitura_verdade == 1001) {
      frente(40);
    //delay(1000);
  }
  //leitura inviável pela tabela verdade. Pequena ré

  else if (leitura_verdade == 1010) {
      frente(40);
    //delay(1000);
  }

  //leitura inviável pela tabela verdade. Pequena ré

  else if (leitura_verdade == 1011) {
      frente(40);
    //delay(1000);
  }

  //caso sensores extremo e intermediário da esquerda estejam acionados

  else if (leitura_verdade == 1100) {
    tempo = 0;
    frente(40);                             //vai para frente 100osicionar o sensor de cor sobre a fita verde
    delay(ajuste);
    frear(0);
    delay(500);
    int caso_cor = leitura_cor();
    int linha = leitura_sensor();

    if (caso_cor == 0) {                        //não é acionado o sensor de cor


      frente(40);                          //avança até o final da linha preta
      delay(l_linha);

      while (linha > 12 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
        curvaEsq(40);
        linha = leitura_sensor();
      }
    }

    else if (caso_cor == 10) {                   //acionado o sensor de cor da ESQUERDA
      frente(40);
      noventaesquerda();              //curva a direita em 80% da curva de 90º.... evitar que ultrapasse a linha

      while (linha > 12 || linha == 0) {
        curvaEsq(40);                 // procura linha com o 3º sensor de refletância
        linha = leitura_sensor();
      }
      frente(40);
      
    }
  }


  //leitura inviável pela tabela verdade. Volta e refaz a leitura

  else if (leitura_verdade == 1101) {
      frente(40);
  }

  //caso exceto o sensor da estrema direita não esteja acionado

  else if (leitura_verdade == 1110) {
  
  //delay(1000);
    
    frente(40);                             //vai para frente 100osicionar o sensor de cor sobre a fita verde
    delay(ajuste);
    int caso_cor = leitura_cor();
    int linha = leitura_sensor();

    if (caso_cor == 0) {                        //não é acionado o sensor de cor


      frente(40);                          //avança até o final da linha preta
      delay(l_linha);
      
      while (linha > 12 || linha == 0) {                      //curva até achar linha no sensor intermediário à esquerda
        curvaEsq(40);
        linha = leitura_sensor();
      }
    }
    else if (caso_cor == 1) {
      reverso(0);
    }
    else if (caso_cor == 10) {                   //acionado o sensor de cor da esquerda
      frente(40);
      noventaesquerda();//curva a direita em 80% da curva de 90º.... evitar que ultrapasse a linha

      while (linha >12 || linha == 0) {
        curvaEsq(40);                 // procura linha com o 2º sensor de refletância
        linha = leitura_sensor();
      }
    }
  }

  //caso todos os sensores estejam acionados

  else if (leitura_verdade == 1111) {
    frente(40); //vai para frente 100osicionar o sensor de cor sobre a fita verde
    delay(ajuste);
    frear(0);
    delay(500);
    int caso_cor = leitura_cor();
    int linha = leitura_sensor();

    if (caso_cor == 0) {                        //não é acionado o sensor de cor

      frente(40);

    }

    else if (caso_cor == 1) {                   //acionado o sensor de cor da direita
      frente(40);
      noventadireita();              //curva a direita em 70% da curva de 90º.... evitar que ultrapasse a linha
      frente(40);
      while (linha < 99) {
          curvaDir(40);                 // procura linha com o 3º sensor de refletância
        linha = leitura_sensor();
      }
    }

    else if (caso_cor == 10) {                   //acionado o sensor de cor da esquerda

      frente(40);
      noventaesquerda();

      while (linha > 11 || linha == 0) {
        curvaEsq(40);                 // procura linha com o 2º sensor de refletância
        linha = leitura_sensor();
      }
      frente(40);
    }

    else if (caso_cor == 11) {
      frear(0);
      delay(250);
      reverso(0);
      delay(l_linha);
      frear(0);
      delay(250);
      noventaesquerda();
            

      while (linha > 12 || linha == 0) {
        curvaEsq(40);                 // procura linha com o 2º sensor de refletância
        linha = leitura_sensor();
      }
      while (linha > 99 || linha == 0) {
          curvaDir(40);                 // procura linha com o 2º sensor de refletância
        linha = leitura_sensor();
      }
    }
  }
}


void segue_rampa(int leitura_verdade) {
  if (leitura_verdade == 0) {
    frente(40);
  }

  // somente sensor da extrema direita acionado

  else if (leitura_verdade == 1) {
    curvaDir(40);
  }
  //segundo sensor à direita acionado

  else if (leitura_verdade == 10) {
    curvaDir(40);  // correcao de curso
  }


  //dois sensores a direita sobre a linha preta

  else if (leitura_verdade == 11) {
    curvaDir(40);                             //vai para frente 100osicionar o sensor de cor sobre a fita verde
  }

  //sensor intermediário à esquerda sobre a linha

  else if (leitura_verdade == 100) {
    curvaEsq(40); // correção
  }

  //sensores à direita e sensor intermediário a direita acionados

  else if (leitura_verdade == 111) {
    curvaDir(40); // correção
  }


  //sensor da extrema esquerda acionado

  else if (leitura_verdade == 1000) {
    curvaEsq(40); // correção
  }

  //leitura inviável pela tabela verdade. Volta e refaz a leitura

  else if (leitura_verdade == 1001) {
    frente(40);
  }

  //leitura inviável pela tabela verdade. Pequena ré

  else if (leitura_verdade == 1010) {
    frente(40);
  }

  //leitura inviável pela tabela verdade. Pequena ré

  else if (leitura_verdade == 1011) {
    frente(40);
  }

  //caso sensores extremo e intermediário da esquerda estejam acionados

  else if (leitura_verdade == 1100) {
    curvaEsq(40);
  }


  //leitura inviável pela tabela verdade. Volta e refaz a leitura

  else if (leitura_verdade == 1101) {
    frente(40);
  }

  //caso exceto o sensor da estrema direita não esteja acionado

  else if (leitura_verdade == 1110) {
    frente(40);                             //vai para frente 100osicionar o sensor de cor sobre a fita verde  
  }

  //caso todos os sensores estejam acionados

  else if (leitura_verdade == 1111) {
    frente(40);                             //vai para frente 100osicionar o sensor de cor sobre a fita verde

  }
}