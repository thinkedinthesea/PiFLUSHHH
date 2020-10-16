#!/usr/bin/python
#
#	*************
#       * POWERMYPI *
#       *************
#        _____________________
#       |                     |
#     	|   THINKEDINTHESEA   |
#       |_____________________|
#
#
import RPi.GPIO as GPIO
import time
import os
#
GPIO.setmode(GPIO.BOARD)
# SR imput
GPIO.setup(12, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)
# WD output
GPIO.setup(11, GPIO.OUT)
#
tempo = 0
poweroff = 0
# start program, make WD HIGH
GPIO.output(11, True)
while True:
    if (GPIO.input(12) == True):
        tempo = time.time()
        while (time.time() < tempo + 2):
            if (GPIO.input(12) == True):
                poweroff = 1
        if (poweroff == 1):
            os.system("sudo poweroff")
            break
        if (poweroff == 0):
            os.system("sudo reboot")
            break
    time.sleep(0.1)
