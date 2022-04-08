#include "Header.h"



bool isAnagram(char* s, char* t) {

	int* count = calloc(27, sizeof(int));
	int i = 0;
	while (s[i] != '\0' && t[i] != '\0')
	{
		count[s[i] - 'a']++;
		count[t[i] - 'a']--;
		i++;
	}

	if (s[i] == '\0' && t[i] != '\0' || s[i] != '\0' && t[i] == '\0') {
		free(count);
		return false;
	}
	for (i = 0; i < 27; i++) {
		if (count[i] != 0) {
			free(count);
			return false;
		}

	}

	free(count);
	return true;
}
//
//void main() {
//	char* test =   "anagram";
//	char* testtt = "nagaaam";
//	bool res = isAnagram(test, testtt);
//
//}