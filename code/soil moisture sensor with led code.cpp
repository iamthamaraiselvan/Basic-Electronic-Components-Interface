const int sensorPin = A0;
const int greenLED = 3;
const int yellowLED = 5; 
const int orangeLED = 6;
const int redLED = 9;

int sensorValue = 0;
float moisture = 0.0;

void setup() {
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(orangeLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  digitalWrite(greenLED, LOW);  
  digitalWrite(yellowLED, LOW);
  digitalWrite(orangeLED, LOW);
  digitalWrite(redLED, LOW);
}

void loop() {
  sensorValue = analogRead(sensorPin); 
  moisture = (sensorValue/(float)1023)*100;
  Serial.print("Moisture (%): ");
  Serial.println(moisture);

  if (moisture >= 75) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(orangeLED, LOW);
    digitalWrite(redLED, LOW);
  } else if (moisture >= 50) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(orangeLED, HIGH);
    digitalWrite(redLED, LOW);
  } else if (moisture >= 25) {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(orangeLED, HIGH);
    digitalWrite(redLED, HIGH);
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(orangeLED, LOW);
    digitalWrite(redLED, HIGH);
  }

  delay(3000);
}