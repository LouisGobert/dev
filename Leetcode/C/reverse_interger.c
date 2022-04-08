#include "Header.h"
#include "array.h"




int reverse(int x) {
	if (x == 0 || x == INT_MIN)
		return 0;
	unsigned int rvs = 0, base = 0;


	int zero = false;
	if (x < 0) {
		zero = true;
		x = x - x - x;
	}
	int t = x;
	// On compte les base
	while (t >= 10)
	{
		base++;
		t /= 10;
	}



	// del the 0 head
	while (x % 10 == 0) {
		x /= 10;
		base--;
	}
	

	while (x >= 10)
	{
		rvs += (x % 10) * pow(10, base);
		if (rvs > INT_MAX)
			return 0;
		base--;
		x /= 10;
	}

	rvs += x;
	int r = rvs;
	return (zero) ? (int)-r : rvs;
}



//void main() {
//
//	int x = 1534236469;
//	
//	int res = reverse(x);
//
//}