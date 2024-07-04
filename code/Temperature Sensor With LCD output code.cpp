#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);

float celsius;
int temp = A1;

void setup(){
	pinMode(temp,INPUT);
  	Serial.begin(9600);
  	lcd_1.begin(16, 2);
}

void loop(){
	celsius = analogRead(temp)*0.004882814;
  	celsius = (celsius - 0.5) * 100.0;
  
  	Serial.println(celsius);
  	lcd_1.setCursor(0,1);
	lcd_1.print("Temp: ");
  	lcd_1.print(celsius);
	lcd_1.print(" C");
  	lcd_1.clear();
	
}
