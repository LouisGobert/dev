#include "Header.h"
/*Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note:

Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For this problem, 
assume that your function returns 231 − 1 when the division result overflows.*/





int divide(int dividend, int divisor) {
	if ((dividend == INT_MIN && divisor == -1))
		return INT_MAX;
	else if (dividend == INT_MIN && divisor == 1)
		return INT_MIN;

	int q = 0;
	bool neg = false;
	bool neg2 = false;
	if (divisor < 0) {
		neg = true;
		divisor += -divisor + -divisor;
	}
	if (dividend < 0) {
		neg2 = true;

	}

	if (neg2) {
		while (dividend + divisor <= 0)
		{
			dividend += divisor;
			q++;
		}
	}
	else {

		while (dividend - divisor >= 0)
		{
			dividend -= divisor;
			q++;
		}
	}

	if (neg && !neg2 || !neg && neg2)
		q -= (q + q);
	return q;
}

