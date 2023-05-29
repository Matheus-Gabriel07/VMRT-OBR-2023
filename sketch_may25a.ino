#define EN 8 // stepper motor enable , active low
#define X_DIR 5 // X -axis stepper motor direction control
#define Y_DIR 6 // y -axis stepper motor direction control
#define Z_DIR 7 // z axis stepper motor direction control
#define X_STP 2 // x -axis stepper control
#define Y_STP 3 // y -axis stepper control
#define Z_STP 4 // z -axis stepper control
// Function : step . function: to control the direction of the stepper motor , the number of steps .
// Parameters : dir direction control , dirPin corresponding stepper motor DIR pin , stepperPin corresponding stepper motor " step " pin , Step number of step of no return value.
void stepX (boolean dir, byte dirPin, byte stepperPin, int steps, int steplength)
{
  digitalWrite (dirPin, dir);
  //delay (500);
  for (int i = 0; i < steps; i++)
  {
    digitalWrite (stepperPin, HIGH);
    delayMicroseconds (450);
    digitalWrite (stepperPin, LOW);
    delayMicroseconds (500);
    Serial.println(steps);
  }
}

void stepY (boolean dir, byte dirPin, byte stepperPin, int steps, int steplength)
{
  digitalWrite (dirPin, dir);
  for (int i = 0; i < steps; i++)
  {
    digitalWrite (stepperPin, HIGH);
    delayMicroseconds (steplength);
    digitalWrite (stepperPin, LOW);
    delayMicroseconds (500);
  }
}

void setup() {
  // put your setup code here, to run once:
  // The stepper motor used in the IO pin is set to output
  pinMode (X_DIR, OUTPUT); pinMode (X_STP, OUTPUT);
  pinMode (Y_DIR, OUTPUT); pinMode (Y_STP, OUTPUT);
  pinMode (EN, OUTPUT);
  digitalWrite (EN, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  stepX (true, X_DIR, X_STP, 500, 400); // X axis motor reverse 1 ring, the 200 step is a circle.
  stepY (false, Y_DIR, Y_STP, 500, 400); // y axis motor reverse 1 ring, the 200 step is a circle

  stepX (false, X_DIR, X_STP, 500, 400); // X axis motor reverse 1 ring, the 200 step is a circle.
  stepY (true, Y_DIR, Y_STP, 500, 400); // y axis motor reverse 1 ring, the 200 step is a circle.
  delay(500);
}
