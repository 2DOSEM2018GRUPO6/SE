import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setup(15, GPIO.IN)


while True:
   if GPIO.input(15):
		print("Pressed")
		time.sleep(0.2)
   else:
		print("Released")
		time.sleep(0.2)

