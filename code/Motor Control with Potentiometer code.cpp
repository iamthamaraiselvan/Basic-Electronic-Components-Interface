#define motorPin 3
#define potPin A0  

int motorSpeed = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  motorSpeed = map(analogRead(potPin), 0, 1023, 0, 255);
  analogWrite(motorPin, motorSpeed);
  delay(10);
}