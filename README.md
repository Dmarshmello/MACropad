<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1>Macropad - MAC x SMEE</h1>

<p>This project involves building a 4x4 switch macropad with a rotary encoder and a single button. It was developed for the Monash Association of Coding (MAC) Macropad Workshop.</p>

<div style="display: flex; margin-bottom: 30px;">
    <img src="images/mat.jpg" alt="Diode Orientation" style="width:350px; margin-right: 10px;">
    <img src="images/closeup.jpg" alt="Diode Orientation" style="width:350px; margin-right: 10px;">
</div>

<h2>Software</h2>

<p>Instructions on programming the MACROPAD can be found in the Software section. This contains a debugging directory as well as an example macro directory.</p>

<h2>Hardware</h2>

<h3>Components Used:</h3>
<ul>
    <li><strong>Microcontroller:</strong> Pro Micro Atmega32U4 5V</li>
    <li><strong>Rotary Encoder:</strong> EC11 Rotary Encoder</li>
    <li><strong>Macropad Kit:</strong> Dumpad-V2 Kit
        <ul>
            <li>Macropad PCB</li>
            <li>IN4148 Diode x 17</li>
            <li>6x6x4.5mm PCB Push Button Switch 4 Pin DIP</li>
        </ul>
    </li>
    <li><strong>Switches:</strong> 5-Pin Switches x 16</li>
    <li><strong>Keycaps:</strong> 16 keycaps</li>
    <li><strong>Enclosure:</strong> 3D Printed Case and Rotary Cap</li>
</ul>

<img src="images/AllParts.jpg" alt="All Parts" style="width:500px; margin-bottom: 30px;">

<h3>Suppliers:</h3>
<table>
    <tr>
        <th>Component</th>
        <th>Supplier</th>
        <th>Store URL</th>
    </tr>
    <tr>
        <td><strong>Macropad Kit & Components</strong></td>
        <td>customKBD</td>
        <td><a href="https://customkbd.com/">https://customkbd.com/</a></td>
    </tr>
    <tr>
        <td><strong>Switches and Keycaps</strong></td>
        <td>Idyllic</td>
        <td><a href="https://mechstock.com.au/">https://mechstock.com.au/</a></td>
    </tr>
    <tr>
        <td></td>
        <td>CAFEGE</td>
        <td><a href="https://cafege.com.au/">https://cafege.com.au/</a></td>
    </tr>
</table>

<p><strong>Keyboard Maintainer:</strong> imchipwood<br>
   <a href="https://github.com/imchipwood/dumbpad">https://github.com/imchipwood/dumbpad</a>
</p>

<p><strong>Special Thanks:</strong> customKBD for all the help<br>
   <a href="https://github.com/customkbd/Dumbpad/tree/main/source">https://github.com/customkbd/Dumbpad/tree/main/source</a>
</p>


<h1>Build Guide</h1>

<h2>1. Solder the Diodes</h2>

<h3>Insert the Diodes</h3>
<ul>
    <li>Feed the diodes through their designated holes on the PCB.</li>
    <li>Ensure that the diodes are oriented correctly; the PCB shows the direction with a line that should match up with the line on the diode.</li>
</ul>

<div style="display: flex; margin-bottom: 30px;">
    <img src="images/DioOrientation.jpg" alt="Diode Orientation" style="width:300px; margin-right: 10px;">
    <img src="images/FeedDiodes.jpg" alt="Feeding Diodes" style="width:450px;">
</div>

<h3>Bend and Solder the Legs</h3>
<ul>
    <li>Flip the board over and bend the diode legs to hold them in place.</li>
    <li>Solder all 17 diode legs from the same side.</li>
</ul>

<img src="images/BendDiodes.jpg" alt="Bending Diodes" style="width:450px; margin-bottom: 30px;">

<ul>
    <li>Carefully trim down the legs.</li>
    <li><strong>Warning:</strong> Hold the leg with one hand while snipping to prevent it from flying.</li>
</ul>

<img src="images/CutDiodes.jpg" alt="Cut Diodes" style="width:450px; margin-bottom: 30px;">

<h2>2. Install the Microcontroller</h2>

<h3>Prepare the Microcontroller</h3>
<ul>
    <li>With the PCB face up and the MAC logo visible, insert the long legs of the microcontroller pins through the dedicated holes.</li>
</ul>

<img src="images/TopLongPins.jpg" alt="Feeding Long Pins" style="width:450px; margin-bottom: 30px;">

<h3>Solder the Microcontroller</h3>
<ul>
    <li>Place the microcontroller on top of the pins to hold them in place.</li>
    <li>Flip the board over while holding the pins and microcontroller in place.</li>
    <li>Solder all four corners first, then continue by soldering the remaining pins.</li>
</ul>

<div style="display: flex; margin-bottom: 30px;">
  <img src="images/SolderCorner.jpg" alt="Soldering Corners" style="width:400px; margin-right: 10px;">
  <img src="images/SolderPins.jpg" alt="Soldering Pins" style="width:400px;">
</div>

