#include "Header.h"


int* getRow(int rowIndex, int* returnSize) {

	int* array_true =  (int*)malloc(sizeof(int) * (rowIndex+1));
	int* array_false = (int*)malloc(sizeof(int) * (rowIndex+1));

	
	array_true[0] = 1;
	array_false[0] = 1;
	
	bool arrChoice = false;
	
	

	for (int i = 1, t; i < rowIndex + 1; i++) {
		
		// On copie dans le tableau false
		if (arrChoice) {
			for (t = 1; t < i; t++)
				array_false[t] = array_true[t] + array_true[t - 1];

			//array_false[0] = 1;
			array_false[i] = 1;
			arrChoice = false;
		}
		else {
			for (t = 1; t < i; t++)
				array_true[t] = array_false[t] + array_false[t - 1];
			array_true[i] = 1;
			arrChoice = true;
		}
	}


	*returnSize = rowIndex + 1;
	//printArray(array_false, 6);

	if (!arrChoice) {

		free(array_true);
		return array_false;
	}

	free(array_false);
	return array_true;
	

}


//void main() {
//
//	int rSize = 0;
//
//	int* res = getRow(4, &rSize);
//	
//	for (int x = 0; x < rSize; x++) {
//			printf("%d ", res[x]);
//	}
//
//	free(res);
//
//}