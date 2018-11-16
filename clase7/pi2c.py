# El programa toma datos vía comunicación i2c (Arduino-RBP).
# Los datos fueron generados aleatoriamente en arduino.
import smbus
import sys
import time

bus = smbus.SMBus(1)

# Dirección seleccionada para el programa de arduino.
address = 0x08

def readNumber():
	number = bus.read_byte(address)
	return number
i=0
# Adquisición de 50 datos.
while i<50:
	number = readNumber()
	print "Valor Arduino: ", number
	time.sleep(0.2)
	i=i+1
