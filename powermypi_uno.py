#!/usr/bin/python
#
#POWERMYPI - UNO
#THINKEDINTHESEA
#
#rev2 - 191020
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
GPIO.output(11, True)
while True:
  if (GPIO.input(12) == True):
    time.sleep(2)
    if (GPIO.input(12) == True):
      os.system("sudo poweroff")
      break
    else:
      os.system("sudo reboot")
      break
  time.sleep(0.1)
