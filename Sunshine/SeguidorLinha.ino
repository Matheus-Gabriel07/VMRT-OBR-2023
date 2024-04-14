void segue_linha(int leitura_verdade) {
  switch (leitura_verdade) {
    case 0:
    case 110:
    case 101:
      frente(vel_motor);
      break;

    case 1:
    case 10:
      curvaDireita(vel_curva);
      break;

    case 11: {
      int le_cor = leitura_cor();
      unsigned long posAtual = graus;
      while ((graus - posAtual) < l_linha) {
        frente(10);
      }
      frear(0);

      if (le_cor == 10 || le_cor == 11) {
        curvaNoventaDireita(vel_curva);
      } else if (le_cor == 0 || le_cor == 1) {
        while (leitura_sensor() != 10) {
          curvaDireita(5);
        }
      }
      frear(0);
      break;
    }

    case 100:
      curvaEsquerda(vel_motor);
      break;

    case 111:
      frente(vel_motor);
      break;

    case 1000:
      curvaEsquerda(vel_curva);
      break;

    case 1001:
    case 1010:
    case 1011:
    case 1101:
    case 1110:
    case 1111:
      frente(vel_motor);
      break;

    case 1100: {
      int le_cor = leitura_cor();
      unsigned long posAtual = graus;
      while ((graus - posAtual) < l_linha) {
        frente(20);
      }
      frear(0);

      if (le_cor == 10 || le_cor == 11) {
        curvaNoventaEsquerda(vel_curva);
      } else if (le_cor == 0 || le_cor == 1) {
        while (leitura_sensor() != 10) {
          curvaEsquerda(5);
        }
      }
      frear(0);
      break;
    }
  }
}

void segue_rampa(int leitura_verdade) {
  switch (leitura_verdade) {
    case 0:
      frente(vel_motor);
      break;

    case 1:
    case 10:
    case 11:
      curvaDireita(vel_motor);
      break;

    case 100:
    case 110:
    case 111:
      curvaEsquerda(vel_motor);
      break;

    case 1000:
    case 1001:
    case 1010:
    case 1011:
    case 1100:
    case 1101:
    case 1110:
    case 1111:
      frente(vel_motor);
      break;
  }
}