#include "Header.h"



bool increasingTriplet(int* nums, int numsSize) {
	if (numsSize < 2)
		return false;

	int i = 0, first = INT_MAX, second = INT_MAX;


	for (i = 0; i < numsSize; i++) {
		if (nums[i] <= first)
			first = nums[i];
		else if (nums[i] <= second)
			second = nums[i];
		else
			return true;
	}
	return false;
}


//void main() {
//	int test[] = { 9, 10, 1, 1, 1, 2, 3};
//	bool res = increasingTriplet(test, 7);
//}