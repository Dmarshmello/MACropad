#include "macrosDefinitions.h"

/*Button Layout based on orientation of your board:
 *                
 *   {(promicro)   "0",     "1",    "2",     "layer 0"},
 *   {             "4",     "5",    "6",     "layer 1"},
 *   {             "8",     "9",    "10",    "11 or layer 2"},
 *   {(12 rotary)  "13",    "14",   "15",    "16 or layer 3"}
 *        ^         ^        ^        ^       ^
 *       row0     row1      row2     row3    row4
 * 
*/

void initLayer1(void (*buttonFunctions[16])()) {
    buttonFunctions[0] = MAC;
    buttonFunctions[1] = MAC;
    buttonFunctions[2] = MAC;

    buttonFunctions[4] = MAC;
    buttonFunctions[5] = MAC;
    buttonFunctions[6] = MAC;
    buttonFunctions[7] = MAC;

    buttonFunctions[8] = rewind;
    buttonFunctions[9] = MAC;
    buttonFunctions[10] = MAC;
    buttonFunctions[11] = fastForward;

    buttonFunctions[12] = mute;
    buttonFunctions[13] = stop;
    buttonFunctions[14] = previousSong;
    buttonFunctions[15] = playPause;
    buttonFunctions[16] = nextSong;
}
