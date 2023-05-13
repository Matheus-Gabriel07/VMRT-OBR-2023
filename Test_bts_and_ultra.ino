#include <HCSR04.h>
#include <Buttons>

UltraSonicDistanceSensor sensorFrente (45, 44);
UltraSonicDistanceSensor sensorEsq (43, 42);
UltraSonicDistanceSensor sensorDir (49, 48);
int distace, distaceLatEsq, distaceLatDir;
int alvo = 10;
int LED_green  = 9;
int LED_redEsq = 8;
int LED_redDir = 10;


void setup () {
  pinMode(LED_green, OUTPUT);
  pinMode(LED_redEsq, OUTPUT);
  pinMode(LED_redDir, OUTPUT);
  Serial.begin(1200);
}

void loop () {
  distace = sensorFrente.measureDistanceCm();
  distaceLatEsq = sensorEsq.measureDistanceCm();
  distaceLatDir = sensorDir.measureDistanceCm();

  if (distace != alvo && distace > alvo) {
    digitalWrite(LED_green, HIGH);
    digitalWrite(LED_redDir, HIGH);
    digitalWrite(LED_redEsq, HIGH);
    delay(150);
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_redDir, LOW);
    digitalWrite(LED_redEsq, LOW);
    delay(150);
    return;
  }

  if (distace <= alvo && distace > 5) {
    Serial.println(distace);
    digitalWrite(LED_green, HIGH);
    delay (100);
    
    if (distaceLatEsq <= alvo && distaceLatEsq > 4) {
      Serial.print(distaceLatEsq);
      digitalWrite(LED_redEsq, HIGH);
      delay (100);
    } else if (distaceLatDir <= alvo && distaceLatDir > 4) {
      Serial.print(distaceLatDir);
      digitalWrite(LED_redDir, HIGH);
      delay (100);
    } else {
      digitalWrite(LED_redDir, LOW);
      digitalWrite(LED_redEsq, LOW);
      delay(100);
    }
  }
  else if (distace < 5) {
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_redDir, HIGH);
    digitalWrite(LED_redEsq, HIGH);
    delay(150);
    digitalWrite(LED_redDir, LOW);
    digitalWrite(LED_redEsq, LOW);
    delay(150);
  }
}
