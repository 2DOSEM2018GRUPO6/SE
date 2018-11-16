# El programa toma datos vía comunicación serial (Arduino-RBP).
# Los datos fueron generados aleatoriamente en arduino.
import serial
import sys

# Abrimos el puerto del arduino a 9600
PuertoSerie = serial.Serial('/dev/ttyACM0', 9600)

# Bucle sin fin
while True:
  # leemos hasta que encontarmos el final de linea
  sArduino = PuertoSerie.readline()
  # Mostramos el valor leido y eliminamos el salto de linea del final
  print 'Valor Arduino: ' + sArduino.rstrip('\n')
