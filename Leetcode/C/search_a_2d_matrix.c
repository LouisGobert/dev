#include "Header.h"


int binarySearchh(const int* tab, const int val, const int dim) {

	int sPos = 0, ePos = dim - 1, mid;

	while (sPos <= ePos) {
		// COmpter le nombre d'itération
		mid = (sPos + ePos) / 2;
		if (tab[mid] == val)
			return mid;
		else if (tab[mid] < val)
			sPos = ++mid;
		else
			ePos = --mid;

	}
	return -1;

}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {

	if (matrixSize == 0 || *matrixColSize == 0)
		return false;

	int endIndex = *matrixColSize - 1;

	if (matrix[0][0] > target || matrix[matrixSize-1][endIndex] < target)
		return false;

	for (int ligne = 0, col; ligne < matrixSize; ligne++) {
		if (matrix[ligne][0] > target)
			return false;
		else if (matrix[ligne][endIndex] >= target) {
			// Loop for try to find
			if (binarySearchh(matrix[ligne], target, *matrixColSize) != -1)
				return true;
			return false;
		}
	}

	return false;
}


/*
void main() {

	int** tab = (int**)malloc(sizeof(int*) * 3);
	for (int i = 0; i < 4; i++) {
		tab[i] = (int*)malloc(sizeof(int) * 4);
	}

	int tab2[3][4] = {{ 1,3,5,7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 }};
	int tab3[1][2] = { {1,3} };

	for (int ligne = 0, col; ligne < 3; ligne++) {
		
		// Loop for try to find
		for (col = 0; col < 4; col++) {
			tab[ligne][col] = tab2[ligne][col];
		}
		
	}
	int var = 4;
	bool r = searchMatrix(tab, 3, &var, 3);
}

*/