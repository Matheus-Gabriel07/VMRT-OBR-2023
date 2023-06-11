/* função para leitura dos sensores de refletância e aplicação da tabela verdade (binária)  */

int leitura_sensor() {

  qtr.read(sensorValues);

  // print the sensor values as numbers from 0 to 2500, where 0 means maximum
  // reflectance and 2500 means minimum reflectance
  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();

  int num_sensor = 4;
  int leitura[4];  //cria vetor para armazenamento dos dados

  leitura[0] = sensorValues[1];
  leitura[1] = sensorValues[2];
  leitura[2] = sensorValues[5];
  leitura[3] = sensorValues[6];

  Serial.println();  //imprime os valores lidos pelos sensores de refletância

  int ligado = 0;         //inicia variável ligado, que aponta se o sensor está ou não sobre a linha sendo O = BRANCO / 1 = PRETO
  int multiplicador = 1;  //multiplicador é o fator que faz o deslocamento decimal da direita para a esquerda dos sensores de refletância
  int caso = 0;           //caso é somatório dos multiplicadores. pode variar de 0 à 1111

  for (int i = 0; i < num_sensor; i++)  // for para o tratamento do vetor. Lendo cada um dos sensores e definindo se está na linha preta
  {
    if (leitura[i] > preto && leitura[i] < corte)  // se entre preto e o valor de corte, 1; caso contrário 0;
    {
      ligado = 1;
    } else {
      if (leitura[i] > corte) {
        caso = 0;
        i = 3;
      } else {
        ligado = 0;
      }
    }

    caso = caso + (ligado * multiplicador);  //soma dado atual com anterior multiplicado pela posição unitária do vetor (1, 10, 100 e 1000)
    multiplicador = multiplicador * 10;      //incrementa o vetor em 10
  }
  return caso;  //retorna valor da soma que será enviado para o segue linha
}



int leitura_cor() {

  int num_cor = 2;
  unsigned int le_cor[num_cor];  //cria vetor para armazenamento dos dados
  unsigned int comparador[num_cor];
  unsigned int cortador[num_cor];
  le_cor[0] = analogRead(cor1);
  le_cor[1] = analogRead(cor2);
  comparador[0] = verde1;
  comparador[1] = verde2;
  cortador[0] = corte_verde1;
  cortador[1] = corte_verde2;


  //Serial.println();     //imprime os valores lidos pelos sensores de refletância

  int ligado = 0;         //inicia variável ligado, que aponta se o sensor está ou não sobre a linha
  int multiplicador = 1;  //multiplicador é o fator que faz o deslocamento decimal da direita para a esquerda dos sensores de refletância
  int caso = 0;           //caso é somatório dos multiplicadores. pode variar de o à 1111

  for (int i = 0; i < num_cor; i++) {                            // for para o tratamento do vetor.
    if (le_cor[i] < comparador[i] && le_cor[i] > cortador[i]) {  // se entre preto e o valor de corte, 1; caso contrário 0;
      ligado = 1;
    } else {
      ligado = 0;
    }

    caso = caso + (ligado * multiplicador);  //soma dado atual com anterior multiplicado pela posição unitária do vetor (1, 10, 100 e 1000)
    multiplicador = multiplicador * 10;      //incrementa o vetor em 10
  }
  Serial.print("COR");
  Serial.println(caso);
  return caso;  //retorna valor da soma que será enviado para o segue linha
}
