#include <Encoder.h>
#include <Ultrasonic.h>


//DECLARAÇÃO DOS SENSORES DE REFLETÂNCIA
#define sensor1 A10
#define sensor2 A11
#define sensor3 A12
#define sensor4 A13

//DECLARAÇÃO DOS SENSORES DE COR
#define cor1 A9    //CABO AZUL
#define cor2 A8    //CABO VERDE   

//DECLARAÇÃO DOS MOTORES
#define G1 12      //motor GARRA
#define G2 13      //motor GARRA
#define M2 5      //motor da direita
#define M1 6      //motor da esquerda
#define PWM2 4    //pwm do motor da direita 
#define PWM1 7    //pwm do motor da esquerda
Encoder encoderM1(18, 19);
Encoder encoderM2(20, 21);
#define C1 10     //motor comporta
#define C2 11     //motor comporta



//declaração ultrassonicos

#define T_PIN_frente  22
#define E_PIN_frente  23
Ultrasonic u_frente(T_PIN_frente, E_PIN_frente);
#define T_PIN_lat  24
#define E_PIN_lat  25
Ultrasonic u_lat(T_PIN_lat, E_PIN_lat);
#define T_PIN_late  26
#define E_PIN_late  27
Ultrasonic u_late(T_PIN_late, E_PIN_late);

boolean rampa = false;
int ultima_medida, contador = 0;
int dist_esq, dist_dir = 10000;
int dist_garra = 20;
// olhar o robô, , de frente para onde sobe a fiação dos motores. motor a direita, é o que está a sua direita. esquerda a mesma coisa, mas a esquerda
//REGULAGEM DO ROBÔ COMEÇA AQUI

int preto   = 800;        //define valor de refletância para o preto. mudar aqui, após testar os sensores
int corte   = 990;       //define valor que o sensor de refletância, descarta. usamos para acertar os redutores de velocidade
int l_linha = 280;      //define extensão da linha, perpendicularmente ao robô. tempo que o robô tem que andar, para ultrapassar uma linha em um cruzamento
int ajuste  = 100;        //distância que regula a posição do sensor de cor
int verde1  = 405;
int verde2  = 375;//leitura do verde
int corte_verde1 = 236; //corte para o verde
int corte_verde2 = 175; //corte para o verde
//Velocidade dos Motores
int F1 = 200;          //forca a ser aplicada no motor 1 (direita)
int F2 = 200;           //forca a ser aplicada no motor 2 (esquerda)
int FG = 150;
int FC = 100;
int tempo_atual = 0;
int tempo = 0;
float obst = 0;
float distancia_parada = 11;


//Valores dos obstáculos
int curvanoventa       = 1650;    //número de pulsos do encoder para uma curva de noventa graus
int curvanoventaesqu   = 1450;
int curva_direita  = 2000;    //período que o robô leva para fazer uma curva de 90º direita
int curva_esquerda = 1700;    //período que o robô leva para fazer uma curva de 90º esquerda
int comp_obs       = 5000;    //comprimento do obstáculo
int larg_obs       = 4750;    //largura do obstáculo

//REGULAGEM DO ROBÔ ACABA AQUI


void setup() {
  // inicia serial. o serial, pode ser usado para acompanhar a leitura dos sensores
  Serial.begin(9600);


  //incia motores
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);

}

void loop() {
  //loping do programa com segue linha e detecção de obstáculos combinados
/*

  while (rampa == false) {



    int leitura_verdade = leitura_sensor();          // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
    Serial.println(leitura_verdade);                 // imprime as leituras em serial
    segue_linha(leitura_verdade);                    // sobe condição da leitura atual no segue linha



    tempo_atual = millis();


    tempo = tempo_atual - ultima_medida;
    //Serial.println(tempo);
    if (tempo > 50) {
      ultima_medida = tempo_atual;
      tempo = 0;
      obst = distancia_frente();
      dist_dir = distancia_lateral();
      dist_esq = esq_distancia_lateral();
      Serial.println("entrei");
        if (obst < distancia_parada && obst!=0 ) {
          Serial.println("DESVIA");
          desvia();
        }
        
        

        if (dist_dir < 10 || dist_esq < 10 && dist_dir != 0 && dist_esq != 0){
          contador = contador + 1;
          Serial.println(contador);
          Serial.println(dist_dir);
          Serial.println(dist_esq);
          }
          else{
            contador = 0;
            }

            if (contador > 10){
              rampa = true;
              }


    }

    Serial.println(leitura_verdade);
    Serial.println(obst);
}

  while (rampa == true){
    
    int leitura_verdade = leitura_sensor();          // leitura dos sensores de refletância, classificação de ligado/desligado pela tabela verdade
    Serial.println(contador);
    Serial.println("rampa");                 // imprime as leituras em serial
    segue_rampa(leitura_verdade);                    // sobe condição da leitura atual no segue linha
    tempo_atual = millis();
    tempo = tempo_atual - ultima_medida;
    if (tempo > 100) {
      ultima_medida = tempo_atual;
      tempo = 0;
      dist_dir = distancia_lateral();
      dist_esq = esq_distancia_lateral();
      Serial.println(dist_esq);  
        if (dist_esq > 10 ){
          contador = contador + 1;
          
          }
          else{
            contador = 0;
            }

         if (contador > 10){
           rampa = false;
              }
    }
 }

while (rampa == false){
  
  delay(10000);
  */resgate();
  //}

}