<ul>
    <li>Trim down the legs.</li>
    <li><strong>Warning:</strong> These legs are thicker and may fly when cut, so cover them with your hand or use a book or paper to shield yourself.</li>
</ul>

<div style="display: flex; margin-bottom: 30px;">
    <img src="images/CutMicro.jpg" alt="Cut legs" style="width:520px; margin-right: 10px;">
    <img src="images/Covercut.jpg" alt="Cover and cut" style="width:250px;">
</div>

<h3>Soldering Top of PCB</h3>
<ul>
    <li>Turn the board back over and solder the remaining pins.</li>
</ul>

<img src="images/ProMicro.jpg" alt="Pro Micro Installed" style="width:450px; margin-bottom: 30px;">

<h2>3. Attach the Push Button</h2>

<h3>Insert the Button</h3>
<ul>
    <li>Place the push button into the dedicated holes on the PCB.</li>
    <li>The button should slide in easily, and its orientation should match the image provided.</li>
</ul>

<img src="images/Button.jpg" alt="Button Placement" style="width:350px; margin-bottom: 30px;">

<h3>Solder the Button</h3>
<ul>
    <li>Flip the board over and solder the button's pins.</li>
</ul>

<img src="images/ButtonSolder.jpg" alt="Button Soldered" style="width:350px; margin-bottom: 30px;">

<h2>4. Install the Rotary Encoder</h2>

<p>As the rotary encoder does not fit flush on top of your PCB, follow these steps:</p>

<div style="display: flex; margin-bottom: 30px;">
    <img src="images/rotaryboard.jpg" alt="Rotary Encoder Board" style="width:285px; margin-right: 10px;">
    <img src="images/RotaryNotFit.jpg" alt="Rotary Encoder Not Fit" style="width:400px;">
</div>

<h3>Modify the Rotary Encoder</h3>
<ul>
    <li>Bend the side tabs away from the encoder.</li>
</ul>

<div style="display: flex; margin-bottom: 30px;">
    <img src="images/BendRotary.jpg" alt="Bend Rotary Encoder" style="width:415px; margin-right: 10px;">
    <img src="images/NormVsBent.jpg" alt="Normal vs Bent" style="width:300px;">
</div>

<ul>
    <li>Cut off the side tabs while holding them away from your face and covering them.</li>
</ul>

<div style="display: flex; margin-bottom: 30px;">
    <img src="images/RotaryCut.jpg" alt="Cut Rotary Tabs" style="width:310px; margin-right: 10px;">
    <img src="images/CutPcb.jpg" alt="Cut PCB" style="width:300px;">
</div>

<h3>Solder the Rotary Encoder</h3>
<ul>
    <li>Turn over the board and solder your rotary encoder via the 5 pins: 3 small and 2 regular, opposite each other.</li>
</ul>

<img src="images/SolderRotary.jpg" alt="Solder Rotary Encoder" style="width:450px; margin-bottom: 30px;">

<h2>5. Fit Your Case</h2>

<ul>
    <li>Place your board within your 3D printed case, and screw it down with 4 Torx screws.</li>
</ul>

<div style="display: flex; margin-bottom: 30px;">
    <img src="images/CasePcb.jpg" alt="Case and PCB" style="width:350px; margin-right: 10px;">
    <img src="images/ScrewedPcb.jpg" alt="Screwed PCB" style="width:300px;">
</div>

<h2>6. Attach the Keycaps</h2>

<ul>
    <li>Place your keycaps and rotary encoder cap on your macropad.</li>
</ul>

<div style="display: flex; margin-bottom: 30px;">
    <img src="images/FinishedMacropad.jpg" alt="Finished Macropad" style="width:330px; margin-right: 10px;">
    <img src="images/Finished2.0.jpg" alt="Finished Macropad 2.0" style="width:250px;">
</div>

<h1>CONGRATULATIONS!!!</h1>

<p><strong>Created by:</strong> Ethan Dmello</p>

<p style="display: flex; align-items: center;">
  <img src="images/monashcoding_logo.jpg" alt="MAC Logo" width="20" style="margin-right: 10px;">
  <span style="font-size: 24px; font-weight: bold;">Monash Association of Coding (MAC)</span>
</p>

<h3>Connect with Us</h3>

<div style="display: flex; justify-content: center; align-items: center; gap: 20px;">
  <a href="https://www.monashcoding.com" target="_blank" style="text-decoration: none; border: none;">
    <img src="images/globe-solid.svg" alt="Website" style="width:20px;">
  </a>
  <a href="https://www.instagram.com/monashcoding/" target="_blank" style="text-decoration: none; border: none;">
    <img src="images/instagram-brands-solid.svg" alt="Instagram" style="width:20px;">
  </a>
  <a href="http://monash.club/discord" target="_blank" style="text-decoration: none; border: none;">
    <img src="images/discord-brands-solid.svg" alt="Discord" style="width:20px;">
  </a>
  <a href="https://www.linkedin.com/company/monashcoding" target="_blank" style="text-decoration: none; border: none;">
    <img src="images/linkedin-brands-solid.svg" alt="LinkedIn" style="width:20px;">
  </a>
</div>

</body>
</html>
