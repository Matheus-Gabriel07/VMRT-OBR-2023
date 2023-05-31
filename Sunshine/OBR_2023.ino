#include <Encoder.h>
#include <HCSR04.h>

// Definição do sensores de refletância
#define sen1 (A13)
#define sen2 (A12)
#define sen3 (A11)
#define sen4 (A10)
#define sen5 (A9)
#define sen6 (A8)
#define sen7 (A7)
#define sen8 (A14)

// Definição dos sensores de cor

#define ldr1 (A0)
#define ldr2 (A1)

// Definição dos motores
//...

// Definição dos sensores ultrasonicos

UltraSonicDistanceSensor sensorFrente (45, 44);
UltraSonicDistanceSensor sensorEsq (49, 48);
UltraSonicDistanceSensor sensorDir (46, 47);
int distace, distaceLatEsq, distaceLatDir;
int alvo = 10;

// Definição dos LEDS

int LED_green  = 9;
int LED_redEsq = 8;
int LED_redDir = 10;

// Definição dos Botões

int BTN_f4 = 35;
int BTN_f3 = 0;
int BTN_f2 = 0;
int BTN_f1 = 0;

// Globais e regulação

int preto; // Valor de refletancia do preto
int corteMax = 990; // Valor de descarte de preto, usado para acertar os redutores de velocidade
int l_linha = 200; // largura da linha

int ajuste = 200; // Regulação da distância do sensor de cor
int verdeEsq = 400; 
int verdeDir = 400;
int corteVerde1 = 375; // Valor de corte
int corteVerde2 = 375;

//Velocidade dos Motores
int F1 = 200;          //forca a ser aplicada no motor 1 (direita)
int F2 = 200;           //forca a ser aplicada no motor 2 (esquerda)
int FG = 150;
int FC = 100;
int tempo_atual = 0;
int tempo = 0;
float obst = 0;
float distancia_parada = 11;

//REGULAGEM DO ROBÔ ACABA AQUI

void setup() {
  Serial.begin(1200);
  
  pinMode(sen1, INPUT):
  pinMode(sen2, INPUT):
  pinMode(sen3, INPUT):
  pinMode(sen4, INPUT):
  pinMode(sen5, INPUT):
  pinMode(sen6, INPUT):
  pinMode(sen7, INPUT):
  pinMode(sen8, INPUT):

  pinMode(LED_green, OUTPUT):
  pinMode(LED_redEsq, OUTPUT):
  pinMode(LED_redDir, OUTPUT):

  pinMode(BTN_f1, INPUT_PULLUP);
  pinMode(BTN_f2, INPUT_PULLUP);
  pinMode(BTN_f3, INPUT_PULLUP);
  pinMode(BTN_f4, INPUT_PULLUP);
}

void loop() {
  // Escrever código
}
