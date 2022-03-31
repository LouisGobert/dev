#!/usr/bin/env python3
# coding: utf-8

import time
import requests


url = "http://challenge01.root-me.org/programmation/ch1/"

s = requests.Session()
reponse = s.get(url).text

print(reponse)

start = reponse.index("U<sub>n+1</sub> = [") + len("U<sub>n+1</sub> = [")
end = reponse.index("]<br />", start) 

calcul = reponse[start+1:end-1].split(' ')
print("Calcul : ", calcul)

start = reponse.index("U<sub>0</sub> = ") + len("U<sub>0</sub> = ")
end = reponse.index("<br />", start) -1

initial_value = int(reponse[start:end])

start = reponse.index("<br />You must find U<sub>") + len("<br />You must find U<sub>")
end = reponse.index("</sub><br /><br />", start)
limite = int(reponse[start:end])

print("Limite : ", limite)
print("Initial value : ", initial_value)

mid_operator = calcul[4]
print("Operator : ", mid_operator)

res = initial_value
calcul[0] = int(calcul[0])
calcul[-1] = int(calcul[-1])

for i in range(limite):
    if mid_operator == "-":
        res = (calcul[0] + res) - (i * calcul[-1])
    else:
        res = (calcul[0] + res) - (i * calcul[-1])

print("Resultat : ", res)


#payload = {"cametu": res} 
res_url = "http://challenge01.root-me.org/programmation/ch1/ep1_v.php?result=" + str(res)
rpost = s.get(res_url)
rpoststr = rpost.text
print(rpoststr)
    