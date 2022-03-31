#!/usr/bin/env python3
# coding: utf-8

""" Pour résoudre se problème il faut faire -10 sur tout les char du fichier .bin """


encrypt = list("L|k€y+*^*zo‚*€kvsno|*k€om*vo*zk}}*cyvksr")
a = 'abcdefghijklmnopqrstuvwxyz'
res = ''
for i in range(len(encrypt)):
    res += (chr(ord(encrypt[i])-10))

print(res)