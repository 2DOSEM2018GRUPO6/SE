#!/usr/bin/env python

import os
import RPi.GPIO as GPIO
import datetime
import time
import hashlib
from pyfingerprint.pyfingerprint import PyFingerprint
import MySQLdb

global db
global curs
global insertar
global leer

db = MySQLdb.connect("localhost", "root", "eie507", "embebidos")
curs = db.cursor()

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(12, GPIO.OUT)    #Led VERDE
GPIO.setup(11, GPIO.OUT)    #Led ROJO
GPIO.setup(15, GPIO.IN)     #Buscar
GPIO.setup(16, GPIO.IN)     #Agregar
GPIO.setup(18, GPIO.IN)     #Borrar


## Tries to initialize the sensor
try:
    f = PyFingerprint('/dev/ttyAMA0', 57600, 0xFFFFFFFF, 0x00000000)

    if ( f.verifyPassword() == False ):
        raise ValueError('The given fingerprint sensor password is wrong!')

except Exception as e:
    print('El sensor no puede ser iniciado!')
    print('Exception message: ' + str(e))
    exit(1)

## Gets some sensor information
print('Actualmente se han registrado: ' + str(f.getTemplateCount()) +'/'+ str(f.getStorageCapacity()))

curs.execute ("SELECT * FROM huella ORDER BY ID ASC")
print ("\n ID   	Hora		Fecha		Usuario")
print ("===========================================================")
for reading in curs.fetchall():
	print (" "+str(reading[0])+" 	"+str(reading[3])+" 	"+str(reading[2])+" 	"+str(reading[1]))

print("\nPresione un pulsador\n")
while (True):

	if GPIO.input(15):      #BUSCAR HUELLA


			print('\n---------- BUSCAR HUELLA ----------\n') 
				## Tries to search the finger and calculate hash
			try:
				GPIO.output(11, False)
				GPIO.output(12, False)
				print('Posicione su dedo Indice en el sensor...') 
				
				## Wait that finger is read
				while ( f.readImage() == False ):
					pass

				## Converts read image to characteristics and stores it in charbuffer 1
				f.convertImage(0x01)

				## Searchs template
				result = f.searchTemplate()

				positionNumber = result[0]
				accuracyScore = result[1]

				if ( positionNumber == -1 ):
					print('Huella no registrada... \n')
					GPIO.output(11, True)
					time.sleep(2)
					GPIO.output(11, False)

				else:
					print('Huella encontrada en la posicion #' + str(positionNumber))
					posicion = positionNumber
					sqlpos = "SELECT * FROM huella WHERE ID = '%s'" %posicion
					curs.execute(sqlpos)
					result = curs.fetchall()
					for reading in result:
						print("Bienvenido "+reading[1]+"\n")
					GPIO.output(12, True)
					time.sleep(2) 
					GPIO.output(12, False)

			except Exception as e:
				print(" ")
				#print('Exception message: ' + str(e))
			print("\nPresione un pulsador")
				#exit(1)
				
				
	if GPIO.input(16):      #AGREGAR HUELLA NUEVA
		
			print('\n---------- AGREGAR HUELLA ----------\n') 
		
			## Tries to enroll new finger
			try:
				print('Posicione su dedo indice en el sensor...')

				## Wait that finger is read
				while ( f.readImage() == False ):
					pass

				## Converts read image to characteristics and stores it in charbuffer 1
				f.convertImage(0x01)

				## Checks if finger is already enrolled
				result = f.searchTemplate()
				positionNumber = result[0]

				if ( positionNumber >= 0 ):
										
					print('Huella registrada en la posicion #' + str(positionNumber))
					print("\n")

				else:
					print('Remueva su dedo...')
					time.sleep(2)

					print('Posicione su dedo nuevamente...')

					## Wait that finger is read again
					while ( f.readImage() == False ):
						pass

					## Converts read image to characteristics and stores it in charbuffer 2
					f.convertImage(0x02)

					## Compares the charbuffers
					if ( f.compareCharacteristics() == 0 ):
						print('Las huellas no coinciden...')
						raise Exception('Huella no encontrada...')
						GPIO.output(11, True)
						time.sleep(2)
						GPIO.output(11, False)

					## Creates a template
					f.createTemplate()

					## Saves template at new position number
					#usuario = 'hola'
					positionNumber = f.storeTemplate()
					print('Su huella ha sido registrada satisfactoriamente!\n')
					print('Se ha guardado en la posicion #' + str(positionNumber))
					usuario = raw_input('Digite su nombre de usuario: ')
					ID = positionNumber
					fecha = (datetime.datetime.fromtimestamp(time.time()).strftime("%Y-%m-%d"))
					hora = (datetime.datetime.fromtimestamp(time.time()).strftime("%H:%M:%S"))
					sqladd =  "INSERT INTO huella (ID, usuario, fecha, hora) VALUES (%s, %s, %s, %s)" 
					try:
						curs.execute(sqladd,(str(ID), str(usuario) , str(fecha), str(hora)))
						db.commit()
					except:
						db.rollback()
					
					print('OK ' + usuario + ', registro exitoso!')
					GPIO.output(12, True)
					time.sleep(2)
					GPIO.output(12, False)
										
			except Exception as e:
				print('')
			print("\nPresione un pulsador")	
	
	
	if GPIO.input(18):		
		
			print('\n---------- BORRAR HUELLA ----------\n') 
			## Gets some sensor information
			print('Actualmente se han registrado ' + str(f.getTemplateCount()) +'/'+ str(f.getStorageCapacity()))
			
			curs.execute ("SELECT * FROM huella ORDER BY ID ASC")

			print ("\n ID   	Hora		Fecha		Usuario")
			print ("===========================================================")

			for reading in curs.fetchall():
				print (" "+str(reading[0])+" 	"+str(reading[3])+" 	"+str(reading[2])+" 	"+str(reading[1]))
				
			## Tries to delete the template of the finger
			try:
				positionNumber = input('\nIntroduzca el ID a borrar: ')
				positionNumber = int(positionNumber)

				if ( f.deleteTemplate(positionNumber) == True ):
					sqldel = "DELETE FROM huella WHERE ID = '%s'" % positionNumber 
					try:
						curs.execute(sqldel)
						db.commit()
					except:
						db.rollback()
					print('Registro borrado!\n')
					GPIO.output(12, True)
					time.sleep(2)
					GPIO.output(12, False)

			except Exception as e:
				print('No hay registro de huella')
				GPIO.output(11, True)
				time.sleep(2)
				GPIO.output(11, False)
			print("\nPresione un pulsador")
			
