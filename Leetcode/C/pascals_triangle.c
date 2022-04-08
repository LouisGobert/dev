#include "Header.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

	if (numRows == 0) {
		*returnSize = 0;
		return NULL;
	}

	*returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
	(*returnColumnSizes)[0] = 1;

	int** array = (int**)malloc(sizeof(int*) * numRows);
	
	array[0] = (int*)malloc(sizeof(int) * 1);
	array[0][0] = 1;
	
	for (int i = 1, t; i < numRows; i++) {
		array[i] = (int*)malloc(sizeof(int) * (i + 1));
		(*returnColumnSizes)[i] = i + 1;

		for (t = 1; t < i; t++)
			array[i][t] = array[i - 1][t] + array[i - 1][t - 1];
		
		array[i][0] = 1;
		array[i][i] = 1;

		//array[i] = subArray;
	}


	*returnSize = numRows;
	return array;
		
}



//
//void main() {
//
//	int* sizeCol = NULL;
//	int rSize = 0;
//
//	int** res = generate(6, &rSize, &sizeCol);
//	printArray(sizeCol, 6);
//
//	for (int x = 0; x < rSize; x++) {
//		for (int y = 0; y < sizeCol[x]; y++) {
//			printf("%d ", res[x][y]);
//		}
//		printf("\n");
//	}
//
//	for (int i = 0; i < rSize; i++) {
//	
//		free(res[i]);
//	}
//
//	free(sizeCol);
//	free(res);
//
//}