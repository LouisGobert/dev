#!/usr/bin/env python3

from PIL import Image

pixel = ['0x3+1x1+0x1+0x1+0x7+1x2+0x15+1x1+0x8+1x1+0x8+1x1+0x1+1x1+0x1+1x1+0x1+1x1+0x1+1x1+0x3+1x1+0x1+1x1+0x3+1x1+0x1+1x4+0x2+1x1+0x25'
,'0x2+1x1+0x4+1x1+0x4+1x3+0x1+1x2+0x2+1x8+0x11+1x4+0x1+1x3+0x6+1x2+0x4+1x1+0x4+1x2+0x7+1x4+0x4+1x2+0x7+1x2+0x3+1x2+0x3'
,'0x3+1x1+0x2+1x1+0x2+1x1+0x11+1x2+0x2+1x3+0x7+1x1+0x4+1x2+0x2+1x2+0x7+1x1+0x6+1x1+0x2+1x1+0x4+1x3+0x1+1x1+0x4+1x1+0x2+1x1+0x2+1x1+0x3+1x1+0x2+1x3+0x2+1x2+0x3'
,'1x1+0x2+1x1+0x4+1x1+0x2+1x1+0x1+1x1+0x2+1x1+0x2+1x1+0x1+1x2+0x2+1x2+0x1+1x2+0x3+1x1+0x3+1x1+0x2+1x2+0x1+1x3+0x3+1x1+0x2+1x1+0x4+1x2+0x1+1x1+0x4+1x1+0x3+1x2+0x12+1x2+0x1+1x1+0x3+1x7+0x3'
,'0x3+1x1+0x7+1x1+0x1+1x1+0x4+1x1+0x2+1x2+0x2+1x2+0x4+1x1+0x2+1x1+0x1+1x2+0x1+1x8+0x1+1x1+0x4+1x1+0x5+1x1+0x3+1x2+0x2+1x1+0x1+1x2+0x2+1x1+0x3+1x2+0x9+1x1+0x1+1x2+0x2+1x3+0x2+1x1'                
,'0x7+1x1+0x4+1x1+0x4+1x1+0x1+1x1+0x1+1x7+0x3+1x1+0x1+1x2+0x3+1x1+0x1+1x6+0x1+1x1+0x3+1x1+0x2+1x1+0x14+1x2+0x8+1x1+0x10+1x2+0x3+1x2+0x1+1x1+0x1'
,'0x6+1x5+0x4+1x1+0x7+1x1+0x2+1x1+0x3+1x2+0x4+1x1+0x8+1x1+0x3+1x2+0x1+1x2+0x3+1x1+0x8+1x1+0x2+1x2+0x1+1x1+0x3+1x7+0x5+1x2+0x2+1x1+0x2+1x2+0x3'
,'0x1+1x1+0x2+1x1+0x1+1x2+0x5+1x1+0x6+1x2+0x3+1x1+0x2+1x1+0x1+1x2+0x20+1x8+0x1+1x1+0x1+1x1+0x4+1x2+0x3+1x1+0x2+1x2+0x3+1x2+0x7+1x2+0x3+1x2+0x4'
,'0x2+1x1+0x3+1x5+0x5+1x2+0x7+1x1+0x4+1x2+0x2+1x1+0x2+1x2+0x1+1x1+0x3+1x1+0x6+1x2+0x2+1x2+0x3+1x2+0x2+1x3+0x1+1x1+0x6+1x3+0x3+1x5+0x3+1x1+0x4+1x1+0x5'
,'0x4+1x2+0x3+1x2+0x3+1x1+0x5+1x2+0x2+1x1+0x1+1x1+0x1+1x1+0x1+1x2+0x9+1x1+0x3+1x1+0x2+1x1+0x1+1x1+0x2+1x1+0x1+1x2+0x2+1x1+0x2+1x1+0x1+1x1+0x4+1x3+0x1+1x1+0x2+1x2+0x3+1x2+0x3+1x1+0x5+1x1+0x4+1x1+0x2'
,'0x6+1x5+0x4+1x1+0x1+1x1+0x2+1x2+0x6+1x1+0x1+1x7+0x4+1x3+0x3+1x1+0x4+1x1+0x2+1x2+0x4+1x1+0x6+1x1+0x6+1x8+0x3+1x1+0x5+1x1+0x7'
,'0x2+1x1+0x3+1x6+0x4+1x1+0x1+1x3+0x4+1x1+0x2+1x2+0x4+1x1+0x5+1x1+0x2+1x1+0x3+1x2+0x3+1x1+0x2+1x3+0x1+1x1+0x2+1x2+0x3+1x3+0x2+1x3+0x9+1x1+0x4+1x2+0x7+1x2']

img = Image.new(mode="RGB", size=(1000, 1000))

text = img.load()
for y in range(len(pixel)):
    row = pixel[y].split('+')
    xx = 0
    for x in range(len(row)):
        if row[x][0] == '0':
            nb = row[x].split('x')[1]
            nb = int(nb)
            print(nb)
            for n in range(nb):
                img.putpixel((xx, y), (255, 255, 255))
                xx += 1
        else:
            nb = row[x].split('x')[1]
            nb  = int(nb)
            for n in range(nb):
                img.putpixel((xx, y), (0, 0, 0))
                xx += 1
            
print("fin")
text = img.show()
img.save("generated.png")
