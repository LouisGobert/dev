#!/usr/bin/env python3
# coding: utf-8

import generate_gpx_html 
import pickle

"""

D   EXEMPL  
0 	1.0 	    111.32 km 	s
1 	0.1 	    11.132 km 	nde ville
2 	0.01 	    1.1132 km 	lage
3 	0.001 	    111.32 m 	
4 	0.0001 	    11.132 m 	mp
5 	0.00001 	1.1132 m 	re
6 	0.000001 	111.32 mm 	ain
7 	0.0000001 	11.132 mm 	ite des instruments GPS commerciaux
8 	0.00000001 	1.1132 mm

"""
def arround(coo):


	"""
	I adjust the precission to +- 5 metters
	so
	+- 5 digit near 5
	"""

	five_digit = (coo * 10000) % 10
	if five_digit <= 0.999999:
		new_digit = 5
	elif five_digit <= 2.5:
		new_digit = 5
	elif five_digit <= 4.999999:
		new_digit = 5
	elif five_digit <= 7.5:
		new_digit = 5
	elif five_digit <= 8.999999:
		new_digit = 5
	else:
		new_digit = 5

	coo = ((coo * 10000) - five_digit + new_digit) / 10000

	return coo


def merge_gpx(gpx_one, gpx_two):

	# Time to start detect a collision
	TIME_TO_WAIT_DETECT = 60

	# Precission then whe are going into collision mode
	ENTER_PRECISSION = 4

	#gpx_one_11m = list(map(lambda x: [round(x[0], ENTER_PRECISSION), round(x[1], ENTER_PRECISSION)], gpx_one[:]))
	gpx_one_11m = list(map(lambda x: [arround(x[0]), arround(x[1])], gpx_one[:]))
	#gpx_two_11m = list(map(lambda x: [round(x[0], ENTER_PRECISSION), round(x[1], ENTER_PRECISSION)], gpx_two[:]))
	gpx_two_11m = list(map(lambda x: [arround(x[0]), arround(x[1])], gpx_two[:]))

	
	for one in range(len(gpx_one)):
		for two in range(len(gpx_two)):
			if gpx_one_11m[one] == gpx_two_11m[two]:
				gpx_two[two][0] = gpx_one[one][0]
				gpx_two[two][1] = gpx_one[one][1]




	

def solu_merge_one():
	TIME_TO_WAIT_DETECT = 60
	OUT_LIMIT_PRECISSION = 3

	# +- 55 metter precission
	#gpx_scale = list(map(lambda x: [arround(x[0]), arround(x[1])], gpx))
	gpx_scale = list(map(lambda x: [round(x[0], OUT_LIMIT_PRECISSION), round(x[1], OUT_LIMIT_PRECISSION)], gpx))
	gpx_scale_11m = list(map(lambda x: [round(x[0], OUT_LIMIT_PRECISSION), round(x[1], OUT_LIMIT_PRECISSION)], gpx))
	#gpx_scale = gpx[:]


	res_gpx = []
	gpx_list = []
	extract_gpx = []
	extract_list = []

	for y in range(len(gpx)):
		if gpx_scale[y] is not None:
			res_gpx.append(gpx[y])


			
			for x in range(y + TIME_TO_WAIT_DETECT ,len(gpx)):
					
				# If the runner point is at the same pos then the walker pos 1 min later
				if gpx_scale[y] == gpx_scale[x]:

					p = 0
					while ( x + p + 2< len(gpx) and (
						gpx_scale_11m[y+p] == gpx_scale_11m[x+p] or
						gpx_scale_11m[y+p+1] == gpx_scale_11m[x+p+1] or
						gpx_scale_11m[y+p-1] == gpx_scale_11m[x+p-1])):
						#print(f'{y+p} same then {x+p}')
						#print(f'{gpx_scale_11m[y+p]} : {gpx_scale_11m[x+p]}')

						extract_gpx.append(gpx[x+p])

						gpx_scale[x+p] = None
						gpx_scale_11m[x+p] = None
						#gpx_scale[y+p] = None
						
						p+=1
					extract_list.append(extract_gpx[:])
					extract_gpx = []


		else:
			print('added 1new gpx')
			gpx_list.append(res_gpx[:])
			res_gpx = []

		
	print('added 1new gpx')
	gpx_list.append(res_gpx)
		

	print(f'Extract {len(extract_list)} gpx.')
	print(f'Split into {len(gpx_list)} gpx.')

	generate_gpx_html.gen_with_multiple_polyline(gpx_list, 'test/gpx_list')
	generate_gpx_html.gen_with_multiple_polyline(extract_list, 'test/extract_list')

	with open('test/gpx_list.gpx', 'w') as f:
		f.write(str(gpx_list))


	with open('test/res_gpx_extract.gpx', 'w') as f:
		f.write(str(extract_list))




if __name__ == '__main__':

	gpx_list = None
	with open('gpx.list', 'rb') as f:
		gpx_list = pickle.load(f)[:10]


	for y in range(len(gpx_list)):
		for x in range(len(gpx_list)):
			if x != y:
				merge_gpx(gpx_list[y], gpx_list[x])
				merge_gpx(gpx_list[x], gpx_list[y])

		print(f'{y}/{len(gpx_list)} gpx merged.')

	
	with open('test/gpx_merged.list', 'wb') as f:
		pickle.dump(gpx_list, f)

	generate_gpx_html.gen_with_multiple_polyline(gpx_list, 'test/gpx_merged')



