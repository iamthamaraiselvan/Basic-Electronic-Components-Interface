
#include <Adafruit_LiquidCrystal.h>

const int seconds = 0;
const int minutes = 1;
const int hours = 2;

Adafruit_LiquidCrystal lcd(0);

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.print("00:00:00");
}

void loop()
{
  lcd.setCursor(0, 1);
  
  unsigned long currentTime = millis();
  int currentSeconds = (currentTime / 1000) % 60;
  int currentMinutes = (currentTime / (60 * 1000)) % 60;
  int currentHours = (currentTime / (3600 * 1000)) % 24;

  lcd.print(zeroPad(currentHours, 2));
  lcd.print(":");
  lcd.print(zeroPad(currentMinutes, 2));
  lcd.print(":");
  lcd.print(zeroPad(currentSeconds, 2));

  delay(1000);//time is not accurate because of online simulation
}

String zeroPad(int num, size_t len) {
  String str = String(num);
  while (str.length() < len) {
    str = "0" + str;
  }
  return str;
}