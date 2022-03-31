#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>


int myAtoi(char* s) {

	// Get the start
	int pos = 0, sign = 1;
	long long res = 0;
	
	while (s[pos] == ' ')
		pos++;

	// If a digit or a sign
	if (s[pos] == '-') {
		sign = -1;
		pos++;
	}
	else if (s[pos] == '+') {
		sign = +1;
		pos++;
	}

	while (s[pos] > 47 && s[pos] < 58)
	{
		res *= 10;
		res += (s[pos] - 48);

		pos++;


		if (res > INT_MAX) {
			if (sign == -1)
				return INT_MIN;
			return INT_MAX ;
		}
		else if (res < INT_MIN)
			return INT_MIN * sign;

		
	}

	if (res == 0)
		return 0;
	else {
		
		return res * sign;
	}

}

