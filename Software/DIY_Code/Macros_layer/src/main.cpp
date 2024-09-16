/*
 * ------------------------------
 * MACropad | MAC x SMEE Workshop
 * 
 * Project: Macros_layer
 * Description: This program extends off the original Macros project but enables multiple layers,
 *              i have defaulted it to 2 layers however users can activate the other 2. Each layer
 *              has a corresponding .h file to define each buttons functionality.
 * 
 * Author: Ethan Dmello
 * Date: 9/11/2024
 * --------------------------------
 */


#include <Arduino.h>
#include <Encoder.h>
#include <HID-Project.h>
#include "macrosDefinitions.h"

//import the layers
#include "layers/layer0.h"
#include "layers/layer1.h"
#include "layers/layer2.h"
#include "layers/layer3.h"

const int totalButtons = 17;
int currentLayer = 0;

const int numRows = 4;
const int numCols = 5;
bool keyState[numRows][numCols];
unsigned long debounceTime = 100;
unsigned long lastDebounceTime[numRows][numCols];

const int rowPins[numRows] = {A3, A2, A1, A0};
const int colPins[numCols] = {5, 6, 7, 8, 9};
#define ENCODER_PIN1 16
#define ENCODER_PIN2 4

// Define rotary encoder
Encoder myEnc(ENCODER_PIN1, ENCODER_PIN2);
long oldPosition = -999;

void (*buttonFunctions[totalButtons])();

// Function to handle layer switching
void handleLayerSwitch(int buttonIndex) {
    switch (buttonIndex) {
        case 3:  // Button 3 switches to Layer 0
            currentLayer = 0;
            initLayer0(buttonFunctions);
            break;
        case 7:  // Button 7 switches to Layer 1
            currentLayer = 1;
            initLayer1(buttonFunctions);
            break;
        case 11: // Button 11 switches to Layer 2
            currentLayer = 2;
            initLayer2(buttonFunctions);
            break;
        case 15: // Button 15 switches to Layer 3
            currentLayer = 3;
            initLayer3(buttonFunctions);
            break;
    }
}

void setup() {
    for (int i = 0; i < numRows; i++) {
        pinMode(rowPins[i], OUTPUT);
        digitalWrite(rowPins[i], HIGH);
    }

    for (int i = 0; i < numCols; i++) {
        pinMode(colPins[i], INPUT_PULLUP);
    }

    memset(keyState, false, sizeof(keyState));

    BootKeyboard.begin();
    Consumer.begin();

    // Initialize layer 0 at startup
    initLayer0(buttonFunctions);
}

void loop() {
    // Handle rotary encoder for volume control
    long newPosition = myEnc.read() / 4;
    if (newPosition != oldPosition) {
        if (newPosition > oldPosition) {
            // Volume up
            Consumer.write(MEDIA_VOLUME_UP);
        } else {
            // Volume down
            Consumer.write(MEDIA_VOLUME_DOWN);
        }
        oldPosition = newPosition;
    }

    for (int row = 0; row < numRows; row++) {
        digitalWrite(rowPins[row], LOW);  // Activate the current row

        for (int col = 0; col < numCols; col++) {
            int buttonIndex;
            if (row == 3) {
                buttonIndex = 12 + col;  // Row 4 has no gap
            } else {
                buttonIndex = (row) * 4 + (col-1);  // Rows 1, 2, and 3 have gaps
            }

            if (buttonIndex >= 0 && buttonIndex < totalButtons) {
                unsigned long currentTime = millis();
                if (digitalRead(colPins[col]) == LOW) {  // Button pressed
                    if (!keyState[row][col] && (currentTime - lastDebounceTime[row][col] > debounceTime)) {
                        keyState[row][col] = true;  // Mark the key as pressed

                        // Handle layer switching for buttons 3, 7

                // to activate layers 3 and 4 delete this        vvvvvv   ") {//"
                        if (buttonIndex == 3 || buttonIndex == 7 ) { // || buttonIndex == 11 || buttonIndex == 16) {
                            handleLayerSwitch(buttonIndex);  // Switch between layers
                            
                        } else {
                            // Execute the corresponding macro for the current layer
                            buttonFunctions[buttonIndex]();
                        }

                        lastDebounceTime[row][col] = currentTime;  // Update debounce time
                    }
                } else {
                    keyState[row][col] = false;  // Reset the key state when button is released
                }
            }
        }

        digitalWrite(rowPins[row], HIGH);  // Deactivate the current row
    }
}
