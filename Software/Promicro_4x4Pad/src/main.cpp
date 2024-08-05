#include <Arduino.h>
#include <Keyboard.h>
#include <Encoder.h>

// Define the rows and columns based on your layout
const int numRows = 4;
const int numCols = 5;

// Define the key map (modified for 4x5 layout)
char keys[numRows][numCols] = {
  {0, '1', '2', '3', '4'},
  {0, '5', '6', '7', '8'},
  {0, '9', '0', 'A', 'B'},
  {'X', 'C', 'D', 'E', 'F'}
};

// Define the row and column pins based on your layout
const int rowPins[numRows] = {3, 4, 5, 6}; // Use appropriate digital pins
const int colPins[numCols] = {7, 8, 9, 10, 16}; // Use appropriate digital pins

// Rotary encoder pins
#define ENCODER_PIN1 2
#define ENCODER_PIN2 3
#define BUTTON_PIN 4

// Create encoder object
Encoder myEnc(ENCODER_PIN1, ENCODER_PIN2);

long oldPosition = -999;
bool buttonState = HIGH;
bool lastButtonState = HIGH;

void setup() {
  // Initialize the row pins as outputs
  for (int i = 0; i < numRows; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }

  // Initialize the column pins as inputs with pullup resistors
  for (int i = 0; i < numCols; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }

  // Initialize the button pin
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Begin the Keyboard library
  Keyboard.begin();
}

void loop() {
  // Check the macropad keys
  for (int row = 0; row < numRows; row++) {
    digitalWrite(rowPins[row], LOW); // Activate the current row
    for (int col = 0; col < numCols; col++) {
      if (keys[row][col] == 0) continue; // Skip undefined keys
      if (digitalRead(colPins[col]) == LOW) { // Check if the button is pressed
        Keyboard.press(keys[row][col]);
        delay(100); // Debounce delay
        Keyboard.release(keys[row][col]);
      }
    }
    digitalWrite(rowPins[row], HIGH); // Deactivate the current row
  }

  // Check the rotary encoder
  long newPosition = myEnc.read() / 4;
  if (newPosition != oldPosition) {
    if (newPosition > oldPosition) {
      Keyboard.press(KEY_RIGHT_ARROW); // Turned clockwise
      delay(100); // Debounce delay
      Keyboard.release(KEY_RIGHT_ARROW);
    } else {
      Keyboard.press(KEY_LEFT_ARROW); // Turned counterclockwise
      delay(100); // Debounce delay
      Keyboard.release(KEY_LEFT_ARROW);
    }
    oldPosition = newPosition;
  }

  // Check the push button
  buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == LOW && lastButtonState == HIGH) {
    Keyboard.press(KEY_CAPS_LOCK); // Button pressed
    delay(100); // Debounce delay
    Keyboard.release(KEY_RETURN);
  }
  lastButtonState = buttonState;
}
