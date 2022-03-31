#include "Header.h"


int thirdMax(int* nums, int numsSize) {
	int first = nums[0], second = nums[0], max = nums[0];

	for (int i = 0; i < numsSize; i++) {
		if (nums[i] > max) {
			first = second;
			second = max;
			max = nums[i];
		}
		else if (nums[i] < max && nums[i] > second || second == max) {
			first = second;
			second = nums[i];

		}
		else if (nums[i] < second && nums[i] > first || first == second || first == max)
			first = nums[i];

	}

	if (first != second && second != max)
		return first;
	return max;
}

//void main() {
//	int test[] = { 3, 2, 1 };
//	int res = thirdMax(test, 3);
//}