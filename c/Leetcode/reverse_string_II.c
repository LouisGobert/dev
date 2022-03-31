#include <stdio.h>
#include <string.h>


/*Given a string and an integer k, you need to reverse the first k characters for 
every 2k characters counting from the start of the string. If there are less than k characters left,
reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters 
and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"*/

void reverseStrings(char* str, int s, int e) {

	char t;
	while (s < e)
	{
		t = str[s];
		str[s] = str[e];
		str[e] = t;
		s++;
		e--;
	}
}


char* reverseStr(char* s, int k) {
	int ln = strlen(s), i = 0;

	while (i+k < ln)
	{
		// reverse
		reverseStrings(s, i, i + k-1);
		i += k * 2;
	}

	i -= k;

	if (i + k < ln)
		reverseStrings(s, i, ln - 1);
	else
		reverseStrings(s, i, k - 1);

}
