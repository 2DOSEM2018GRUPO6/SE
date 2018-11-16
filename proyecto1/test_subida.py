import time
import datetime
import MySQLdb

global db
global curs
global insertar
global leer
 
db = MySQLdb.connect("localhost", "root", "eie507", "embebidos")
curs = db.cursor()

ID = ('10')
usuario = ('paralelepipedortocloro')
fecha = (datetime.datetime.fromtimestamp(time.time()).strftime("%Y-%m-%d"))
hora = (datetime.datetime.fromtimestamp(time.time()).strftime("%H:%M:%S"))
print ('holi')
sqladd =  "INSERT INTO huella (ID, usuario, fecha, hora) VALUES (%s, %s, %s, %s)" 
try:
	curs.execute(sqladd,(str(ID), str(usuario) , str(fecha), str(hora)))
	db.commit()
except:
	db.rollback()


