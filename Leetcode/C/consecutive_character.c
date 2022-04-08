#include "Header.h"


int maxPower(char* s) {
	int power[26] = { 0 };

	int i = 0, cpt = 0, ch = s[0], max = INT_MIN;
	while (s[i] != '\0')
	{
		if (s[i] == ch) {
			cpt++;
		}
		else {
			if (cpt > power[ch - 'a']) {
				power[ch - 'a'] = cpt;
				if (max < cpt)
					max = cpt;
			}

			ch = s[i];
			cpt = 1;

			
		}

		i++;
	}

	if (cpt > power[ch - 'a']) {
		power[ch - 'a'] = cpt;
		if (max < cpt)
			max = cpt;
	}


	/*cpt = 0;
	for (i = 0; i < 26; i++)
		if (cpt < power[i])
			cpt = power[i];*/

	return max;
}


//void main() {
//
//	char s[] = "leetcode";
//
//	int res = maxPower(s);
//
//}