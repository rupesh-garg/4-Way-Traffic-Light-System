const int redPins[4]    = {2, 8, 6, 13};
const int yellowPins[4] = {1, 9, 5, 12};
const int greenPins[4]  = {0, 10, 4, 11};

const unsigned long GREEN_TIME  = 5000;
const unsigned long YELLOW_TIME = 2000;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(redPins[i], OUTPUT);
    pinMode(yellowPins[i], OUTPUT);
    pinMode(greenPins[i], OUTPUT);

    digitalWrite(redPins[i], HIGH);
    digitalWrite(yellowPins[i], LOW);
    digitalWrite(greenPins[i], LOW);
  }

  delay(500);
}

void loop() {
  for (int dir = 0; dir < 4; dir++) {
    activateDirection(dir);
  }
}

void activateDirection(int dir) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(redPins[i], HIGH);
    digitalWrite(greenPins[i], LOW);
    digitalWrite(yellowPins[i], LOW);
  }

  digitalWrite(redPins[dir], LOW);
  digitalWrite(greenPins[dir], HIGH);
  delay(GREEN_TIME);

  digitalWrite(greenPins[dir], LOW);
  digitalWrite(yellowPins[dir], HIGH);
  delay(YELLOW_TIME);

  digitalWrite(yellowPins[dir], LOW);
  digitalWrite(redPins[dir], HIGH);
}
