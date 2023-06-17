include <>

int LED_green = 9;
int LED_red = 8, 11;

//Ultrasonic
const int trigPin = ;
const int echoPin = ;
long duration;
int dist;

void setup () {
  pinMode(LED_green, OUTPUT);
  pinMode(LED_red, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  serial.begin(9600);
}

void loop (){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  
  duration = pulseln(echoPin, HIGH):
  dist = duration*0.032/2;
  
  if (dist <=10 && >5) {
    digitalWrite(LED_green, HIGH);
    delay(10);
    digitalWrite(LED_green, LOW);
    delay(10);
  }
  else if (dist >10 || <5) {
    digitalWrite(LED_red, HIGH);
    delay(10);
    digitalWrite(LED_red, LOW);
    delay(10);
  }
}
