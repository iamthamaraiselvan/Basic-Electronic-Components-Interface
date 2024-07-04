const int potPin = A0;
int sensorValue = 0; 
float resistance = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(potPin); 
  resistance = (float)sensorValue / 1023.0;
  resistance = resistance * 1000.0;

  Serial.print("Raw ADC Value: ");
  Serial.println(sensorValue);
  Serial.print("Resistance (Ohms): ");
  Serial.println(resistance);

  delay(1000);
}