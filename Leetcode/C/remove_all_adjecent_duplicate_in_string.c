#include "Header.h"



char* removeDuplicatess(char* s) {

	bool haveDupli;

	do {
		haveDupli = false;
		int i = 0, pos = 0;
		char t;

		while (s[i] != '\0' && s[pos - 1] != '\0')
		{
			if (s[i] == s[i + 1]) {
				haveDupli = true;
				i++;
				t = s[i];
				while (s[i] != '\0' && s[i + 1] != '\0' && s[i] == s[i + 1])
				{
					i++;
				}
				i++;
			}
			else
				s[pos++] = s[i++];
		}

		s[pos] = '\0';
	} while (haveDupli);

	return s;
}



//void main() {
//	char S[] = "abbaca";
//	removeDuplicatess(S);
//}