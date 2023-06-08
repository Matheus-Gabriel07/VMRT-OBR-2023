  void noventadireita()
   {
    
    encoderM1.write(0);
    // Faz com que o motor se mova até que a contagem do encoder chegue ao número determinado
    while (abs(encoderM1.read())<= curvanoventa) {
      curvaDir(100);
    Serial.println(encoderM1.read());
    }
    frear(0);
   }


   void noventaesquerda()
   {
    
    encoderM1.write(0);
    // Faz com que o motor se mova até que a contagem do encoder chegue ao número determinado
    while (abs(encoderM1.read())<= curvanoventaesqu) {
    curvaEsq(100);
    Serial.println(encoderM1.read());
    }
    frear(0);
   }

   void quarentaecincoesquerda()
   {
    
    encoderM1.write(0);
    // Faz com que o motor se mova até que a contagem do encoder chegue ao número determinado
    while (abs(encoderM1.read())<= curvanoventaesqu / 1.8) {
    curvaEsq(100);
    Serial.println(encoderM1.read());
    }
    frear(0);
   }

   void quarentaecincodireita()
   {
    
    encoderM1.write(0);
    // Faz com que o motor se mova até que a contagem do encoder chegue ao número determinado
    while (abs(encoderM1.read())<= curvanoventa / 2) {
    curvaEsq(100);
    Serial.println(encoderM1.read());
    }
    frear(0);
   }
