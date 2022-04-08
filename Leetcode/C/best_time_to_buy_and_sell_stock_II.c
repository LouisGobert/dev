#include "Header.h"
#include "array.h"




int maxProfit(int* prices, int pricesSize) {
	int profit = 0, i;
	for (i = 1; i < pricesSize; i++) {

		// On vend
		if (prices[i] > prices[i - 1]) {
			profit += prices[i] - prices[i - 1];
		}
	}
	return profit;
}

//
//void main() {
//
//	int tab[7] = { 7,1,5,3,6,4};
//
//
//
//	int p = maxProfit(tab, 7);
//
//}