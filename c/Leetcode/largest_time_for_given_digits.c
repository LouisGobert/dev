#include "Header.h"


/*char* largestTimeFromDigits(int* arr, int arrSize) {

	int hMax = 0, mMax = -1;
	int msbHmax = -1, lsbHmax, i, x;
	char* res = malloc(sizeof(char) * 6);
	res[0] = 'x';
	// Get max hours
	for (i = 0; i < 3; i++) {
		for (x = i + 1; x < 4; x++) {
			if ((arr[i] * 10) + arr[x] < 24 && (arr[i]*10) + arr[x] >= hMax) {
				hMax = (10*arr[i]) + arr[x];
				msbHmax = i;
				lsbHmax = x;
			} 
			
			if((arr[x] * 10) + arr[i] < 24 && (arr[x] * 10) + arr[i] >= hMax) {
				hMax = arr[i] + (arr[x]*10);
				lsbHmax = i;
				msbHmax = x;
			}
		}
	}

	if (msbHmax == -1) {
		res[0] = '\0';
		return res;
	}
		
	res[0] = arr[msbHmax] + '0';
	res[1] = arr[lsbHmax] + '0';
	res[2] = ':';
	
	// Get max minutes
	for (i = 0; i < 3; i++) {
		for (x = i+1; x < 4; x++) {
			if (i != msbHmax && i != lsbHmax && x != msbHmax && x != lsbHmax) {

				if ((10 * arr[i] + arr[x]) < 60) {
					mMax = (10 * arr[i]) + arr[x];
					res[3] = arr[i] + '0';
					res[4] = arr[x] + '0';
				}

				if ((10 * arr[x]) + arr[i] < 60 && (10 * arr[x]) + arr[i] > mMax) {
					mMax = 1;
					res[3] = arr[x] + '0';
					res[4] = arr[i] + '0';
				}
				if (mMax == -1) {
					res[0] = '\0';
					return res;
				}

				res[5] = '\0';
				return res;
			}
		}
	}

	return res;

}*/



char* largestTimeFromDigits(int* arr, int arrSize) {

	int pos[24][4] =
	{	{0, 1, 2, 3},
		{0, 1, 3, 2},
		{0, 2, 1, 3},
		{0, 2, 3, 1},
		{0, 3, 1, 2},
		{0, 3, 2, 1},

		{1, 0, 2, 3},
		{1, 0, 3, 2},
		{2, 0, 1, 3},
		{2, 0, 3, 1},
		{3, 0, 1, 2},
		{3, 0, 2, 1},

		{1, 2, 0, 3},
		{1, 3, 0, 2},
		{2, 1, 0, 3},
		{2, 3, 0, 1},
		{3, 1, 0, 2},
		{3, 2, 0, 1},

		{1, 2, 3, 0},
		{1, 3, 2, 0},
		{2, 1, 3, 0},
		{2, 3, 1, 0},
		{3, 1, 2, 0},
		{3, 2, 1, 0}
	};

	char* res = malloc(sizeof(char) * 6);
	int i, x;
	int maxHeure = -1, maxMinute = -1, heure, minute;

	for (i = 0; i < 24; i++) {

		heure = (arr[pos[i][0]] * 10) + arr[pos[i][1]];
		minute = (arr[pos[i][2]] * 10) + arr[pos[i][3]];

		// Heure valide trouvée
		if (heure < 24 && minute < 60) {
			if (heure > maxHeure) {
				maxHeure = heure;
				maxMinute = minute;
			}
			else if (heure == maxHeure && minute > maxMinute) {
				maxHeure = heure;
				maxMinute = minute;
			}
			
		}
	}

	if (maxHeure != -1) {
		if (maxHeure < 10)
			res[0] = '0';
		else
			res[0] = (maxHeure / 10) + '0';

		res[1] = (maxHeure % 10) + '0';
		res[2] = ':';
		if (maxMinute < 10)
			res[3] = '0';
		else
			res[3] = (maxMinute / 10) + '0';

		res[4] = (maxMinute % 10) + '0';
		res[5] = '\0';

		return res;
	}
	else {
		res[0] = '\0';
		return res;
	}

}
//
//void main() {
//
//	int tab[] = {1, 2, 3, 4 };
//
//	char* res = largestTimeFromDigits(tab, 4);
//	printf("Res : %s", res);
//	free(res);
//}