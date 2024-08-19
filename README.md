<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1>Macropad - MAC x SMEE</h1>

<p>This project involves building a 4x4 switch macropad with a rotary encoder and a single button. It was developed for the Monash Association of Coding (MAC) Macropad Workshop.

<div style="display: flex; margin-bottom: 30px;">
    <img src="images/mat.jpg" alt="Diode Orientation" style="width:450px; margin-right: 10px;">
    <img src="images/closeup.jpg" alt="Diode Orientation" style="width:450px; margin-right: 10px;">
</div>


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

<h2></h2>


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

<h2></h2>

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
    <img src="images/CutMicro.jpg" alt="Cut legs" style="width:450px; margin-right: 10px;">
    <img src="images/Covercut.jpg" alt="Cover and cut" style="width:250px;">
</div>

<h3>Final Soldering</h3>
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

<img src="images/Button.jpg" alt="Button Placement" style="width:450px; margin-bottom: 30px;">

<h3>Solder the Button</h3>
<ul>
    <li>Flip the board over and solder the button's pins.</li>
</ul>

<img src="images/ButtonSolder.jpg" alt="Button Soldered" style="width:450px; margin-bottom: 30px;">

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
