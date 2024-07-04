#include <Adafruit_NeoPixel.h>

constexpr int stripPin = 6;
constexpr int NUMPIXELS = 24;

Adafruit_NeoPixel pixels(NUMPIXELS, stripPin, NEO_GRB + NEO_KHZ800);  // Initialize NeoPixel library

void setup() {
  pixels.begin();
}

void loop() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(255, 25, 0)); // Set all pixels red
  }
  pixels.show();
  delay(500);

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 25)); // Set all pixels green
  }
  pixels.show();
  delay(500);

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(25, 0, 255)); // Set all pixels blue
  }
  pixels.show();
  delay(500);
}