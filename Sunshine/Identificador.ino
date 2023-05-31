/* 
    Função para leitura dos sensores de refletância, 
    utilizando tabela da verdade (binário)
*/

int leituraSensor(){

    int numSen = 8;
    unsigned int leitura[8];

    leitura[0] = analogRead(sen1);
    leitura[1] = analogRead(sen2);
    leitura[2] = analogRead(sen3);
    leitura[3] = analogRead(sen4);
    leitura[4] = analogRead(sen5);
    leitura[5] = analogRead(sen6);
    leitura[6] = analogRead(sen7);
    leitura[7] = analogRead(sen8);

    Serial.println();

    int ligado = 0;        //inicia variável ligado, que aponta se o sensor está ou não sobre a linha sendo O = BRANCO / 1 = PRETO
    int multiplicador = 1; //multiplicador é o fator que faz o deslocamento decimal da direita para a esquerda dos sensores de refletância
    int caso = 0;          //caso é somatório dos multiplicadores. pode variar de 0 à 1111

    for (int i = 0; i < numSen; i++) {
        if (leitura[i] > preto && leitura[i] < pretoCorte) {
            ligado = 1;
        } else {
            if (leitura[i] > pretoCorte) {
                caso = 0;
                i = 7;
            } else {
                ligado = 0;
            }
        }

        caso = caso + (ligado * multiplicador); //soma dado atual com anterior multiplicado pela posição unitária do vetor (1, 10, 100 e 1000)
        multiplicador = multiplicador * 10;     //incrementa o vetor em 10
    }
    return caso; //retorna valor da soma que será enviado para o segue linha
}

int leitura_cor() {

  int numCor = 2;
  unsigned int le_cor[numCor];
  unsigned int comparador[numCor];
  unsigned int contador[numCor];

  le_cor[0] = analogRead(ldr1);
  le_cor[1] = analogRead(ldr2);
  comparador[0] = verdeEsq;
  comparador[1] = verdeDir;
  contador[0] = corteVerde1;
  contador[2] = corteVerde2;

  Serial.println();

  int ligado = 0;        //inicia variável ligado, que aponta se o sensor está ou não sobre a linha sendo O = BRANCO / 1 = PRETO
  int multiplicador = 1; //multiplicador é o fator que faz o deslocamento decimal da direita para a esquerda dos sensores de refletância
  int caso = 0;          //caso é somatório dos multiplicadores. pode variar de 0 à 1111

  for (int i = 0; i < numCor; i++) {
    if (le_cor[i] < comparador[i] && le_cor[i] > contador[i]) {
      ligado = 1;
    } else {
      ligado = 0
    }

    caso = caso + (ligado*multiplicador);
    multiplicador = multiplicador*10;
  }
  Serial.print("Cor");
  Serial.println(caso);
  return caso;
}
