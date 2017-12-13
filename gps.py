# -*- coding: utf-8 -*-
import serial
port = serial.Serial("/dev/ttyS0", baudrate=9600, timeout=3.0)
# le programme redemarre toutes les 3s
i=0
while True:
    i+=1
    rcv = port.read(150)                 # lit les caracteres (150)
    splitage = rcv.split("$")            # Split les caracteres selon les types -> interese par $GPRMC
    for elem in splitage:                # elem represente toutes les infos pour chaque type
        secondSplit = elem.split(',')    # On trie les infos car elles sont separees par une ','
        for secondElem in secondSplit:   # Pour chaque info...
        #print(secondElem)
            if secondElem == "GPRMC":    # ... On va prendre celles qui nous interesse -> $GPRMC
                if len(secondSplit) > 5 :
                    Latitude = secondSplit[3][0:2]+"°"+secondSplit[3][2:9]
                    print "Latitude : "+Latitude
                if len(secondSplit) > 7 :
                    Longitude = secondSplit[5][0:3]+"°"+secondSplit[5][3:10]
                    print "Longitude : "+Longitude
                else:
                    print("Mauvaise réception des données")
