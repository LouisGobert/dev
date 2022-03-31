#include "Header.h"

int smallestDivisor(int* nums, int numsSize, int threshold) {

	int i, max = INT_MIN;
	for (i = 0; i < numsSize; i++)
		if (nums[i] > max)
			max = nums[i];



	int sPos = 0, ePos = max;
	int divisor; // 4
	int minima = -1;

	int thresholdObtain = 0;
	// max = 9
	// mid = 4
	while (sPos <= ePos) {

		divisor = (sPos + ePos) / 2;
		// Sum all / by mid
		// find the num or num >
		if (divisor == 0)
			divisor++;


		for (i = 0, thresholdObtain = 0; i < numsSize; i++)
			thresholdObtain += ceil((double)nums[i] / divisor);

		if (thresholdObtain > threshold) {
			sPos = divisor + 1;
			if (sPos > ePos)
				return minima;

		}
		else if (thresholdObtain <= threshold && divisor > 1) {
			// On a trouvé un mais on cherche plus petit
			ePos = divisor - 1;
			minima = divisor;
		}
		else {
			return divisor;
		}
	}


	return divisor;

}





//
//void main() {
//
//	int tab[] = { 1, 2, 5, 9 };
//	int tab2[] = { 2,3,5,7,11 };
//	int tab3[] = { 19 };
//
//	int tab4[] = { 16,79,6,43,53 };
//	int tab5[] = { 9, 63, 69, 43, 95, 11, 7 };
//	int tab6[] = { 909771,973275,979226,934386,981517 };
//
//	int small = smallestDivisor(tab, 4, 6); // 5
//	int s1 = smallestDivisor(tab2, 5, 11);  // 3
//	int s2 = smallestDivisor(tab3, 1, 5);   // 4
//	int sfinal = smallestDivisor(tab4, 5, 172);
//	int sss = smallestDivisor(tab5, 7, 302);
//	int rr = smallestDivisor(tab6, 5, 10); // 490759
//
//}