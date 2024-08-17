# MAC Macropad Workshop - Build Guide

This guide will walk you through building a 4x4 switch macropad with a rotary encoder and a single button. The macropad is powered by a Pro Micro Atmega32U4 5V microcontroller and comes with a 3D printed case and rotary cap.

## Hardware

### Components Used
- **Microcontroller:** Pro Micro Atmega32U4 5V
- **Rotary Encoder:** EC11 Rotary Encoder
- **Macropad Kit:** Dumpad-V2 Kit
- **Macropad PCB**
- **Diodes:** IN4148 Diode x 17
- **Push Button Switch:** 6x6x4.5mm PCB Push Button Switch 4 Pin DIP
- **Switches:** 5-Pin Switches x 16
- **Keycaps:** 16 keycaps
- **Enclosure:** 3D Printed Case and Rotary Cap

![All Parts](Hardware/BuildImages/AllParts.jpg)

## Build Instructions

### 1. Solder the Diodes

#### Insert the Diodes
- Feed the diodes through their designated holes on the PCB. Ensure that the diodes are oriented correctly; the PCB shows the direction with a line that should match up with the line on the diode.

![Diode Orientation](Hardware/BuildImages/DioOrientation.jpg)

![Feeding Diodes](Hardware/BuildImages/FeedDiodes.jpg)

#### Bend and Solder the Legs
- Flip the board over and bend the diode legs to hold them in place.
- Solder all 17 diode legs from the same side.
- Carefully trim down the legs. **Warning:** Hold the leg with one hand while snipping to prevent it from flying.

![Bending Diodes](Hardware/BuildImages/BendDiodes.jpg)

### 2. Install the Microcontroller

#### Prepare the Microcontroller
- With the PCB face up and the MAC logo visible, insert the long legs of the microcontroller pins through the dedicated holes.

![Feeding Long Pins](Hardware/BuildImages/FeedLongPins.jpg)

#### Solder the Microcontroller
- Place the microcontroller on top of the pins to hold them in place.
- Flip the board over while holding the pins and microcontroller in place. Solder all four corners first, then continue by soldering the remaining pins.
- Trim down the legs. **Warning:** These legs are thicker and may fly when cut, so cover them with your hand or use a book or paper to shield yourself.

![Soldering Corners](Hardware/BuildImages/SolderCorner.jpg)

![Soldering Pins](Hardware/BuildImages/SolderPins.jpg)

#### Final Soldering
- Turn the board back over and solder the remaining pins.

![Pro Micro Installed](Hardware/BuildImages/ProMicro.jpg)

### 3. Attach the Push Button

#### Insert the Button
- Place the push button into the dedicated holes on the PCB. The button should slide in easily, and its orientation should match the image provided.

![Button Placement](Hardware/BuildImages/Button.jpg)

#### Solder the Button
- Flip the board over and solder the button's pins.

![Button Soldered](Hardware/BuildImages/ButtonSolder.jpg)
