#include "string_util.h"

char* reverseWords(char* str) {

	int i = 0, s = 0, e;

	while (str[i] != '\0') {
		if (str[i] == ' ') {
			reverseString(str, s, i - 1);
			s = i + 1;
		}
		i++;
	}
	// last execute
	reverseString(str, s, i - 1);


	return str;
}


