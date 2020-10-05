#!/usr/bin/python3
#
#THINKEDINTHESEA
#PiFUN
#
#rev041219
#rev081119
#
import time
import board
import neopixel
#classneopixel.NeoPixel(pin, n, *, bpp=3, brightness=1.0, auto_write=True, pixel_order=None)
#brightness (float) – Brightness of the pixels between 0.0 and 1.0 where 1.0 is full brightness
led = neopixel.NeoPixel(board.D18, 1)
#led[0] = (0, 255, 0)
#led.show()
while True:
  led[0] = (0, 255, 0)
  led.show()
  time.sleep(1)
  #
  led[0] = (0, 0, 255)
  led.show()
  time.sleep(1)
  led[0] = (255, 0, 0)
  led.show()
  time.sleep(1)
