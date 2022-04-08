#include "Header.h"


char* decodeAtIndex(char* S, int K) {

	char* string = malloc(sizeof(char) * (K + 10));
	printf("size = %d\n", K + 10);
	long sIndex = 0, i = 0, mul = 0, temp = 0, indexStart = 0, indexStop = 0;


	while (S && S[i] != '\0')
	{
		if (isalpha(S[i])) {
			string[sIndex++] = S[i++];
			if (sIndex == K) {
				S[0] = string[sIndex - 1];
				S[1] = '\0';
				free(string);
				return &S[0];

			}
		}
		else {

			mul = 0;
			indexStop = sIndex;
			while (S[i] != '\0' && isdigit(S[i]))
			{
				mul *= 10;
				mul += S[i] - '0';
				i++;
			}
			// Multiplication de string par mul

			for (temp = 0; temp < mul - 1; temp++) {

				for (indexStart = 0; indexStart < indexStop; indexStart++) {
					string[sIndex++] = string[indexStart];
					if (sIndex == K) {
						S[0] = string[sIndex - 1];
						S[1] = '\0';
						free(string);
						return &S[0];

					}
				}
			}

		}
	}
	return &S[0];

}


//void main() {
//	char test[] = "vzpp636m8y";
//
//	char* res = decodeAtIndex(test, 2920);
//	printf("%c", *res);
//}