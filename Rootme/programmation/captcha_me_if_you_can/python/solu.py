#!/usr/bin/env python3
# coding: utf-8

import time
import urllib.request, urllib.error, urllib.parse
import requests
import re
import base64
import json


try:
    from PIL import Image
except ImportError:
    import Image
import pytesseract

url = "http://challenge01.root-me.org/programmation/ch8/"

while True:
    s = requests.Session()
    rget = s.get(url)
    reponse = rget.text

    start = reponse.index("data:image/png;base64,") + len("data:image/png;base64,")
    end = reponse.index("\"", start)

    img = reponse[start:end]
    with open('res.png', 'wb') as f:
        f.write(base64.b64decode(img))

    

    def ocr_core(filename):
        """
        This function will handle the core OCR processing of images.
        """
        text = pytesseract.image_to_string(Image.open(filename))  # We'll use Pillow's Image class to open the image and pytesseract to detect the string in the image
        return text

    res = ocr_core('res.png')

    res = res.replace(" ", "")
    res = res[:-1]
    res = res.rstrip("\n")

    print("Res---", res, "---")
    


    for i, elt in enumerate(res):
        print("i : " , i, " val: ", elt)

    if res.isalnum():
        print("Correct   :", res)

        payload = {"cametu": res} 
        rpost = s.post(url, data=payload)
        rpoststr = rpost.text

        try:
            start = rpoststr.index("data:image/png;base64,") + len("data:image/png;base64,")
        except ValueError:
            print(rpoststr)
            exit()
        """if start != 254 and "retente" not in rpoststr:
            print(rpoststr)
            exit()"""
     
    else:
        print("Incorrect :", res)
