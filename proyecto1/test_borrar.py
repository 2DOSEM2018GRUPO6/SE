import time
import MySQLdb

global db
global curs
 
db = MySQLdb.connect("localhost", "root", "eie507", "embebidos")
curs = db.cursor()

criterio = raw_input("Ingrese posicion a eliminar: ") 
sqldel = "DELETE FROM huella WHERE ID = '%s'" % criterio 
try:
	curs.execute(sqldel)
	db.commit()
except:
	db.rollback()
print('listo')
	

