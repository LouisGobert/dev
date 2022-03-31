#include "Header.h"
#include "array.h"


void moveZeroes(int* nums, int numsSize) {

	int pos = 0, i = 0;
	while (pos < numsSize)
	{
		if (nums[pos] != 0) {
			nums[i] = nums[pos];
			i++;
		}
		pos++;
	}

	// Copy the 0 a the end
	for (pos = numsSize - 1; pos >= i; pos--)
		nums[pos] = 0;
}

//
//void main() {
//
//	int tab[5] = { 0,1,0,3,12 };
//
//	moveZeroes(tab, 5);
//	
// 
//}