#include "Header.h"


void countFromStr(char* strBase, char* strNew) {
	int num = strBase[0];
	int x = 0; // Nombre dans le groupe
	int i = 0, newIndex = 0;
	while (strBase[i] != '\0')
	{
		if (strBase[i] == num)
			x++;
		else {
			strNew[newIndex++] = x+ '0';
			strNew[newIndex++] = num;
			strNew[newIndex] = '\0';
			//printf("%s\n", strNew);

			x = 1;
			num = strBase[i];
		}

		i++;
	}

	strNew[newIndex++] = x + '0';
	strNew[newIndex++] = num;
	strNew[newIndex] = '\0';
	printf("%s\n", strNew);

	num = strBase[i];
	
}

char* countAndSay(int n) {

	char* strBase = malloc(sizeof(int) * 1000);
	char* strNew = malloc(sizeof(int) * 1000);
	strBase[0] = '1';
	strBase[1] = '\0';
	int strBaseLen = 1;
	int strNewLen = 0;


	for (int i = 0; i < n; i++) {

		if (i % 2 == 0)
			countFromStr(strBase, strNew);
		else
			countFromStr(strNew, strBase);

	}
}


//void main() {
//	char* res = countAndSay(29);
//}