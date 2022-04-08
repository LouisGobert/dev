#include "Header.h"
#define max(a,b) (((a) > (b)) ? (a) : (b))
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
	
	int xx = 0, K_T = K;
	while (K_T > 0)
	{
		K_T /= 10;
		xx++;
	}
	int LENMAX = max(ASize + 1,  xx+1);
	int* tab = malloc(sizeof(int) * LENMAX);
	int tabIndex = LENMAX-1;
	int carry = 0;
	ASize--;

	while (ASize >= 0 || K > 0)
	{
		if (ASize >= 0 && K >0) {
			tab[tabIndex] = (A[ASize] + (K % 10) + carry) % 10;
			
			if (A[ASize] + (K % 10) + carry > 9)
				carry = 1;
			else
				carry = 0;

			K /= 10;
		}
		else if (ASize >= 0) {
			tab[tabIndex] = (A[ASize] + carry) % 10;
			if (A[ASize] + carry > 9)
				carry = 1;
			else
				carry = 0;

		}
		else {
			tab[tabIndex] = ((K%10) + carry) % 10;
			if (((K % 10) + carry) > 9)
				carry = 1;
			else
				carry = 0;

			K /= 10;
		}
		printf("%d\n", tab[tabIndex]);
		ASize--;
		tabIndex--;
	}

	if (carry)
		tab[tabIndex--] = 1;
	


	// Tout le tableau est utilisé
	if (tabIndex < 0) {
		*returnSize = LENMAX;
		return tab;
	} 

	*returnSize = LENMAX - tabIndex -1;
	memmove(tab, tab + ((LENMAX - (LENMAX - tabIndex) +1)), *returnSize * sizeof(int));
	return tab;
}

//void main() {
//
//	int tab[] = { 1, 2, 3, 4 };
//	int n = 1234;
//	int t2[] = { 1 };
//
//	int rS = 0;
//	int* res = addToArrayForm(t2, 1, n, &rS);
//	printArray(res, rS);
//
//	free(res);
//
//}