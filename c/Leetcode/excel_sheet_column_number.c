#include "Header.h"




int titleToNumber(char* s) {
	int len = strlen(s);

	int value = 0;
	for (int i = len - 1; i >= 0; i--) {
		value += (s[i] - 'A' +1 ) * pow(26, len-1 - i);
	}

	return value;
}



//void main() {
//	char* test = "AA";
//	int res = titleToNumber(test);
//}
