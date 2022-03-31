#include "Header.h"

// Voir les formules : 
//			https://www.alloprof.qc.ca/fr/eleves/bv/mathematiques/les-permutations-les-arrangements-et-les-combinai-m1346


int numPairsDivisibleBy60(int* time, int timeSize) {
	int mod[60] = {0};
	int i, tot = 0;

	for (i = 0; i < timeSize; i++)
		mod[time[i] % 60]++;


	if (mod[0] > 1)
		for (int x = 0; x < mod[0] - 1; x++)
			for (i = x + 1; i < mod[0]; i++)
				tot++;
	
	if (mod[30] > 1)
		for (int x = 0; x < mod[30] - 1; x++)
			for (i = x + 1; i < mod[30]; i++)
				tot++;
	

	for (i = 1; i < 30; i++)
		if (mod[i] != 0 && mod[60-i] != 0)
			tot += mod[i] * mod[60-i];
	
	return tot;
}

/// 1234
/// 12
/// 13
/// 14
/// 23
/// 24
/// 34


//void main() {
//	int test[] = { 60, 60, 60, 100, 40 };
//
//	int res = numPairsDivisibleBy60(test, 5);
//}