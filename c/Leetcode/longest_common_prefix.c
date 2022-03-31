#include "Header.h"


char* longestCommonPrefix(char** strs, int strsSize) {

	if (strsSize == 0 || strs[0][0] == '\0')
		return "";
	else if (strsSize == 1)
		return strs[0];
	
	
	char* prefix = malloc(sizeof(char) * (strlen(strs[0])+1));

	int index = 0, i, ch;
	while (strs[0][index] != '\0')
	{
		ch = strs[0][index];

		for (i = 1; i < strsSize; i++) {
			if (strs[i][index] != ch) {
				prefix[index] = '\0';
				if (index == 0)
					return "";
				return prefix;
			}
		}

		prefix[index] = ch;
		index++;
	}
	prefix[index] = '\0';
	return prefix;

}

//void main() {
//
//	char** strs = malloc(sizeof(char*) * 4);
//
//	char* s1 = "flower";
//	char* s2 = "flower";
//	char* s3 = "flower";
//	char* s4 = "flower";
//
//	strs[0] = s1;
//	strs[1] = s2;
//	strs[2] = s3;
//	strs[3] = s4;
//
//
//	char* res = longestCommonPrefix(strs, 4);
//	free(res);
//
//}