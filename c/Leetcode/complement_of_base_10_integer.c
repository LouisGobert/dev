#include <stdio.h>
#include <limits.h>
#include <math.h>

int bitwiseComplement(int N) {

	int res = 0, base = 31;
	if (!N)
		return 1;

	while (pow(2, base) - N > 0)
		base--;

	while (N != 0 || base != -1)
	{
		if (pow(2, base) - N <= 0) {
			
			N -= pow(2, base);
		} else 
			res += pow(2, base);

		base--;
	}

	return res;

}
