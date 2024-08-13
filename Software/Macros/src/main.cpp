#include <Arduino.h>
#include <Keyboard.h>
#include <Encoder.h>

const int numRows = 4;
const int numCols = 5;

const int totalButtons = 16;

// Define the row and column pins
const int rowPins[numRows] = {A3, A2, A1, A0};
const int colPins[numCols] = {5, 6, 7, 8, 9};

#define ENCODER_PIN1 2
#define ENCODER_PIN2 3

const unsigned long debounceTime = 100;

Encoder myEnc(ENCODER_PIN1, ENCODER_PIN2);

long oldPosition = -999;
unsigned long lastDebounceTime[numRows][numCols];
bool keyState[numRows][numCols];

// Function prototypes
void customFunction1();
void customFunction2();
void customFunction3();
void customFunction4();
void customFunction5();
void customFunction6();
void customFunction7();
void customFunction8();
void customFunction9();
void customFunction10();
void customFunction11();
void customFunction12();
void customFunction13();
void customFunction14();
void customFunction15();
void customFunction16();

// Array of function pointers corresponding to each button
void (*buttonFunctions[totalButtons])() = {
    customFunction1, customFunction2, customFunction3, customFunction4,
    customFunction5, customFunction6, customFunction7, customFunction8,
    customFunction9, customFunction10, customFunction11, customFunction12,
    customFunction13, customFunction14, customFunction15, customFunction16,
};

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
      int buttonIndex = row * (numCols - 1) + (col - 1); // Calculate button index
      
      if (col == 0 || buttonIndex >= totalButtons) continue;
      
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

            // Call the corresponding function for the button
            buttonFunctions[buttonIndex]();
            
            Serial.print("Button Pressed: ");
            Serial.println(buttonIndex + 1);
            lastDebounceTime[row][col] = currentTime;
          }
        }
      } else {
        if (keyState[row][col] == true) {
          keyState[row][col] = false;
          Serial.print("Button Released: ");
          Serial.println(buttonIndex + 1);
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

// Define custom functions for each macro
void customFunction1() {
  Serial.println("Custom Function 1 executed");
  // Add custom functionality here
}

void customFunction2() {
  Serial.println("Custom Function 2 executed");
  // Add custom functionality here
}

void customFunction3() {
  Serial.println("Custom Function 3 executed");
  // Add custom functionality here
}

void customFunction4() {
  Serial.println("Custom Function 4 executed");
  // Add custom functionality here
}

void customFunction5() {
  Serial.println("Custom Function 5 executed");
  // Add custom functionality here
}

void customFunction6() {
  Serial.println("Custom Function 6 executed");
  // Add custom functionality here
}

void customFunction7() {
  Serial.println("Custom Function 7 executed");
  // Add custom functionality here
}

void customFunction8() {
  Serial.println("Custom Function 8 executed");
  // Add custom functionality here
}

void customFunction9() {
  Serial.println("Custom Function 9 executed");
  // Add custom functionality here
}

void customFunction10() {
  Serial.println("Custom Function 10 executed");
  // Add custom functionality here
}

void customFunction11() {
  Serial.println("Custom Function 11 executed");
  // Add custom functionality here
}

void customFunction12() {
  Serial.println("Custom Function 12 executed");
  // Add custom functionality here
}

void customFunction13() {
  Serial.println("Custom Function 13 executed");
  // Add custom functionality here
}

void customFunction14() {
  Serial.println("Custom Function 14 executed");
  // Add custom functionality here
}

void customFunction15() {
  Serial.println("Custom Function 15 executed");
  // Add custom functionality here
}

void customFunction16() {
  Serial.println("Custom Function 16 executed");
  // Add custom functionality here
}
