#include <Arduino.h>
#include <Keyboard.h>
#include <Encoder.h>

const int numRows = 4;
const int numCols = 5;

const char* keys[numRows][numCols] = {
  {0, "4", "8", "12", "16"},
  {0, "3", "7", "11", "15"},
  {0, "2", "6", "10", "14"},
  {"X", "1", "5", "9", "13"}
};

const int rowPins[numRows] = {A3, A2, A1, A0};
const int colPins[numCols] = {5, 6, 7, 8, 9};

#define ENCODER_PIN1 2
#define ENCODER_PIN2 3

const unsigned long debounceTime = 100;

Encoder myEnc(ENCODER_PIN1, ENCODER_PIN2);

long oldPosition = -999;
unsigned long lastDebounceTime[numRows][numCols];
bool keyState[numRows][numCols];

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Pro Micro connected and ready!");

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);

  for (int i = 0; i < numRows; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
    for (int j = 0; j < numCols; j++) {
      keyState[i][j] = false;
    }
  }

  for (int i = 0; i < numCols; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }

  Keyboard.begin();
  Serial.println("Keyboard library initialized.");
}

void loop() {
  for (int row = 0; row < numRows; row++) {
    digitalWrite(rowPins[row], LOW); 
    for (int col = 0; col < numCols; col++) {
      if (keys[row][col] == 0) continue;
      
      unsigned long currentTime = millis();
      if (digitalRead(colPins[col]) == LOW) {
        if (keyState[row][col] == false && (currentTime - lastDebounceTime[row][col] > debounceTime)) {
          bool multipleKeysPressed = false;
          for (int checkCol = 0; checkCol < numCols; checkCol++) {
            if (checkCol != col && digitalRead(colPins[checkCol]) == LOW) {
              multipleKeysPressed = true;
              break;
            }
          }
          
          if (!multipleKeysPressed) {
            keyState[row][col] = true;
            Keyboard.print(keys[row][col]);
            Serial.print("Key Pressed: ");
            Serial.println(keys[row][col]);
            lastDebounceTime[row][col] = currentTime;
          }
        }
      } else {
        if (keyState[row][col] == true) {
          keyState[row][col] = false;
          Serial.print("Key Released: ");
          Serial.println(keys[row][col]);
          delay(100);
        }
      }
    }
    digitalWrite(rowPins[row], HIGH);
  }

  long newPosition = myEnc.read() / 4;
  if (newPosition != oldPosition) {
    if (newPosition > oldPosition) {
      Keyboard.press(KEY_RIGHT_ARROW);
      Serial.println("Rotary Encoder: Clockwise");
      delay(100);
      Keyboard.release(KEY_RIGHT_ARROW);
    } else {
      Keyboard.press(KEY_LEFT_ARROW);
      Serial.println("Rotary Encoder: Counterclockwise");
      delay(100);
      Keyboard.release(KEY_LEFT_ARROW);
    }
    oldPosition = newPosition;
  }
}
