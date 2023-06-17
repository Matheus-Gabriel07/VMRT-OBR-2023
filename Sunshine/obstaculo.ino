/*função para desvio do obstáculo
 * 
 */


void desvia() {

  noventinhaDir(vel_motor);
  setupMotor(0);
  setupMotor(1);
  unsigned int pp = graus;

  while ((graus - pp) < 360){
    frente(vel_motor);
    
  } 

  setupMotor(0);
  setupMotor(1);

  noventinhaEsq(vel_motor);

  
  pp = graus;


  while ((graus - pp) < 700){
    frente(vel_motor);
    
  }

  noventinhaEsq(vel_motor);

    pp = graus;
  
  while ((graus - pp) < 360){
    frente(vel_motor);
    
  }

  int bl = leitura_sensor();    

  while(bl < 1){
    curvaDir(vel_motor);
    bl = leitura_sensor();
  }

}
