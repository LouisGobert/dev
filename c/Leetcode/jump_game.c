#include "Header.h"

//bool indexExplored[30000] = { false };

bool jumpHelper(int* nums, int size, int index) {

	if (index < 0 || index >= size || nums[index] == 0)
		return false;

	if (index == size-1 || jumpHelper(nums, size, index + nums[index]))
		return true;

	nums[index]--;
	while (nums[index] > 0 && !jumpHelper(nums, size, index + nums[index]))
		nums[index]--;
	
	if (!nums[index])
		return false;
	return true;
		
	
	
}

bool canJump(int* nums, int numsSize) {

	return jumpHelper(nums, numsSize, 0);
}

//void main() {
//
//	int tab[] = { 2,3,1,1,4 };
//	int tab2[] = { 3,2,1,0,4 };
//	int tab3[] = { 2, 0 };
//	int tab4[] = { 1, 3, 2 };
//
//	bool res = canJump(tab4, 3);
//
//}