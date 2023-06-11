/* função para leitura dos sensores de refletância e aplicação da tabela verdade (binária)  */

int leitura_sensor() {
  qtr.read(sensorValues); // Lê os valores dos sensores de refletância

  // Imprime os valores dos sensores
  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();

  int num_sensor = 4;
  int leitura[4]; // Vetor para armazenar os dados dos sensores

  // Armazena os valores dos sensores no vetor de leitura
  leitura[0] = sensorValues[1];
  leitura[1] = sensorValues[2];
  leitura[2] = sensorValues[5];
  leitura[3] = sensorValues[6];

  Serial.println();

  int ligado = 0;         // Variável que indica se o sensor está sobre a linha (0 = BRANCO / 1 = PRETO)
  int multiplicador = 1;  // Fator para o deslocamento decimal dos sensores de refletância
  int caso = 0;           // Somatório dos multiplicadores (varia de 0 a 1111)

  for (int i = 0; i < num_sensor; i++) {
    if (leitura[i] > preto && leitura[i] < corte) { // Se o valor estiver entre preto e o valor de corte, é considerado 1; caso contrário, 0
      ligado = 1;
    } else {
      if (leitura[i] > corte) { // Se o valor for maior que o corte, é reiniciado o caso para 0 e o loop é interrompido
        caso = 0;
        i = 3;
      } else {
        ligado = 0;
      }
    }

    caso = caso + (ligado * multiplicador); // Soma o valor atual com o anterior multiplicado pela posição do vetor (1, 10, 100 e 1000)
    multiplicador = multiplicador * 10;     // Incrementa o multiplicador em 10
  }

  return caso; // Retorna o valor da soma para ser utilizado na função segue_linha()
}


int leitura_cor() {
  int num_cor = 2;
  unsigned int le_cor[num_cor];  // Vetor para armazenar os dados dos sensores de cor
  unsigned int comparador[num_cor];
  unsigned int cortador[num_cor];
  le_cor[0] = analogRead(cor1);
  le_cor[1] = analogRead(cor2);
  comparador[0] = verde1;
  comparador[1] = verde2;
  cortador[0] = corte_verde1;
  cortador[1] = corte_verde2;

  int ligado = 0;         // Variável que indica se o sensor está sobre a linha
  int multiplicador = 1;  // Fator para o deslocamento decimal dos sensores de cor
  int caso = 0;           // Somatório dos multiplicadores (varia de 0 a 1111)

  for (int i = 0; i < num_cor; i++) {
    if (le_cor[i] < comparador[i] && le_cor[i] > cortador[i]) { // Se o valor estiver entre o cortador e o comparador, é considerado 1; caso contrário, 0
      ligado = 1;
    } else {
      ligado = 0;
    }

    caso = caso + (ligado * multiplicador); // Soma o valor atual com o anterior multiplicado pela posição do vetor (1, 10, 100 e 1000)
    multiplicador = multiplicador * 10;     // Incrementa o multiplicador em 10
  }

  Serial.print("COR");
  Serial.println(caso);

  return caso; // Retorna o valor da soma para ser utilizado na função segue_linha()
}
