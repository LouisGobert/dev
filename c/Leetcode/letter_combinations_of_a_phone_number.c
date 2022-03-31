#include "Header.h"


char* getKeys(int n) {
	char* keys = malloc(sizeof(char) * 5);
	switch (n)
	{
	case 2: keys = "abc";	break;
	case 3: keys = "def";	break;
	case 4: keys = "ghi";	break;
	case 5: keys = "jkl";	break;
	case 6: keys = "mno";	break;
	case 7: keys = "pqrs";	break;
	case 8: keys = "tuv";	break;
	case 9: keys = "wxyz";  break;
	}

	return keys;
}

void combine(char** combination, char** digitConteneur, int digitConteneurSize, int combinationIndex, int digitConteneurIndex) {

	if (digitConteneurIndex >= digitConteneurSize)
		return;


}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
	int digitLen = strlen(digits); // = nombre de lettre dans chaque combinaison
	if (digitLen == 0) {
		*returnSize = 0;
		return NULL;
	}
	char** digitConteneur = malloc(sizeof(char*) * digitLen);

	int fourValue = 0;
	for (int i = 0; i < digitLen; i++) {
		digitConteneur[i] = getKeys(digits[i] - '0');
		if (digits[i] - '0' == 7 || digits[i] - '0' == 9)
			fourValue++;
	}

	// Combien de combinaison ?
	int nbCombi = pow(3, digitLen-fourValue);
	if (fourValue) nbCombi *= pow(4, fourValue);
	*returnSize = nbCombi;

	char** returnTab = malloc(sizeof(char*) * nbCombi);
	int indexReturnTab = 0;

	int i1 = 0, i2 = 0, i3 = 0, i4 = 0;
	while (digitConteneur[0][i1] != '\0')
	{
		i2 = 0;
		if (digitLen > 1) {
			while (digitLen > 1 && digitConteneur[1][i2] != '\0')
			{
				i3 = 0;
				if (digitLen > 2) {
					while (digitLen > 2 && digitConteneur[2][i3] != '\0')
					{
						i4 = 0;
						if (digitLen > 3) {
							while (digitLen > 3 && digitConteneur[3][i4] != '\0') {
								char* newWord = malloc(sizeof(char) * 3);
								newWord[0] = digitConteneur[0][i1];
								newWord[1] = digitConteneur[1][i2];
								newWord[2] = digitConteneur[2][i3];
								newWord[3] = digitConteneur[3][i4];
								newWord[4] = '\0';
								printf("New word : %s\n", newWord);
								returnTab[indexReturnTab++] = newWord;

								i4++;
							}
						}
						else {
							char* newWord = malloc(sizeof(char) * 3);
							newWord[0] = digitConteneur[0][i1];
							newWord[1] = digitConteneur[1][i2];
							newWord[2] = digitConteneur[2][i3];
							newWord[3] = '\0';
							printf("New word : %s\n", newWord);
							returnTab[indexReturnTab++] = newWord;
						}
						i3++;
					}
				}
				else {
					char* newWord = malloc(sizeof(char) * 3);
					newWord[0] = digitConteneur[0][i1];
					newWord[1] = digitConteneur[1][i2];
					newWord[2] = '\0';
					printf("New word : %s\n", newWord);
					returnTab[indexReturnTab++] = newWord;
				}
				i2++;
			}
		}
		else {
			char* newWord = malloc(sizeof(char) * 3);
			newWord[0] = digitConteneur[0][i1];
			newWord[1] = '\0';
			printf("New word : %s\n", newWord);
			returnTab[indexReturnTab++] = newWord;
		}
		i1++;
		
	}



	return returnTab;
}


//void main() {
//	char* test = "2222";
//	int retSize = 0;
//	char** res = letterCombinations(test, &retSize);
//	for (int i = 0; i < retSize; i++)
//		printf("Word : %s\n", res[i]);
//}