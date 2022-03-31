#include "Header.h"


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ASize, int* AColSize, int* returnSize, int** returnColumnSizes) {

	*returnSize = ASize;
	*returnColumnSizes = malloc(sizeof(int) * (*AColSize));

	int temp;
	for (int i = 0, l, r; i < ASize; i++) {
		
		(*returnColumnSizes)[i] = *AColSize;
		for (l = 0, r = *AColSize - 1; l <= r; l++, r--) {
			temp = 1 ^ A[i][l];
			A[i][l] = A[i][r] ^ 1;
			A[i][r] = temp;
		}
	}

	return A;
}
