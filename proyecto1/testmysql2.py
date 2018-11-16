import MySQLdb
 
db = MySQLdb.connect("localhost", "root", "eie507", "embebidos")
curs=db.cursor()

curs.execute ("SELECT * FROM huella ORDER BY ID ASC")

print ("\n ID   	Hora		Fecha		Usuario")
print ("===========================================================")

for reading in curs.fetchall():
    print (" "+str(reading[0])+" 	"+str(reading[3])+" 	"+str(reading[2])+" 	"+str(reading[1]))
