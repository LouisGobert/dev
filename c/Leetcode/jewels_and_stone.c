#include "Header.h"

int numJewelsInStones(char* J, char* S) {
	int jewel = 0, i = 0, x;
	
	while (J[i] != '\0')
	{
		x = 0;
		while (S[x] != '\0')
		{
			if (S[x] == J[i])
				jewel++;

			x++;
		}
		i++;
	}

	return jewel;
}
