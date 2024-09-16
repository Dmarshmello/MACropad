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
*/

void initLayer2(void (*buttonFunctions[16])()) {
    buttonFunctions[0] = MAC;
    buttonFunctions[1] = MAC;
    buttonFunctions[2] = MAC;

    buttonFunctions[4] = MAC;
    buttonFunctions[5] = MAC;
    buttonFunctions[6] = MAC;

    buttonFunctions[8] = MAC;
    buttonFunctions[9] = MAC;
    buttonFunctions[10] = MAC;

    buttonFunctions[12] = MAC;
    buttonFunctions[13] = MAC;
    buttonFunctions[14] = MAC;
    buttonFunctions[15] = MAC;
}
