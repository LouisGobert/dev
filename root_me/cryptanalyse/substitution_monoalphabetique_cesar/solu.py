#!/usr/bin/env python3
# coding: utf-8

encrypt = "tm bcsv qolfp\
f'dmvd xuhm exl tgak\
hlrkiv sydg hxm\
qiswzzwf qrf oqdueqe\
dpae resd wndo\
liva bu vgtokx sjzk\
hmb rqch fqwbg\
fmmft seront sntsdr pmsecq"

"""

SOLUTION : c'est du code de césar progressif

UN DEUX TROIS
JIRAI DANS LES BOIS
QUATRE CINQ SIX
CUEILLIR DES CERISES
SEPT HUIT NEUF
DANS UN PANIER NEUF
DIX ONZE DOUZE 
ELLES SERONT TOUTES ROUGES"""


# calcul occurence

occ = [0] * 26
prime =  [1,3,5,7,9,11,15,17,19,21,23,25]

for x in range(len(prime)):
    for u in range(27):
        res = ''
        for i in range(len(encrypt)):
            if encrypt[i].isalpha():
                lett = ord(encrypt[i]) - ord('a')
                res += chr(((prime[x]*(lett)+u)%26) + ord('a'))
            else:
                res += ' '


        print(res)
        