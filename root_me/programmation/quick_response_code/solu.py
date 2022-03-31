#!/usr/bin/env python3
# coding: utf-8

import time
import requests
import re
import base64
import json
from PIL import Image
import qrcode
import cv2

try:
    from PIL import Image
except ImportError:
    import Image
import pytesseract

url = "http://challenge01.root-me.org/programmation/ch7/"


s = requests.Session()
reponse = s.get(url)
reponse = reponse.text

start = reponse.index("data:image/png;base64,") + len("data:image/png;base64,")
end = reponse.index("\"", start)
img = reponse[start:end]

with open('qr.png', 'wb') as f:
    f.write(base64.b64decode(img))

# TRAITEMENT

empty_qr = Image.open('qr.png', 'r')
calib = Image.open('calib.png', 'r')
offset = (18, 19)
offset2 = (219, 18)
offset3 = (18, 219)

empty_qr.paste(calib, offset)
empty_qr.paste(calib, offset2)
empty_qr.paste(calib, offset3)
empty_qr.save('res.png')


from pyzbar.pyzbar import decode

img = Image.open("res.png")

res = decode(img)

res = res[0].data.decode("utf-8")

print(res)
print("Code complet : ", res, " flag : ", res[res.index("/"):])

payload = {"metu": res[res.index("/"):]} 
reponse = s.post(url, data=payload)

print(reponse.text)
