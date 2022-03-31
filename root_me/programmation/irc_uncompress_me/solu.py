#!/usr/bin/env python3
# coding: utf-8

import socket, string, time
import time
import zlib
import base64
SERVER = 'irc.root-me.org'
PORT = 6667
NICKNAME = ''
CHANNEL = ''

def main():
	global IRC
	IRC = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	IRC.connect((SERVER, PORT))
	Listener()


def send_data(command):
	command += "\n"
	print("Envois de : ", command)
	IRC.send(command.encode())


def Listener():
	x = 0
	while (True):
		
		buffer = IRC.recv(1024)
		buffDecoded = buffer.decode()
		if buffer:
			print(buffDecoded)

			if "PRIVMSG Louis :" in buffDecoded:
				print("TROUVER")
				debut = buffDecoded.index("PRIVMSG Louis :") + len("PRIVMSG Louis :")
			
				base64_message = buffDecoded[debut:]
				message = base64.b64decode(base64_message)

				print("Decode base64 : ", message)
				message = zlib.decompress(message)
				message = message.decode()
				print(message)
				res = "privmsg Candy !ep4 -rep "
				res += message
				send_data(res)

		if not x:
			send_data("NICK Louis")
			send_data("USER Louis 0 * :Louis")
			time.sleep(2)
			#send_data("msg NickServ IDENTIFY mdp1234#")
			send_data("JOIN #root-me_challenge")
			#send_data('Candy !ep4')
			send_data('privmsg Candy !ep4')

		x = 1

main()