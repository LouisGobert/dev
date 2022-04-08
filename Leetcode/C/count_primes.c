#include "Header.h"


bool isPrime(int val)  {

	for (int i = 3; i < sqrt(val)+1; i+=2) {
		if (val % i == 0) return false;
	}

	return true;

}




int countPrimes(int n) {

	if (n == 2) return 1;
	else if (n < 2) return 0;

	int nbPrime = 1;
	for (int num = 3; num < n; num += 2) {
		if (isPrime(num)) {
			printf("%d is prime\n", num);
			nbPrime++;
		}
	}

	return nbPrime;
}


//void main() {
//	int res = countPrimes(10);
//}

