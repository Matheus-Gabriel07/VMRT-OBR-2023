  void noventadireita()
   {
    
    encoderM1.write(0);
    // Faz com que o motor se mova até que a contagem do encoder chegue ao número determinado
    while (abs(encoderM1.read())<= curvanoventa) {
    virar_direita(F1, F2);
    Serial.println(encoderM1.read());
    }
    frear();
   }


   void noventaesquerda()
   {
    
    encoderM1.write(0);
    // Faz com que o motor se mova até que a contagem do encoder chegue ao número determinado
    while (abs(encoderM1.read())<= curvanoventaesqu) {
    virar_esquerda(F1, F2);
    Serial.println(encoderM1.read());
    }
    frear();
   }

   void quarentaecincoesquerda()
   {
    
    encoderM1.write(0);
    // Faz com que o motor se mova até que a contagem do encoder chegue ao número determinado
    while (abs(encoderM1.read())<= curvanoventaesqu / 1.8) {
    virar_esquerda(F1, F2);
    Serial.println(encoderM1.read());
    }
    frear();
   }

   void quarentaecincodireita()
   {
    
    encoderM1.write(0);
    // Faz com que o motor se mova até que a contagem do encoder chegue ao número determinado
    while (abs(encoderM1.read())<= curvanoventa / 2) {
    virar_esquerda(F1, F2);
    Serial.println(encoderM1.read());
    }
    frear();
   }
