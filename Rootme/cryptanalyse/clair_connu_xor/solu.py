#!/usr/bin/env python

from os import urandom


fichier = open("text.txt", 'rb')
message = ''
test = 0
for ligne in fichier:
    message += ligne
    if test < 1:
        #print('Message:', message)
        test += 1
fichier.close()



""" 
Fichier crypter :
2    4    2    c    9    a    e    3    6    2    6    e
0010 0100 0010 1100 10011010 11100011 01100010 01101110

Attendu : (Inversion de la taille : 495606)
00000000 00000111 10001111 11110110

4    2    4    D
0100 0010 0100 1101 11110110 10001111 00000111 00000000


calul de la cle
001001000010110010011010111000110110001001101110
010000100100110111110110100011110000011100000000
011001100110000101101100011011000110010101101110
"""



key = "011001100110000101101100011011000110010101101110"
key_split = [int(d) for d in str(key)]
print("Splited key : ")
print(key_split)


def xor_strings(message, key):
    scale = 16 ## equals to hexadecimal
    num_of_bits = 8
    index_key = 0

    global_res = ''

    #for i in range(1):
    for i in range(len(message)):
        source = ''.join(format(ord(message[i]), '08b'))
        source_split = [int(d) for d in str(source)]
        #print(source_split)

        res = []
        
        for x, elt in enumerate(source_split): 
            #print("S :", elt)
            #print("M :",key[index_key%len(key)])
            

            result = elt ^ key[index_key%len(key)]
            res.append(str(result))
            #print("R :", result)
            index_key += 1

        
        #print("Source :    {}\nMask :      {}\nRes :       {}".format(source_split, key, res))
        


        # ecriture
      
        test = ''.join(res)
        test = int(test, 2)
        global_res += chr(test)
        #print(global_res)

    return global_res





cipherText = xor_strings(message, key_split)




new_fichier = open("resFinal.bmp", 'w')
new_fichier.write(cipherText)
new_fichier.close()