#!/usr/bin/env python3
# coding: utf-8

import time
import requests
from basecrack import BaseCrack
import subprocess
import codecs

"""
Encodage utilisé : 
	- Base64
	- Base32
	- Morse
	- Hexadecimal donne un résultat ascii
	- PEUX ETRE : myslq323


	a trouvé : 
	-	V{d6}d1Ya8
	-	b9Z5RVqs%zWn=
"""

#tcp://challenge01.root-me.org:52017

SERVER = "challenge01.root-me.org"
#SERVER = '212.129.38.224'
PORT = 52017


import socket


def get_to_decode(data):
	start = data.index("Decode this please: '") + len("Decode this please: '")
	stop = data.index("'", start)

	to_decode = data[start:stop]

	return to_decode


def Convert(string):
    list1=[]
    list1[:0]=string
    return list1



def decodage(to_decode):
	# /home/louis/.local/bin

	#to_decode = "\"" + to_decode + "\""
	print("A décoder : ", to_decode)
	res = subprocess.check_output(["/home/louis/.local/bin/ciphey", "-g", "-t", to_decode]).decode().replace('\n', '').lower()

	# Si ca c'est pas passer comme prévu
	if res == to_decode:
		string = "68656c6c6f"
		res = str(codecs.decode(res, "hex"), 'utf-8')

	if not res.isalpha():
		print("Erreur de format : ", res)
		res = BaseCrack().decode(to_decode)[0]
		


	print("Résultat du décodage :", res)
	#print(Convert(res))
	return res


def resolve():
	socket.setdefaulttimeout(100)
	timeout = socket.getdefaulttimeout()

	print("System has default timeout of {} for create_connection".format(timeout))
	socketInstance = socket.create_connection((SERVER,PORT))
	print('Connection résussie.')

	#bytes2Send = str.encode("Hello server system!")
	#socketInstance.sendall(bytes2Send)

	# Receive the data
	while(True):

		data = socketInstance.recv(1024).decode()
		print(data)
		to_decode = get_to_decode(data)
		res = decodage(to_decode) + "\n"

		print("On envois : ", res.encode())
		socketInstance.send(res.encode())

		if(data==b''):

			print("Connection closed")

			break

	socketInstance.close()
	
resolve()
