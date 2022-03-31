#include "Header.h"

char findTheDifference(char* s, char* t) {

	int i = 0;
	int sumS = 0, sumT = 0;
	while (s[i] != '\0')
	{
		sumS += s[i];
		sumT += t[i];

		i++;
	}

	sumT += t[i];

	return sumT - sumS;
}

//void main() {
//
//
//	char s1[] = "abcd";
//	char s2[] = "abcde";
//
//	char res = findTheDifference(s1, s2);
//}