#include "macrosDefinitions.h"

/*Button Layout based on orientation of your board:
 *                
 *   {(promicro)   "0",     "1",    "2",     "layer 0"},
 *   {             "4",     "5",    "6",     "layer 1"},
 *   {             "8",     "9",    "10",    "layer 2"},
 *   {(12 rotary)  "13",    "14",   "15",    "layer 3"}
 *        ^         ^        ^        ^       ^
 *       row0     row1      row2     row3    row4
 * 
 * Everyday Keyboard
*/

void initLayer0(void (*buttonFunctions[16])()) {
    buttonFunctions[0] = openNewGoogleTab;
    buttonFunctions[1] = openSpotify;
    buttonFunctions[2] = putComputerToSleep;

    buttonFunctions[4] = minimizeWindow;
    buttonFunctions[5] = openMoodle;
    buttonFunctions[6] = openCalculator;
    buttonFunctions[7] = MAC;
    buttonFunctions[8] = closeTab;
    buttonFunctions[9] = openVScode;
    buttonFunctions[10] = cntrlShiftT;
    buttonFunctions[11] = nextSong;
    buttonFunctions[12] = mute;
    buttonFunctions[13] = openDiscord;
    buttonFunctions[14] = openTab;
    buttonFunctions[15] = screenCapture;
}
