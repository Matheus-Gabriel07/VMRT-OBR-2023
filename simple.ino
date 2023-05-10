#include <HCSR04.h>
#define T_PIN_frente  45;
#define E_PIN_frente  44;

UltraSonicDistanceSensor distanceSensor(T_PIN_frente, E_PIN_frente);
int start = 0;
int tempo = 0;
int dist = 10;

void setup () {
    Serial.begin(9600); 
}

void loop () {
    
    if(distanceSensor.measureDistanceCm() == dist) {
      Serial.println(distanceSensor.measureDistanceCm());
      delay(100);
    }
    
    if (start = 0){
      tempo = millis();
      start = 1;
    }

/*    if (millis() - tempo > 1000){
      Serial.println(distanceSensor.measureDistanceCm());
      Serial.print("tempo: " );
      Serial.println( tempo);
      Serial.print("millis: ");
      Serial.println(millis());
      tempo  = millis();
    }

  */
}
