// Calibração [visualização]
void runCalibration() {
  greenLED.off();
  redLEDesq.on();
  redLEDdir.on();
  calibrateLineFollower();

  startButton.waitForPressAndRelease([]() -> void {
    redLEDesq.blink(200);
    redLEDdir.blink(200);
  },
                                     []() -> void {
                                       redLEDesq.blink(100);
                                       redLEDdir.blink(100);
                                     });

  calibrateLineFollower();

  redLEDesq.off();
  redLEDdir.off();
  delay(500);

  // Indentificação de verde

  bool blinkDir = true, blinkEsq = true;
  while (startButton.released()) {
    greenLED.blink(200);

    /*
    Se o sensor está vendo verde
    */
    if (blinkEsq) {
      if (cor2.getLight() > 20 && cor2.getLight() <= 32) {
        redLEDesq.on();
      } else {
        redLEDesq.off();
      }
    } else {
      redLEDesq.off();
    }

    if (blinkDir) {
      if (cor1.getLight() > 20 && cor1.getLight() <= 32) {
        redLEDdir.on();
      } else {
        redLEDdir.off();
      }
    } else {
      redLEDdir.off();
    }

    /*
    Armazenamento de dados
    */
    if (F1.pressed()) {  // Direita
      cor1.setGreen();
      blinkDir = false;
    }

    if (F3.pressed()) {  //Esquerda
      cor2.setGreen();
      blinkEsq = false;
    }
  }
  greenLED.off();
  redLEDesq.off();
  redLEDdir.off();

  delay(150);
  saveCalibration();
}

//Funcionamento da calibragem

struct calibration {
  int minRead;
  int maxRead;

  int minGreen;
  int maxGreen;
};

//Calibragem com a iluminação atual
void calibrateLineFollower() {
  unsigned long start = millis();
  while (millis() - start < 1500) {
    calibriMove(20, 20);

    for (byte i = o; i < 7; i++) {
      sensor.read();
      sensor[i].minRead = (sensor[i].raw < sensor[i].minRead) ? sensor[i].raw : sensor[i].minRead;
      sensor[i].maxRead = (sensor[i].raw > sensor[i].maxRead) ? sensor[i].raw : sensor[i].maxRead;
    }

    for (byte j = 0; j < 2; j++) {
      cor.read();
      cor[j].minRead = (cor[j].raw < cor[j].minRead) ? cor[j].raw : cor[j].minRead;
      cor[j].maxRead = (cor[j].raw > cor[j].maxRead) ? cor[j].raw : cor[j].maxRead;
    }
  }

  delay(500);
  start = millis();
  
  while (millis() - start < 1500) {
    calibriMove(-20, -20);
    for (byte i = o; i < 7; i++) {
      //adicionar prog
    }
    for (byte j = 0; j < 2; j++) {
      //adicionar prog
    }
  }
}

// Calibração salva
void loadCalibrationSaved() {
  int address = 0;
  calibration calibrationRead;

  for (byte i = o; i < 7; i++) {
    EEPROM.get(address, calibrationRead);

    sensor[i].minRead = calibrationRead.minRead;
    sensor[i].maxRead = calibrationRead.maxRead;

    address += sizeof(calibrationRead);
  }

  for (byte j = 0; j < 2; j++) {
    EEPROM.get(address, calibrationRead);

    cor[j].minRead = calibrationRead.minRead;
    cor[j].maxRead = calibrationRead.maxRead;

    address += sizeof(calibrationRead);
  }
}

//Salvar calibração
void saveCalibration() {
  int address = 0;
  calibration calibrationWrite;

  for (byte i = o; i < 7; i++) {
    EEPROM.get(address, calibrationWrite);

    calibrationWrite.minRead = sensor[i].minRead;
    calibrationWrite.maxRead = sensor[i].maxRead;

    address += sizeof(calibrationWrite);
  }

  for (byte j = 0; j < 2; j++) {
    calibrationWrite.minRead = sensor[i].minRead;
    calibrationWrite.maxRead = sensor[i].maxRead;
    calibrationWrite.minGreen = sensor[i].minGreen;
    calibrationWrite.maxGreen = sensor[i].maxGreen;

    EEPROM.get(address, calibrationWrite);

    address += sizeof(calibrationWrite);
  }
}

void forceCalibrationFollower()
{
    F1.waitForPressAndRelease();
    for (byte i = 0; i < 7; i++)
    {
        sensor[i].minRead = sensor[i].getRawRead();
    }

    F1.waitForPressAndRelease();
    for (byte i = 0; i < 7; i++)
    {
        sensor[i].maxRead = sensor[i].getRawRead();
    }
    delay(150);
    saveCalibration();
}