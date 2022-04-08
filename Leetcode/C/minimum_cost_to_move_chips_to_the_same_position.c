#include "Header.h"


int minCostToMoveChips(int* position, int positionSize) {

	// odd = impaire
	int even = 0, i;


	for (i = 0; i < positionSize; i++)if (position[i] % 2 == 0)	even++;

	if (even == 0 || positionSize-even == 0)
		return 0;

	return (even > positionSize-even) ? positionSize-even : even;

	
}
//
//void main() {
//	
//	int tab[] = { 1,2,3 };
//
//	int res = minCostToMoveChips(tab, 3);
//
//
//}