//                  sensor  |  placa        placa.S

#define sen1 A8 //  cinza    |  marrom   |
#define sen2 A9 //  azul    |  vermelho |   
#define sen3 A10 //  verde   |  laranja  |
#define sen4 A11 //  amarelo |  amarelo  |
#define sen5 A12 //  laranja |  verde    |
#define sen6 A13 //  branco  |  roxo     |
#define sen7 A14 //  preto   |  cinza    |
#define sen8 A15//   marrom  | marrom    |





void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200);
  pinMode(sen8, INPUT);
  pinMode(sen7, INPUT);
  pinMode(sen6, INPUT);
  pinMode(sen5, INPUT);
  pinMode(sen4, INPUT);
  pinMode(sen3, INPUT);
  pinMode(sen2, INPUT);
  pinMode(sen1, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(sen1));
  Serial.print(" ");
  Serial.print(analogRead(sen2));
  Serial.print(" ");
  Serial.print(analogRead(sen3));
  Serial.print(" ");
  Serial.print(analogRead(sen4));
  Serial.print(" ");
  Serial.print(analogRead(sen5));
  Serial.print(" ");
  Serial.print(analogRead(sen6));
  Serial.print(" ");
  Serial.print(analogRead(sen7));
  Serial.print(" ");
  Serial.print(analogRead(sen8));
  Serial.println(" ");
    Serial.println(" ");

    
  
  

}
