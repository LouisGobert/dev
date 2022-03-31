#include "SearchAlgorithme.h"


int binarySearch(const int* tab, const int traget, const int size) {

	int sPos = 0, ePos = size - 1, mid;

	while (sPos <= ePos) {
		// COmpter le nombre d'itération
		mid = (sPos + ePos) / 2;
		if (tab[mid] == traget)
			return mid;
		else if (tab[mid] < traget)
			sPos = ++mid;
		else
			ePos = --mid;

	}
	return -1;

}