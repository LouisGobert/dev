#include "Math.h"


int factorielle(int nb) {
	if (nb < 0)
		return 0;
	int fct = 1, i;
	for (i = 2; i <= nb; i++)
		fct *= i;

	return fct;
}