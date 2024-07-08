#include <Mouse.h>
#include <Encoder.h>

#define SW_GND 5
#define SW_PIN 3

#define ROT_B 10
#define ROT_GND 9
#define ROT_A 8

#define LED_PIN 13

#define DEBOUNCE_DELAY 1000

Encoder encoder(ROT_A, ROT_B);

long oldPosition = -999;
long lastPressTime = 0;
long lastMoveTime = 0;

bool isJiggling = false;
int moveState = 0;

void setup() {
  Serial.begin(115200);
  Mouse.begin();
  pinMode(SW_GND, OUTPUT);
  pinMode(ROT_GND, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  pinMode(SW_PIN, INPUT_PULLUP);

  digitalWrite(ROT_GND, LOW);
  digitalWrite(SW_GND, LOW);
}

int shift = 2;
int wait = 250;

void loop() {
  long currentTime = millis();
  bool btnPressed = !digitalRead(SW_PIN);

  if (btnPressed && (currentTime - lastPressTime) > DEBOUNCE_DELAY) {
    Serial.println("Cycled Jiggling");
    isJiggling = !isJiggling;
    digitalWrite(LED_PIN, !isJiggling);
    lastPressTime = currentTime;
  }
  long newPosition = encoder.read();
  if (newPosition != oldPosition) {
    int rotationDirection = newPosition - oldPosition;
    if (shift == 1 && rotationDirection > 0) {
      shift++;
    } else if (shift == 100 && rotationDirection < 0) {
      shift--;
    } else if (shift > 1 && shift < 100) {
      shift = rotationDirection < 0 ? shift - 1 : shift + 1;
    }
    oldPosition = newPosition;
  }

  if (isJiggling && (currentTime - lastMoveTime) > wait) {
    lastMoveTime = currentTime;
    Serial.println(shift);
    switch (moveState) {
      case 0:
        Mouse.move(shift, -shift, 0);
        break;
      case 1:
        Mouse.move(shift, shift, 0);
        break;
      case 2:
        Mouse.move(-shift, shift, 0);
        break;
      case 3:
        Mouse.move(-shift, -shift, 0);
        break;
    }
    moveState = (moveState + 1) % 4;
  }
}