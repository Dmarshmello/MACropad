/*
 * ------------------------------
 * MACropad | MAC x SMEE Workshop
 * 
 * Project: Macros
 * Description: This program defines the MACROPAD layout and its associated macros based on the 
 *              orientation of the device. It monitors user input through a matrix of rows and 
 *              columns. Each function executes a unique macro, allowing for customizable 
 *              keyboard shortcuts and commands.
 * 
 * Author: Ethan Dmello
 * Date: 8/13/2024
 * --------------------------------
 */

#include <Arduino.h>
#include <Encoder.h>
#include <HID-Project.h> 
#include <Wire.h>

/// Switch Implementation (16)

// Define PCB matrix 4x4 buttons
const int totalButtons = 17;
const int numRows = 4;
const int numCols = 5;            // includes the rotary encoder
bool keyState[numRows][numCols];  // state of each button, pressed or not

// ProMicro pin numbers for each row and column
const int rowPins[numRows] = {A3, A2, A1, A0};
const int colPins[numCols] = {5, 6, 7, 8, 9};

// Debounce time to prevent multiple triggers
const unsigned long debounceTime = 100; 
unsigned long lastDebounceTime[numRows][numCols]; // time for each button

/// Rotary Implementation

// Define and initialize rotary encoder
#define ENCODER_PIN1 16
#define ENCODER_PIN2 4

Encoder myEnc(ENCODER_PIN1, ENCODER_PIN2);
long oldPosition = -999; // initial position of the encoder

// Macro function declarations
void openNewGoogleTab();
void openSpotify();
void putComputerToSleep();
void micOnOff();
void minimizeWindow();
void openMoodle();
void openCalculator();
void cameraOnOff();
void closeTab();
void openVScode();
void cntrlShiftT();
void bluetooth();
void openTab();
void openDiscord();
void screenCapture();
void hello();
void mute();
void volumeUp();   // Function for Volume Up
void volumeDown(); // Function for Volume Down
void gap();

/*Button Layout based on orientation of your board:
 * I decided vertical so the microcontroller sits at the top so my numbering is
 *                
 *   {(gap - promicro)   "0",     "1",    "2",     "3"},
 *   {(gap)              "4",     "5",    "6",     "7"},
 *   {(gap)              "8",     "9",    "10",    "11"},
 *   {(12 - rotary)      "13",    "14",   "15",    "16"}
 *         ^              ^        ^       ^        ^
 *        row0           row1     row2    row3     row4
 * 
 * Now arrange your functions in the layout you want, remember that the board was wired 
 * horizontally which is why my functions are organized based on numbering above 
*/

void (*buttonFunctions[totalButtons])() = {
            openNewGoogleTab,   openSpotify,      putComputerToSleep,   micOnOff,        
            minimizeWindow,     openMoodle,       openCalculator,       cameraOnOff,        
            closeTab,           openVScode,       cntrlShiftT,          bluetooth,
    mute,   openTab,            openDiscord,      screenCapture,        gap          
};

void setup() {
  // Initialize LED inside the microcontroller
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);

  // Activate rows by stepping through the row pins and setting them as high
  for (int i = 0; i < numRows; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }

  // Initialize columns as inputs with pull-up resistors
  for (int i = 0; i < numCols; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }

  // Initialize the key states
  memset(keyState, false, sizeof(keyState));

  // Start the keyboard to send commands
  BootKeyboard.begin();
  Consumer.begin(); // Initialize the ConsumerControl (for media keys)
}

