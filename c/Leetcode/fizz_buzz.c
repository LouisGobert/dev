#include "Header.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
	*returnSize = n;
	char** tab = malloc(sizeof(int*) * n);


	for (int i = 1; i < n + 1; i++) {
		tab[i - 1] = malloc(sizeof(char) * (15));
		if (i % 3 == 0 && i % 5 == 0) {
			sprintf(tab[i - 1], "FizzBuzz\0");
		}
		else if (i % 3 == 0)
			sprintf(tab[i - 1], "Fizz\0");
		else if (i % 5 == 0)
			sprintf(tab[i - 1], "Buzz");
		else
			sprintf(tab[i - 1], "%d\0", i);
	}

	return tab;

}

//void main() {
//
//	int r = 0;
//	char** res = fizzBuzz(100, &r);
//	int i;
//	for (i = 0; i < r; i++)
//		printf("%s\n", res[i]);
//
//	for (i = 0; i < r; i++)
//		free(res[i]);
//
//	free(res);
//}