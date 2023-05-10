#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(45, 44);  // Initialize sensor that uses digital pins 13 and 12.
int start = 0;
int tempo = 0;
int dist = 10;

void setup () {
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
}

void loop () {
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.

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

    if(distanceSensor.measureDistanceCm() == dist) {
      Serial.println(distanceSensor.measureDistanceCm());
      delay(100);
    }
    
}
