#include "Header.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {


	int* returnTab = (int*)malloc(sizeof(int) * numsSize);

	int sum = 1;
	int leftSum = 1, i;
	for ( i = numsSize - 1; i >= 0; i--) {
		returnTab[i] = sum;
		sum *= nums[i];
	}

	for (i = 0; i < numsSize; i++) {
		if (i == 0) {
			returnTab[i];
			leftSum *= nums[0];
		}
		else if (i + 1 >= numsSize)
			returnTab[i] = leftSum;
		else {
			returnTab[i] *= leftSum;
			leftSum *= nums[i];
		}
	}

	*returnSize = numsSize;
	return returnTab;
	

}


//
//void main() {
//
//	int tab[5] = { 1, 0 };
//
//	int p = 0;
//
//	int* r = productExceptSelf(tab, 2, &p);
//	printArray(r, p);
//}