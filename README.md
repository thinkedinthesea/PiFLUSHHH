# FLUSHHH
Add-on board for Raspberry Pi. PWM regulated Fan, WS2812b RGB led and Power/Reboot Switch.<br>
FLUSHHH is the all-in-one solution for the Raspberry Pi family.
<br>
<br>
<p align="center"><img src="https://github.com/thinkedinthesea/FLUSHHH/raw/main/img/front.jpg" width="400">
<img src="https://github.com/thinkedinthesea/FLUSHHH/raw/main/img/rear.jpg" width="385"></p>
<br>
<p><strong>- PWM regulated fan based on CPU temperature</strong></p>
Many cases for Raspberry Pi comes with fan in order to help cooling the CPU. But these fans are always on, and usually pretty noisy. FLUSHHH regulate the fan speed based on CPU temperature using little python script.
<br>
<br>
<p><strong>- WS2812B RGB LED</strong></p>
Very cool multi coloured light. Useful for adding visual signals or show some fancy styles visualization. Connected to Raspberry Pi GPIO pin 12 (BCM18 PWM0) and controlled by a little python script fully customizable.
<br>
<br>
<p><strong>- Power On/Off and Reboot switch</strong></p>
Its main feature is to control the power supply of the Raspberry Pi, providing a switch for Power On / Off and Reboot operations. An ATTINY85 programmed in ARDUINO manages vitality signals with Raspberry Pi.<br>
Just plug your micro-USB power supply into the micro-B connector of FLUSHHH, press the switch to power on the Raspberry Pi. Once started:<br/>
- pressure < 3 secs, reboot<br>
- pressure > 3 secs, shutdown<br>
In addiction, once installed the python script, FLUSHHH is able to check if a restart or shutdown has been commanded from Raspberry Pi and operates accordingly.
<br>
<br>
<br>
<p align="center"><img src="https://github.com/thinkedinthesea/FLUSHHH/raw/main/img/info_front.jpg" width="500">
<img src="https://github.com/thinkedinthesea/FLUSHHH/raw/main/img/info_rear.jpg" width="440"></p>
<br>
<br>
<p align="center"><img src="https://github.com/thinkedinthesea/FLUSHHH/raw/main/img/complete.jpg" width="500">
<img src="https://github.com/thinkedinthesea/FLUSHHH/raw/main/img/usb_small.jpg" width="400"></p>
<br>
<br>
<h1>INSTALL</h1>
Open a terminal on your RPi:<br>
<pre><code>// Some comments
cd /home/pi
line 2 of code
line 3 of code
</code></pre>
