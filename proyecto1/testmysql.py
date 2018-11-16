#!/usr/bin/env python2.7

import os
import time
import datetime
import MySQLdb

global c
global db
def getCPUtemperature():
    t_cpu = os.popen('vcgencmd measure_temp').readline()
    t_cpu = t_cpu.replace("temp=","").replace("'C\n","")
    return(t_cpu)

def insert_to_db():
    temperatur = (getCPUtemperature())
    zeit = (datetime.datetime.fromtimestamp(time.time()).strftime("%H:%M:%S"))
    datum = (datetime.datetime.fromtimestamp(time.time()).strftime("%Y-%m-%d"))
    print (temperatur + " - " + zeit + " - " + datum)
    sql =  "INSERT INTO prueba (TValue, T_Date, T_Time) VALUES (%s, %s, %s)" 
    try:
        c.execute(sql,( str(temperatur) , str(datum), str(zeit)))
        db.commit()
    except:
        db.rollback()
    #db.close()

def read_from_db():
    try:
        #c.execute("SELECT * FROM registro WHERE ID = (SELCET MAX(ID) FROM registro)")
        c.execute("SELECT * FROM prueba ORDER BY ID DESC LIMIT 1")      
        result = c.fetchall()
        if result is not None:
             print ('CPU temperature: ' , result[0][1], '| time: ' , result[0][3], ' | datum: ' , result[0][2])
    except:
        print ("read error")
    
def main():
    while 1:
        insert_to_db()
        read_from_db()
        time.sleep(4)
    
        
if __name__ == '__main__':
    try:
        db = MySQLdb.connect("localhost","root","eie507","embebidos")
        c= db.cursor()
    except:
        print ("Keine Verbindung zum Server...")
             
    try:
      main()
    except KeyboardInterrupt:
      print ("bye bye...")
      pass    
        
  
