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
 * Date: 8/21/2024
 * --------------------------------
 */

#include <Arduino.h>
#include <Encoder.h>
#include <HID-Project.h>

#include "PhoneMacros.h"
#include "LaptopMacros.h"
#include "EditingMacros.h"

const int totalButtons = 16;
const int numRows = 4;
const int numCols = 5;
bool keyState[numRows][numCols];
const int rowPins[numRows] = {A3, A2, A1, A0};
const int colPins[numCols] = {5, 6, 7, 8, 9};
const unsigned long debounceTime = 100;
unsigned long lastDebounceTime[numRows][numCols];

#define NUM_LAYERS 3
int currentLayer = 0;

Encoder myEnc(16, 4);
long oldPosition = -999;

void (*buttonFunctions[totalButtons])() = {
    4,   openSpotify,      putComputerToSleep,   micOnOff,        
    3,     openMoodle,       openCalculator,       cameraOnOff,        
    2,           6,       cntrlShiftT,          bluetooth,
    1,            5,      screenCapture,        mute           
};
};

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(3000);
    digitalWrite(LED_BUILTIN, LOW);

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
}

void loop() {
    checkLayerSwitch();

    for (int row = 0; row < numRows; row++) {
        digitalWrite(rowPins[row], LOW);

        for (int col = 1; col < numCols; col++) {
            int buttonIndex = row * 4 + (col - 1);

            if (buttonIndex >= 0 && buttonIndex < totalButtons) {
                unsigned long currentTime = millis();
                if (digitalRead(colPins[col]) == LOW) {
                    if (!keyState[row][col] && (currentTime - lastDebounceTime[row][col] > debounceTime)) {
                        keyState[row][col] = true;
                        layerFunctions[currentLayer][buttonIndex]();
                        lastDebounceTime[row][col] = currentTime;
                    }
                } else {
                    keyState[row][col] = false;
                }
            }
        }

        digitalWrite(rowPins[row], HIGH);
    }

    long newPosition = myEnc.read() / 4;
    if (newPosition != oldPosition) {
        if (newPosition > oldPosition) {
            volumeUp();
        } else {
            volumeDown();
        }
        oldPosition = newPosition;
    }
}

void checkLayerSwitch() {
    if (digitalRead(colPins[0]) == LOW && digitalRead(rowPins[3]) == LOW) {
        delay(200);
        currentLayer = (currentLayer + 1) % NUM_LAYERS;
    }
}
