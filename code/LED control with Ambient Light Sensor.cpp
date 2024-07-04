
int led = 13;
int LightPin = 2;

int Photo_Pin = A0;

int readPhoto;

void setup() {
  
  pinMode(led, OUTPUT);
  pinMode(LightPin, OUTPUT);
  
  pinMode(Photo_Pin, INPUT);
}


void loop() {
  digitalWrite(led, HIGH);
  readPhoto = analogRead(Photo_Pin);
  
  if (readPhoto < 518) {
  digitalWrite(LightPin, HIGH);
  }else{
      digitalWrite(LightPin, LOW);
  }
  
  delay(1);           
  digitalWrite(led, LOW);
}