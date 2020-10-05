#!/usr/bin/python
#
#	      *************
#       * PiFLUSHHH *
#       *************
#        _____________________
#       |                     |
#     	|   THINKEDINTHESEA   |
#       |_____________________|
#
#
#python3 temp.py -l <y/n> -s <seconds>
#-l log save to log yes/no
#-t scantime in seconds
#-f temp for fan activation
#
import os
import time
from datetime import datetime
import sys, argparse
import RPi.GPIO as GPIO
#
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(13, GPIO.OUT)
#
def getOptions(args=sys.argv[1:]):
    parser = argparse.ArgumentParser(description="Check for CPU Temp. Defaults no log, time 60 and temp 46.")
    parser.add_argument("-l", "--log", help="y/n to save log.")
    parser.add_argument("-t", "--time", help="Seconds to scan for temp.")
    parser.add_argument("-f", "--fan", help="Max temp for FAN activation.")
    options = parser.parse_args(args)
    return options
#
options = getOptions(sys.argv[1:])
#print(options.log)
#print(options.fan)
if not options.time:
        options.time = "60"
if not options.fan:
        options.fan = "46"
#
def measure_temp():
        temp = os.popen("vcgencmd measure_temp").readline()
        #temp2 = temp.replace("'C","")
        return (temp.replace("temp=",""))
#
def write_log():
        logg = open("temp.log", "a")
        now = datetime.now()
        dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
        logg.write(dt_string + ";" + measure_temp())
        logg.close()
#
def fan_activation():
        ffan = measure_temp()
        ffan = ffan.replace("\n","")
        if (float(ffan.replace("'C","")) > float(options.fan)):
          GPIO.output(13, True)
        if (float(ffan.replace("'C","")) < float(options.fan)):
          GPIO.output(13, False)
#
while True:
      if (options.log == "y"):
        write_log()
      fan_activation()
      time.sleep(int(options.time))
