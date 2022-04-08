#include "Header.h"


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {

	*returnSize = arrSize;
	int max = max = arr[arrSize - 1], temp;
	arr[arrSize - 1] = -1;

	if (arrSize == 1)
		return arr;

	
	for (int i = arrSize - 2; i >= 0; i--) {
		if (arr[i] > max) {
			temp = max;
			max = arr[i];
			arr[i] = temp;

		} else 	arr[i] = max;
	}
	return arr;
}