void loop() {
  // Iterate through each row to check if any button is pressed
  for (int row = 0; row < numRows; row++) {
    digitalWrite(rowPins[row], LOW); // Activate the current row

    // Iterate through each column in the current row
    for (int col = 0; col < numCols; col++) { // Start from col=1 because col=0 is the encoder
      int buttonIndex;
      if (row == 3) {
          buttonIndex = 12 + col;  // Row 4 has no gap
      } else {
          buttonIndex = (row) * 4 + (col-1);  // Rows 1, 2, and 3 have gaps
      }
      
      if (buttonIndex >= 0 && buttonIndex < totalButtons) {
        unsigned long currentTime = millis();
        if (digitalRead(colPins[col]) == LOW) { // If the button is pressed
          if (!keyState[row][col] && (currentTime - lastDebounceTime[row][col] > debounceTime)) {
            keyState[row][col] = true; // Mark the key as pressed
            buttonFunctions[buttonIndex](); // Execute the corresponding macro
            lastDebounceTime[row][col] = currentTime; // Update debounce time
          }
        } else {
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
      volumeUp();  // Increase volume
    } else {
      volumeDown();  // Decrease volume
    }
    oldPosition = newPosition;
  }
}

// Each Macro function
void openNewGoogleTab() {
  BootKeyboard.press(KEY_LEFT_CTRL);
  BootKeyboard.press('t');
  delay(100);
  BootKeyboard.releaseAll();
  delay(500);
  
  BootKeyboard.print("https://www.google.com");
  BootKeyboard.press(KEY_RETURN);
  BootKeyboard.releaseAll();
}

void openSpotify() {
  BootKeyboard.press(KEY_LEFT_GUI);
  delay(100);
  BootKeyboard.releaseAll();
  delay(200);

  BootKeyboard.print("Spotify");
  delay(200);

  BootKeyboard.press(KEY_RETURN);
  BootKeyboard.releaseAll();
}

void putComputerToSleep() {
  BootKeyboard.press(KEY_LEFT_GUI);
  BootKeyboard.press('x');
  delay(100);
  BootKeyboard.releaseAll();
  delay(500);
  BootKeyboard.press('u');
  delay(100);
  BootKeyboard.press('s');
  BootKeyboard.releaseAll();
}

void micOnOff() {
  BootKeyboard.press(KEY_LEFT_GUI);
  BootKeyboard.press(KEY_LEFT_ALT);
  BootKeyboard.press('k');
  delay(100);
  BootKeyboard.releaseAll();
}

void minimizeWindow() {
  BootKeyboard.press(KEY_LEFT_GUI);
  BootKeyboard.press(KEY_DOWN_ARROW);
  delay(100);
  BootKeyboard.releaseAll();
}

void openMoodle() {
  BootKeyboard.press(KEY_LEFT_GUI);
  delay(100);
  BootKeyboard.releaseAll();
  delay(500);
  
  BootKeyboard.print("Google Chrome");
  delay(200);

  BootKeyboard.press(KEY_RETURN);
  BootKeyboard.releaseAll();
  delay(500);
  
  BootKeyboard.print("https://learning.monash.edu/my/");
  BootKeyboard.press(KEY_RETURN);
  BootKeyboard.releaseAll();
}

void openCalculator() {
  BootKeyboard.press(KEY_LEFT_GUI);
  BootKeyboard.press('r');
  delay(100);
  BootKeyboard.releaseAll();
  delay(500);
  BootKeyboard.print("calc");
  BootKeyboard.press(KEY_RETURN);
  BootKeyboard.releaseAll();
}

void cameraOnOff() {
  BootKeyboard.press(KEY_LEFT_GUI);
  BootKeyboard.press('r');
  delay(100);
  BootKeyboard.releaseAll();
  delay(500);
  BootKeyboard.print("camera");
  BootKeyboard.press(KEY_RETURN);
  BootKeyboard.releaseAll();
}

void closeTab() {
  BootKeyboard.press(KEY_LEFT_CTRL);
  BootKeyboard.press('w');
  delay(100);
  BootKeyboard.releaseAll();
}

void openVScode() {
  BootKeyboard.press(KEY_LEFT_GUI);
  delay(100);
  BootKeyboard.releaseAll();
  delay(400);

  BootKeyboard.print("Visual Studio Code");
  delay(600);

  BootKeyboard.press(KEY_RETURN);
  BootKeyboard.releaseAll();
}

void cntrlShiftT() {
  BootKeyboard.press(KEY_LEFT_CTRL);
  BootKeyboard.press(KEY_LEFT_SHIFT);
  BootKeyboard.press('t');
  delay(100);
  BootKeyboard.releaseAll();
}

void bluetooth() {
  BootKeyboard.press(KEY_LEFT_GUI);
  BootKeyboard.press('a');
  delay(100);
  BootKeyboard.releaseAll();
  delay(500);
  BootKeyboard.press(KEY_RIGHT);
  delay(100);
  BootKeyboard.releaseAll();
  BootKeyboard.press(KEY_RETURN);
  delay(100);
  BootKeyboard.press(KEY_LEFT_GUI);
  BootKeyboard.press('a');
  BootKeyboard.releaseAll();
}

void openTab() {
  BootKeyboard.press(KEY_LEFT_CTRL);
  BootKeyboard.press('t');
  delay(100);
  BootKeyboard.releaseAll();
}

void openDiscord() {
  BootKeyboard.press(KEY_LEFT_GUI);
  delay(100);
  BootKeyboard.releaseAll();
  delay(400);

  BootKeyboard.print("Disco");
  delay(500);

  BootKeyboard.press(KEY_RETURN);
  delay(100);
  BootKeyboard.releaseAll();
}

void screenCapture() {
  BootKeyboard.press(KEY_LEFT_GUI);
  BootKeyboard.press(KEY_LEFT_SHIFT);
  BootKeyboard.press('s');
  delay(100);
  BootKeyboard.releaseAll();
}


void volumeUp() {
  Consumer.write(MEDIA_VOLUME_UP);
}

void volumeDown() {
  Consumer.write(MEDIA_VOLUME_DOWN);
}

void mute() {
  Consumer.write(MEDIA_VOLUME_MUTE);
  BootKeyboard.print("WAWAWEWA");
}

void gap() {
  BootKeyboard.print("WAWAWEWA");
}