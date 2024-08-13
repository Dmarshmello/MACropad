/*
 * -----------------------------------------------------------------------------
 * MACropad | MAC x SMEE Workshop
 * 
 * Project: Macros
 * Description: This program defines the MACROPAD layout and its associated 
 *              macros based on the orientation of the device. It monitors user 
 *              input through a matrix of rows and columns, triggering specific 
 *              functions tied to each button. Each function executes a unique 
 *              macro, allowing for customizable keyboard shortcuts and commands.
 * 
 * Author: Ethan Dmello
 * Date: 8/13/2024
 * -----------------------------------------------------------------------------
 */

#include <Arduino.h>
#include <Keyboard.h>
#include <Encoder.h>


/// Switches Implimentation (16)

//Define PCBs matrix
const int totalButtons = 16;
const int numRows = 4;
const int numCols = 5; //includes the rotary

//pin numbers for each row and column
const int rowPins[numRows] = {A3, A2, A1, A0};
const int colPins[numCols] = {5, 6, 7, 8, 9};

//debounce time to prevent multiple triggers
const unsigned long debounceTime = 100; 

//current state of each button
bool keyState[numRows][numCols]; 

//debounce time for each button
unsigned long lastDebounceTime[numRows][numCols];



/// Rotary Implimentation

//define and initialize rotary encoder
#define ENCODER_PIN1 2
#define ENCODER_PIN2 3
Encoder myEnc(ENCODER_PIN1, ENCODER_PIN2);
long oldPosition = -999; //previous position of the encoder



/// Define Macros
void macro1();
void macro2();
void macro3();
void macro4();
void macro5();
void macro6();
void macro7();
void macro8();
void macro9();
void macro10();
void macro11();
void macro12();
void macro13();
void macro14();
void macro15();
void macro16();

/*Button Layout:
 * 
 *   {"4", "8", "12", "16"},
 *   {"3", "7", "11", "15"},
 *   {"2", "6", "10", "14"},
 *   {"1", "5", "9", "13"}
*/

//based on layout arrange macros
void (*buttonFunctions[totalButtons])() = {
    macro4, macro8, macro12, macro16,
    macro3, macro7, macro11, macro15,
    macro2, macro6, macro10, macro4,
    macro1, macro5, macro9, macro13,
};

void setup() {
  ///Initialize LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);

  //Initialize row pins as outputs and set them high
  for (int i = 0; i < numRows; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
    for (int j = 0; j < numCols; j++) {
      keyState[i][j] = false; //Set all key states to not pressed
    }
  }

  //Initialize column pins as inputs with pull-up resistors (read signals)
  for (int i = 0; i < numCols; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }

  //Start the keyboard to send commands
  Keyboard.begin();
}

void loop() {

  //Iterate through each row to check if pressed
  for (int row = 0; row < numRows; row++) {
    digitalWrite(rowPins[row], LOW); // Activate the current row

    //iterate through each column
    for (int col = 0; col < numCols; col++) {
      //first column has no btn as it is the encoder
      if (col == 0 || (row == 3 && col == 0)) continue;
      
      int buttonIndex = -1;

      //button indexing
      if (row == 0) buttonIndex = col - 1;
      if (row == 1) buttonIndex = col + 3;
      if (row == 2) buttonIndex = col + 7;
      if (row == 3) buttonIndex = col + 11;

      //button index is valid
      if (buttonIndex < 0 || buttonIndex >= totalButtons) continue;

      unsigned long currentTime = millis(); //current time
      if (digitalRead(colPins[col]) == LOW) { //if the button is pressed
        
        if (keyState[row][col] == false && (currentTime - lastDebounceTime[row][col] > debounceTime)) {
          
          //make sure multiple keys arent pressed
          bool multipleKeysPressed = false; 
          for (int checkCol = 0; checkCol < numCols; checkCol++) {
            if (checkCol != col && digitalRead(colPins[checkCol]) == LOW) {
              multipleKeysPressed = true;
              break;
            }
          }
          
          //one key is pressed, execute the macro
          if (!multipleKeysPressed) {
            keyState[row][col] = true;

            
            buttonFunctions[buttonIndex](); //Call function

            lastDebounceTime[row][col] = currentTime; //Update debounce time
          }
        }

      } 

      else {
        if (keyState[row][col] == true) { //check if alreadu pressed
          keyState[row][col] = false; //reset state
          delay(100); //delay
        }
      }
    }

    digitalWrite(rowPins[row], HIGH); //deactivatecurrent row
  }

  /// Check the rotary encoder
  long newPosition = myEnc.read() / 4;
  if (newPosition != oldPosition) {
    if (newPosition > oldPosition) { // If turned clockwise
      Keyboard.press(KEY_RIGHT_ARROW);
      delay(100);
      Keyboard.release(KEY_RIGHT_ARROW);

    } else { // If turned counterclockwise
      Keyboard.press(KEY_LEFT_ARROW);
      delay(100);
      Keyboard.release(KEY_LEFT_ARROW);
    }
    oldPosition = newPosition; //upadate position history
  }
}

///Each Macro function
void macro1() {
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

void macro2() {
  // Open GitHub (in a new tab)
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.releaseAll();
  delay(200);

  Keyboard.print("GitHub Desktop");
  delay(200);

  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}

void macro3() {
  // Open Google (in a new tab)
  Keyboard.press(KEY_LEFT_GUI);
  delay(100);
  Keyboard.releaseAll();
  delay(500);

  Keyboard.print("Google Chrome");
  delay(200);

  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('t'); // Open new tab in browser
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("https://www.google.com");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void macro4() {
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


void macro5() {
  // Open new tab (Ctrl+T)
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('t');
  delay(100);
  Keyboard.releaseAll();
}

void macro6() {
  // Open screenshot tool (Windows + Shift + S)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press('s');
  delay(100);
  Keyboard.releaseAll();
}

void macro7() {
  // Minimize all windows (Windows + D)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('d');
  delay(100);
  Keyboard.releaseAll();
}

void macro8() {
  // Open File Explorer
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('e');
  delay(100);
  Keyboard.releaseAll();
}

void macro9() {
  // Open Command Prompt (cmd)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r'); // Open Run dialog
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("cmd");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void macro10() {
  // Open specific folder (e.g., "Files")
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('e'); // Open File Explorer
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("Files"); // Replace "Files" with the actual folder name
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void macro11() {
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

void macro12() {
  // Mute system volume (assuming F3 mutes)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_F3); 
  delay(100);
  Keyboard.releaseAll();
}

void macro13() {
  // Turn off camera (this can vary based on system, usually done via software)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r'); // Open Run dialog
  delay(100);
  Keyboard.releaseAll();
  delay(500);
  Keyboard.print("camera"); // Example command, may need adjustment
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void macro14() {
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

void macro15() {
  // Lock the computer (Windows + L)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('l');
  delay(100);
  Keyboard.releaseAll();
}


void macro16() {
  // Lock the computer (Windows + L)
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('l');
  delay(100);
  Keyboard.releaseAll();
}
