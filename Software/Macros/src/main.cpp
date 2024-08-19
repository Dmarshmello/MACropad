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
#include <Keyboard.h>
#include <Encoder.h>

/// Switch Implementation (16)

// Define PCB matrix 4x4 btns
const int totalButtons = 16;
const int numRows = 4;
const int numCols = 5;            // includes the rotary
bool keyState[numRows][numCols];  //state of each btn, pressed or not

// ProMicro pin numbers for each row and column
const int rowPins[numRows] = {A3, A2, A1, A0};
const int colPins[numCols] = {5, 6, 7, 8, 9};

// Debounce time to prevent multiple triggers
const unsigned long debounceTime = 100; 
unsigned long lastDebounceTime[numRows][numCols]; //time for each button


/// Rotary Implementation

// Define and initialize rotary encoder
#define ENCODER_PIN1 2
#define ENCODER_PIN2 3
Encoder myEnc(ENCODER_PIN1, ENCODER_PIN2);
long oldPosition = -999; //initial position of the encoder


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
void mute();

/*Button Layout based on orientation of your board:
 * I decided vertical so the microcontroller sits at the top so my numbering is
 *                
 *   {(promicro)   "3",    "7",   "11",   "15"},
 *   {             "2",    "6",   "10",   "14"},
 *   {             "1",    "5",   "9",    "13"},
 *   {( rotary)    "0",    "4",   "8",    "12"}
 *                  ^       ^      ^        ^
 *                 row0    row1   row2    row3
 * 
 * Now arrange your functions in the layout you want, remmber that the board was wired 
 * horizontally which is why my functions are organised based on numbering above 
*/

void (*buttonFunctions[totalButtons])() = {
    openNewGoogleTab,   openSpotify,      putComputerToSleep,   micOnOff,        
    minimizeWindow,     openMoodle,       openCalculator,       cameraOnOff,        
    closeTab,           openVScode,       cntrlShiftT,          bluetooth,
    openTab,            openDiscord,      screenCapture,        mute           
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
  Keyboard.begin();
}

void loop() {
  // Iterate through each row to check if any button is pressed
  for (int row = 0; row < numRows; row++) {
    digitalWrite(rowPins[row], LOW); // Activate the current row

    // Iterate through each column in the current row
    for (int col = 1; col < numCols; col++) { // Start from col=1 because col=0 is the encoder
      int buttonIndex = row * 4 + (col - 1); // Simplified calculation

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
}


// Each Macro function
void openNewGoogleTab() {
  // Open a new Google tab in the browser
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  
  Keyboard.print("https://www.google.com");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void openSpotify() {
  // Open Spotify
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.releaseAll();
  delay(200);

  Keyboard.print("Spotify");
  delay(200);

  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}

void putComputerToSleep() {
  // Put computer to sleep (Windows + X, U, S)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('x');
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.press('u');
  delay(100);
  Keyboard.press('s');
  Keyboard.releaseAll();
}

void micOnOff() {
  // Toggle microphone on/off (Windows + Alt + K)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('k');
  delay(100);
  Keyboard.releaseAll();
}


void minimizeWindow() {
  // Minimize the current window (Windows + Down Arrow)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_DOWN_ARROW);
  delay(100);
  Keyboard.releaseAll();
}

void openMoodle() {
  // Open Moodle in the browser
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  
  Keyboard.print("Google Chrome");
  delay(200);

  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  
  Keyboard.print("https://learning.monash.edu/my/"); // Replace with the actual URL
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void openCalculator() {
  // Open Calculator
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r'); // Open Run dialog
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("calc");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void cameraOnOff() {
  // Toggle camera on/off (This can vary based on the system, usually done via software)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r'); // Open Run dialog
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("camera"); // Example command, may need adjustment
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void closeTab() {
  // Close the current tab (Ctrl+W)
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('w');
  delay(100);
  Keyboard.releaseAll();
}

void openVScode() {
  // Open Visual Studio Code
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.releaseAll();
  delay(500);

  Keyboard.print("Visual Studio Code");
  delay(1000);

  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}

void cntrlShiftT() {
  // Reopen the last closed tab (Ctrl+Shift+T)
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();
}

void turnOnBluetooth() {
  // Turn on Bluetooth (Windows + A to open Action Center, then toggle)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('a');
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  // Tab through options to get to the Bluetooth toggle
  for (int i = 0; i < 2; i++) {
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.releaseAll();
    delay(100);
  }
  Keyboard.press(KEY_RETURN); // Toggle Bluetooth
  delay(100);
  Keyboard.releaseAll();
}

void openTab() {
  // Open a new browser tab (Ctrl+T)
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();
}

void openDiscord() {
  // Open Discord
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.releaseAll();
  delay(200);

  Keyboard.print("Discord");
  delay(200);

  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}

void screenCapture() {
  // Screen capture (Windows + Shift + S)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('s');
  delay(100);
  Keyboard.releaseAll();
}

void bluetooth() {
  // Turn on Bluetooth (Windows + A to open Action Center, then toggle)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('a');
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  
  // Navigate to the Bluetooth toggle in Action Center
  // This may vary depending on the order of items in the Action Center
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RIGHT_ARROW);
  delay(100);
  Keyboard.releaseAll();
  delay(100);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}


void mute() {
  // Mute system volume (Assuming F3 mutes)
  Keyboard.press(KEY_F3); 
  delay(100);
  Keyboard.releaseAll();
}


