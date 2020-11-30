# FLUSHHH
Add-on board for Raspberry Pi. PWM regulated Fan, WS2812b RGB led and Power/Reboot Switch.
FLUSHHH is the all-in-one solution for the Raspberry Pi family.
<br>
<br>
<p align="center"><img src="https://github.com/thinkedinthesea/FLUSHHH/raw/main/img/front.jpg" width="400">
<img src="https://github.com/thinkedinthesea/FLUSHHH/raw/main/img/rear.jpg" width="380"></p>
<br>
- PWM regulated fan based on CPU temperature<br>
Many cases for Raspberry Pi comes with fan in order to help cooling the CPU. But these fans are always on, and usually pretty noisy. FLUSHHH regulate the fan speed based on CPU temperature using little python script.
<br>
<br>
- WS2812B RGB LED<br>
Very cool multi coloured light. Useful for adding visual signals or show some fancy styles visualization. Connected to Raspberry Pi GPIO pin 12 (BCM18 PWM0) and controlled by a little python script fully customizable.
<br>
<br>
- Power On/Off and Reboot switch<br>
Its main feature is to control the power supply of the Raspberry Pi, providing a switch for Power On / Off and Reboot operations. An ATTINY85 programmed in ARDUINO manages vitality signals with Raspberry Pi.<br>
Just plug your micro-USB power supply into the micro-B connector of FLUSHHH, press the switch to power on the Raspberry Pi. Once started:<br/
- pressure < 3 secs, reboot<br>
- pressure > 3 secs, shutdown<br>
In addiction, once installed the python script, FLUSHHH is able to check if a restart or shutdown has been commanded from Raspberry Pi and operates accordingly.
<br>
<br>
<p align="center"><img src="https://github.com/thinkedinthesea/FLUSHHH/raw/main/img/complete.jpg" width="650"></p>
<br>
<br>
<br>
