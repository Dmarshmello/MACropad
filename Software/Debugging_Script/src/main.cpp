/*
 * ------------------------------
 * MACropad | MAC x SMEE Workshop
 * 
 * Project: Numpad
 * Description: This program turns the MACROPAD into a numpad with keys numbered 1 through 16. 
 *              The rotary encoder is used to control the system volume.
 * 
 * Author: Ethan Dmello
 * Date: 8/13/2024
 * --------------------------------
 */

#include <Arduino.h>
#include <Encoder.h>
#include <HID-Project.h>

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

#define ENCODER_PIN1 16
#define ENCODER_PIN2 4

const unsigned long debounceTime = 100;

Encoder myEnc(ENCODER_PIN1, ENCODER_PIN2);

long oldPosition = -999;
unsigned long lastDebounceTime[numRows][numCols];
bool keyState[numRows][numCols];

void setup() {
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

  BootKeyboard.begin();
  Consumer.begin(); // Initialize the ConsumerControl (for media keys)
}

void loop() {
  for (int row = 0; row < numRows; row++) {
    digitalWrite(rowPins[row], LOW); // Activate the current row
    for (int col = 1; col < numCols; col++) { // Start from col=1 because col=0 is the encoder
      if (keys[row][col] == 0) continue; // Skip the encoder position

      unsigned long currentTime = millis();
      if (digitalRead(colPins[col]) == LOW) { // Button pressed
        if (keyState[row][col] == false && (currentTime - lastDebounceTime[row][col] > debounceTime)) {
          keyState[row][col] = true; // Mark the key as pressed
          BootKeyboard.print(keys[row][col]); // Send the corresponding number via keyboard
          lastDebounceTime[row][col] = currentTime; // Update debounce time
        }
      } else { // Button released
        if (keyState[row][col] == true) {
          keyState[row][col] = false; // Reset the key state
        }
      }
    }
    digitalWrite(rowPins[row], HIGH); // Deactivate the current row
  }

  // Rotary encoder controls volume
  long newPosition = myEnc.read() / 4;
  if (newPosition != oldPosition) {
    if (newPosition > oldPosition) {
      Consumer.write(MEDIA_VOLUME_UP);  // Increase volume
    } else {
      Consumer.write(MEDIA_VOLUME_DOWN);  // Decrease volume
    }
    oldPosition = newPosition;
  }
}
