#!/usr/bin/python2
 
import sys
 
def youLose():
    print "Try again ;-)"
    sys.exit(1)
 
 
try:
    p = input("Please enter password : ")
except:
    youLose()
 
 
with open(".passwd") as f:
    passwd = f.readline().strip()
    try:
        if (p == int(passwd)):
            print "Well done ! You can validate with this password !"
    except:
        youLose()


print(int(open(".passwd", "r").readline().strip()))

exec('print int(open(".passwd", "r").readline().strip())')



MOI

open("res.txt","a").write((int(open("r.txt","r").readline().strip()))).close()


open("/tmp/res.txt","a").write(open(".passwd", "r").readline().strip())
