#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>

struct code {
	char lettre;
	char code[4 + 1];
};

main() {
	// Sp�cifier l'environnement linguistique
	setlocale(LC_ALL, "");

	struct code table[26] = { {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H',"...."},
	{'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},	{'Q', "--.-"}, {'R', ".-."},
	{'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."} };

	char texte[25 + 1];
	int i=0, j;

	printf("Entrez un texte (max 25 lettres majuscules) : ");
	gets(texte);
	
	while (texte[i] != '\0') {
		if (texte[i] < 'A' || texte[i] > 'Z')
			printf("???? ");
		else {
			for (j = 0; j < 26; j++) {
				if (texte[i] == table[j].lettre)
					printf("%s ", table[j].code);
			}
		}
		i++;
	};

	_getch();
}
