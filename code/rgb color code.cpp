#define redPin 11
#define greenPin 9
#define bluePin 10

const int MAX_COLOR_NAME_LENGTH = 10;
char colorName[MAX_COLOR_NAME_LENGTH];

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  setAllLedsOff();
}

void loop() {
  if (Serial.available() > 0) {
    int i = 0;
    while (Serial.available() > 0) {
      colorName[i] = Serial.read();
      if (colorName[i] == '\n') {
        break;
      }
      i++;
    }
    colorName[i] = '\0';
    Serial.print("Received: ");
    Serial.println(colorName);

    setColorFromName(colorName);
  }
}

void setAllLedsOff() {
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}

void setColorFromName(char* name) {
  int red = 0, green = 0, blue = 0;

  if (strcmp(name, "red") == 0) {
    red = 255;
  } else if (strcmp(name, "green") == 0) {
    green = 255;
  } else if (strcmp(name, "blue") == 0) {
    blue = 255;
  } else if (strcmp(name, "white") == 0) {
    red = green = blue = 255;
  } else if (strcmp(name, "yellow") == 0) {
    red = 255;
    green = 128;
  } else if (strcmp(name, "purple") == 0) {
    red = 128;
    blue = 255;
  } else if (strcmp(name, "cyan") == 0) {
    green = 255;
    blue = 255;
  } else {
    Serial.println("Invalid color name. Try red, green, blue, white, yellow, purple, or cyan.");
  }

  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}