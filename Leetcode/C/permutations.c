#include "Header.h"

void swap(int* nums, int id1, int id2) {
	int temp = nums[id1];
	nums[id1] = nums[id2];
	nums[id2] = temp; 
}

void heapPermute(int* nums, int** permutes, int *indexPermute, int size, int n) {

	if (size == 1) {
		for (int i = 0; i < n; i++)
			permutes[*indexPermute][i] = nums[i];
		(*indexPermute)++;
		printArray(nums, n);
		return;
	}
	for (int i = 0; i < size; i++) {
		heapPermute(nums, permutes, indexPermute, size - 1, n);

		if (size % 2 == 0) {
			swap(nums, 0, size - 1);
		}
		else {
			swap(nums, i, size - 1);
		}
	}

}



int** permute(int* nums, int numsSize, int* returnSize, int **returnColumnSize) {

	int i;
	for (i = 1, *returnSize = 1; i <= numsSize; i++)
		*returnSize *= i;


	int indexPermute = 0;
	*returnColumnSize = (int*)malloc(sizeof(int) * *returnSize);
	int** res = (int**)malloc(sizeof(int*) * (*returnSize));
	for (i = 0; i < *returnSize; i++) {
		(*returnColumnSize)[i] = numsSize;
		res[i] = (int*)malloc(sizeof(int) * numsSize);
	}

	heapPermute(nums, res, &indexPermute, numsSize, numsSize);
	return res;

}

//void main() {
//
//	int returnSize = 0;
//	int tab[] = { 1, 2, 3 };
//	int* columnSize = NULL;
//	int** res = permute(tab, 3, &returnSize, &columnSize);
//
//
//	for (int i = 0; i < returnSize; i++) {
//		free(res[i]);
//	}
//	free(res);
//}