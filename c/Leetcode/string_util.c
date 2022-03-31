#include "string_util.h"


void reverseString(char* str, int s, int e) {

	char t;
	while (s < e)
	{
		t = str[s];
		str[s] = str[e];
		str[e] = t;
		s++;
		e--;
	}
}


