#include <Servo.h>

Servo myservo;
unsigned int angle = 0;
unsigned int newAngle = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  myservo.write(angle);
}

void loop() {
  if (Serial.available() > 0) {
    newAngle = Serial.parseInt();
    if (newAngle >= 0 && newAngle <= 360){ 
      angle = newAngle;
      myservo.write(angle);
      Serial.println("Servo moved to: " + String(angle) + " degrees");
    } else {
      Serial.println("Invalid angle. Please enter a value between 0 and 180.");
    }
  }
}
