# Building Your Macropad Using PlatformIO in Visual Studio Code

This guide provides a step-by-step process to set up and program your Macropad using PlatformIO in Visual Studio Code. Follow these instructions carefully to ensure your project is correctly set up and your code is successfully uploaded to the Pro Micro.

## Requirements

- **Visual Studio Code**: The code editor where you will write, compile, and upload your code.
- **PlatformIO**: An extension for Visual Studio Code that simplifies development for embedded systems like the Pro Micro.

## Installation

### Step 1: Install Visual Studio Code

1. Download and install [Visual Studio Code](https://code.visualstudio.com/).
2. Follow the installation prompts specific to your operating system.

### Step 2: Install PlatformIO

1. Open Visual Studio Code.
2. Click on the Extensions icon in the left sidebar or press `Ctrl+Shift+X`.
3. In the search bar, type "PlatformIO IDE".
4. Click `Install` on the "PlatformIO IDE" extension.

## Steps to Build Your Macropad

### Step 1: Create a New PlatformIO Project

1. Open PlatformIO Home by clicking the extension on the left toolbar.
2. Click on "New Project".
3. **Project Name:** Enter a name for your project, e.g., `MAC Macropad`.
4. **Board:** Select `SparkFun Pro Micro` from the dropdown list.
5. **Framework:** Select `Arduino`.
6. Click `Finish`. PlatformIO will set up the project with the necessary files and directories.

### Step 2: Add the Provided Code

1. In your newly created project, navigate to the `src` folder and open the `main.cpp` file.
2. This is where your boards functunality will be.

### Step 3: Connect the Pro Micro

1. Connect your Pro Micro to your computer using a USB cable.
2. If this is the first time connecting the board, your computer may install some drivers automatically.

### Step 4: Select the Correct COM Port
1. PlatformIO typically detects the correct COM port automatically.

2. If necessary, you can manually specify the correct COM port by modifying your `platformio.ini` file. To do this:

   - Open the **Start Menu** and type `Device Manager`, then press `Enter`.
   - In the **Device Manager** window, expand the section labeled `Ports (COM & LPT)`.
   - Look for a device labeled `USB Serial Device (COMx)` or `SparkFun Pro Micro (COMx)`, where `x` represents the COM port number.
   - Note the COM port number (`COMx`).

### Step 5: Installing Required Libraries

To ensure your macropad functions correctly, you'll need to install the following libraries:

- **paulstoffregen: Encoder@^1.4.4**
- **arduino-libraries: Keyboard**

These libraries provide the necessary functionality for reading the rotary encoder and simulating keyboard inputs.

#### How to Install the Libraries:

To install these libraries, you need to include them in your `platformio.ini` file. Follow these steps:

1. **Open the `platformio.ini` file**:
   - Navigate to the root directory of your PlatformIO project and locate the `platformio.ini` file. Open this file in your code editor.

2. **Add the Required Libraries**:
   - 
   ```ini
   lib_deps = 
       paulstoffregen/Encoder@^1.4.4
       arduino-libraries/Keyboard

   Example:
   ```ini
   [env:sparkfun_promicro16]
   platform = atmelavr
   board = sparkfun_promicro16
   framework = arduino
   lib_deps = 
       paulstoffregen/Encoder@^1.4.4
       arduino-libraries/Keyboard
   upload_port = COMx  ; Replace 'x' with your actual COM port number
    ---

### Step 6: Build and Upload the Code

1. In the PlatformIO toolbar at the bottom of VS Code, click the check mark (Build) icon. This will compile the code.
2. After the code compiles successfully, click the right arrow (Upload) icon to upload the code to your Pro Micro.
3. You should see the LED on the Pro Micro flash for 3 seconds, indicating that the code is running.

### Step 6: Monitor Serial Output (Optional)

1. You can view the debug output by opening the Serial Monitor. In PlatformIO, click on the plug icon in the bottom toolbar (`PlatformIO: Serial Monitor`).
2. Ensure the baud rate is set to `9600`.

### Step 7: Test the Functionality

1. Test the macropad buttons and the rotary encoder to ensure they are functioning as expected.

---

