import time
import MySQLdb

global db
global curs
 
db = MySQLdb.connect("localhost", "root", "eie507", "embebidos")
curs = db.cursor()

print('listo')
posicion = '1'
sqlpos = "SELECT * FROM huella WHERE ID = '%s'" %posicion
curs.execute(sqlpos)
result = curs.fetchall()
for reading in result:
	print(reading[1])

