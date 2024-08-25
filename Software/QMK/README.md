# MACropad Firmware Flashing Guide

Follow these steps to flash your MACropad using QMK firmware.

## Flashing Process

1. **Install QMK Toolbox**:
   - Download and install QMK Toolbox from the [GitHub repository](https://github.com/qmk/qmk_toolbox).

2. **Configure Your Layout**:
   - Go to the [QMK Configurator](https://config.qmk.fm/#/merge/uc1/LAYOUT).
   - Select your board: `dumbpad/v1x`.
   - Name your new layout.

3. **Assign Functions**:
   - In the visual representation of your board, select each key.
   - Choose the desired function from the menu below.

4. **Compile and Download Firmware**:
   - Click the **Compile** button at the top right of the Configurator.
   - Wait for the potato to bake.
   - You can then download the firmware, click **Firmware** from below the terminal on the right.

5. **Flash Your MACropad**:
   - Open QMK Toolbox.
   - Ensure the MCU is set to **ATmega32U4** in the top right corner of QMK Toolbox.
   - Locate and open the firmware file you downloaded (usually found in your `Downloads` folder).
    **It should have a ".hex" file type**

6. **Prepare Your MACropad**:
   - Press and hold the **Reset** button on your MACropad for 3 seconds.
   - You should see "Device Connected" in yellow text on the QMK Toolbox screen.
   - Click the **Flash** button in QMK Toolbox.

   The board will flash and disconnect automatically. The board only stays in flashing mode for 5 seconds after you press **Reset**.

## Helpful Links

- [QMK Configurator Tutorial](https://www.youtube.com/watch?v=-imgglzDMdY)
- [QMK Toolbox Overview](https://www.youtube.com/watch?v=fuBJbdCFF0Q)

## Troubleshooting

- If the board doesn't show up in QMK Toolbox, ensure you are holding the **Reset** button long enough.
- Make sure to download the correct firmware file for your specific layout.

Enjoy customizing your MACropad!
