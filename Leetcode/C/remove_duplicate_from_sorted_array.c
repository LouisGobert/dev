#include "Header.h"


int removeDuplicates(int* nums, int numsSize) {

	
	int i = 0, pos = 0;
	while (i < numsSize)
	{
		nums[pos++] = nums[i];
		
		while (i+1 < numsSize && nums[i + 1] == nums[pos - 1])
			i++;

		i++;
	}
	return pos;
}

//void main() {
//	int test[] = { 1, 1, 2 };
//	
//	int res = removeDuplicates(test, 3);
//	printArray(test, res);
//}