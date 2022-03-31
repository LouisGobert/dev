#include "Header.h"



int removeDuplicatesII(int* nums, int numsSize) {

	int i, pos = 0;
	for (i = 0; i < numsSize; i++) {
		nums[pos] = nums[i];
		printf("val : %d pos : %d\n", nums[pos], pos);
		if (i+1 < numsSize && nums[pos] == nums[i+1]) {

			nums[++pos] = nums[++i];
			printf("val : %d pos : %d\n", nums[pos], pos);
			
			while (i + 1 < numsSize && nums[i+1] == nums[pos]) {
				i++;
			}
			

			
		}
		pos++;
	}

	return pos;
}
//
//void main() {
//	int test[] = { 1, 1, 3, 4, 5, 5, 5, 8 };
//
//
//	int res = removeDuplicates(test, 8);
//	printArray(test, res);
//}