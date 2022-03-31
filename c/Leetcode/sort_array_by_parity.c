#include "Header.h"


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
	*returnSize = ASize;
	int* newTab = malloc(sizeof(int) * ASize);

	for (int i = 0, s = 0, e = ASize - 1; s <= e; i++) {
		if (A[i] % 2 == 0)
			newTab[s++] = A[i];
		else
			newTab[e--] = A[i];
	}

	return newTab;
}

//void main() {
//	int test[] = { 10, 11, 11, 12, 5, 6, 3 };
//	int e = 0;
//	e++;
//	int retus = 0;
//	int* res = sortArrayByParity(test, 7, &retus);
//	printArray(res, retus);
//}