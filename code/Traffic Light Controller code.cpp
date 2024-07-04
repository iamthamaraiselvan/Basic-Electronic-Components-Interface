
int redPin1 = 5;
int yellowPin = 6;
int greenPin1 = 7;

void setup() {
  pinMode(redPin1, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin1, OUTPUT);
}

void loop() {
  changeLights();
  digitalWrite(greenPin1, LOW);
}


void changeLights() {
  digitalWrite(redPin1, HIGH);
  delay(5000); 
  digitalWrite(redPin1, LOW); 
  digitalWrite(yellowPin, HIGH);
  delay(1000); 

  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin1, HIGH);
  delay(5000);
}