#include "Header.h"



int hammingWeight(uint32_t n) {

	int log = log2(n);
	int n_bit = 0;

	while (log >= 0 && n != 0)
	{
		if (n - pow(2, log) >= 0) {
			n -= pow(2, log);
			n_bit++;
		}

		log--;
	}

	return n_bit;
}



//void main() {
//	int res = hammingWeight(11);
//
//}

