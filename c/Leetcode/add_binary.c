#include "Header.h"

char* addBinary(char* a, char* b) {
	int c = 0, t;
	int la = strlen(a), lb = strlen(b);
	int ai = la-1, bi = lb-1;
	int Va, vB;
	int resIndex = ((la > lb) ? la : lb);
	char* res = malloc(sizeof(char) * (((la > lb) ? la : lb) + 2));
	res[resIndex + 1] = '\0';
	while (ai >= 0 || bi >= 0)
	{
		t = c;
		c = 0;
		if (ai >= 0) 
			t += a[ai] - '0';
		if (bi >= 0)
			t += b[bi] - '0';

		if (t > 1) {
			c = 1;
			if (t == 3) {
				res[resIndex] = '1';
			}
			else {
				res[resIndex] = '0';
			}
			
		}
		else if (t == 1) {
			res[resIndex] = '1';
		}
		else
			res[resIndex] = '0';

		resIndex--;
		ai--;
		bi--;
	}
	if (c) {
		res[0] = '1';
		return res;
	}

	char* newRes = malloc(sizeof(char) * (((la > lb) ? la : lb) + 1));

	return res + (sizeof(char));
}

//void main() {
//
//	char t1[] = "00000001";
//	char t2[] = "00000001";
//
//	char* res = addBinary(t1, t2);
//	printf("%s", res);
//	free(res);
//}