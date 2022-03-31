#include "Header.h"



bool validMountainArray(int* A, int ASize) {

	// UP mountain
	bool sommet = false;
	int pos = 0;

	if (ASize < 3)
		return false;
	while (pos + 1 < ASize && A[pos] < A[pos + 1]) {
		pos++;
		sommet = true;
	}
	
	if (!sommet || pos + 1 < ASize && A[pos] == A[pos + 1]) return false;

	while (pos + 1 < ASize && A[pos] > A[pos + 1]) {
		pos++;
		sommet = false;
	}
	if (sommet || pos + 1 < ASize && A[pos] <= A[pos + 1]) return false;

	return true;
	
}

