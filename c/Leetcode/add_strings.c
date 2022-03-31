#include "Header.h"

void reverseStrrr(char* str, int e) {

	char t;

	int s = 0;
	while (s < e)
	{
		t = str[s];
		str[s] = str[e];
		str[e] = t;
		s++;
		e--;
	}
}

char* addStrings(char* num1, char* num2) {
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	reverseStrrr(num1, len1-1);
	reverseStrrr(num2, len2-1);
	char* res = malloc(sizeof(char) * (max(len1, len2) + 2));
	int n1, n2;
	int i = 0, carry = 0;
	while (i < len1 || i < len2)
	{
		if (i < len1 && i < len2) {
			n1 = num1[i] - '0';
			n2 = num2[i] - '0';
			res[i] = ((n1 + n2 + carry) % 10) + '0';
			if (n1 + n2 + carry > 9)
				carry = 1;
			else
				carry = 0;
		}
		else if (i < len1) {
			n1 = num1[i] - '0';
			res[i] = ((n1 + carry)%10) + '0';
			if (n1+carry > 9) 
				carry = 1;
			else
				carry = 0;
		}
		else {
			n2 = num2[i] - '0';
			res[i] = ((n2 + carry) % 10) + '0';
			if (n2 + carry > 9)
				carry = 1;
			else
				carry = 0;
		}

		i++;
	}

	if (carry) 
		res[i++] = '1';
	
	res[i] = '\0';
	reverseStrrr(res, i-1);
	return res;
	

}


//void main() {
//
//	char s1[] = "1";
//	char s2[] = "9";
//
//	char* res = addStrings(s1, s2);
//
//	printf("%s", res);
//	free(res);
//}