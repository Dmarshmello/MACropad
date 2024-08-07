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
const int rowPins[numRows] = {A3, A2, A1, A0}; // Use updated analog pins
const int colPins[numCols] = {5, 6, 7, 8, 9}; // Use appropriate digital pins

// Rotary encoder pins
#define ENCODER_PIN1 2
#define ENCODER_PIN2 3
#define RESET_PIN A3 // Pin to be used for reset functionality

// Create encoder object
Encoder myEnc(ENCODER_PIN1, ENCODER_PIN2);

long oldPosition = -999;

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for Serial port to connect. Needed for native USB port only
  }
  Serial.println("Pro Micro connected and ready!");

  // Blink the built-in LED to indicate reset
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }

  // Initialize the row pins as outputs
  for (int i = 0; i < numRows; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH); // Set row pins high
  }

  // Initialize the column pins as inputs with pullup resistors
  for (int i = 0; i < numCols; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }

  // Set up the reset pin
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(RESET_PIN, HIGH); // Ensure A3 is set high

  // Begin the Keyboard library
  Keyboard.begin();
  Serial.println("Keyboard library initialized.");
}

void loop() {
  // Keep the reset pin high all the time
  digitalWrite(RESET_PIN, HIGH);

  // Check the macropad keys
  for (int row = 0; row < numRows; row++) {
    digitalWrite(rowPins[row], LOW); // Activate the current row
    for (int col = 0; col < numCols; col++) {
      if (keys[row][col] == 0) continue; // Skip undefined keys
      if (digitalRead(colPins[col]) == LOW) { // Check if the button is pressed
        Keyboard.press(keys[row][col]);
        Serial.print("Key Pressed: ");
        Serial.println(keys[row][col]);
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
      Serial.println("Rotary Encoder: Clockwise");
      delay(100); // Debounce delay
      Keyboard.release(KEY_RIGHT_ARROW);
    } else {
      Keyboard.press(KEY_LEFT_ARROW); // Turned counterclockwise
      Serial.println("Rotary Encoder: Counterclockwise");
      delay(100); // Debounce delay
      Keyboard.release(KEY_LEFT_ARROW);
    }
    oldPosition = newPosition;
  }
}
