#include "Header.h"



bool isPalindromeee(char* s) {
	int start = 0, end = strlen(s) - 1;
	if (end == -1)
		return true;

	while (start <= end)
	{
		// Tester si les lettres sont égale
		// On va vers la gauche jusqu'a trouvé une lettre
		while (!isalnum(s[start]) && s[start] != '\0')
		{
			start++;
		}
		if (s[start] == '\0')
			return true;

		// On va vers la gauche jusqu'a trouvé une lettre
		while (!isalnum(s[end]) && s[end] >= 0)
			end--;

		if (tolower(s[start]) != tolower(s[end]))
			return false;

		start++;
		end--;
	}

	return true;
}


//void main() {
//	char* test = "0P";
//	bool res = isPalindromeee(test);
//}
