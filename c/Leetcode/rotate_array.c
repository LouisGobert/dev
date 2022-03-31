#include "Header.h"



void rotatee(int *nums, int numsSize, int k) {


	k %= numsSize;
	if (k == 0)
		return; 

	int* temp = (int*)malloc(sizeof(int) * k);
	int i, pos;
	for (i = numsSize - k, pos = 0; i < numsSize; i++, pos++)
		temp[pos] = nums[i];
	
	// Recopy with decade
	for (i = numsSize-k-1, pos = numsSize-1; i >= 0; i--, pos--)
		nums[pos] = nums[i];
	

	// Paste the temp tab
	for (i = 0; i < k; i++)
		nums[i] = temp[i];

}

