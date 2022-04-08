#include <stdio.h>
#include <string.h>



char* freqAlphabets(char* s) {

	int n = 0, ln = strlen(s), val = 0, pos = 0;

	char* ch = malloc(sizeof(char) * ln / 3);

	while (n < ln)
	{
		if (n + 2 < ln && s[n + 2] == '#') {
			ch[pos] = 'a' + (((s[n] - '0') * 10 + s[n + 1])) - '0' -1;
			char x = 'a' + (((s[n] - '0') * 10 + s[n + 1])) - '0' -1;
			int xx = (s[n] - '0') * 10;
			n += 3;
		}
		
		else {
			ch[pos] = 97 + s[n] -49;
			char x = 97 + s[n] - 49;
			n++;
		}


		pos++;
	}

	ch[pos] = '\0';

	return ch;
}

