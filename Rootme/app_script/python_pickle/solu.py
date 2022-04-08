#!/usr/bin/env python3
# coding: utf-8

import time
import requests


SERVER = "challenge02.root-me.org"
PORT = 60005
import socket

def resolve():
	socket.setdefaulttimeout(100)
	timeout = socket.getdefaulttimeout()
	socketInstance = socket.create_connection((SERVER,PORT))
	print('Connection résussie.')
	while(True):

		data = socketInstance.recv(1024).decode()
		print(data)
		socketInstance.send(res.encode())


	socketInstance.close()



resolve()
