#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*
 * Fonction qui vide le buffer pour permettre 
 * une relecture des carract�res correcte.
 *
 */
void viderBuffer() {
	int c = 0;

	// EOF = End Of File
	while (c != '\n' && c != EOF) {
		c = getchar();
	}
}

void lireString(char *chaine, int longueur) {
	setlocale(LC_ALL, "");
	char* posRetourLigne = NULL;
	int saisie = 0; // 0 = pas encore fait 
					// 1 = fait et correct 
					// 2 = fait et faut

	do {
		if (saisie == 2) printf("Le nombre de carract�re ne peux ex�der %d!\nMerci de recommencer : ", longueur);

	

		if (fgets(chaine, longueur, stdin) != NULL) {
			posRetourLigne = strchr(chaine, '\n'); // On recherche l'entr� du \n
			if (posRetourLigne != NULL) {
				*posRetourLigne = '\0';
				saisie = 1;
			}
			else {
				viderBuffer();
				saisie = 2;
			}
		}
		else {
			viderBuffer();
			saisie = 2;
		}
	} while (saisie == 0 || saisie == 2);

}

long lireLong() {

	char texte[100] = { 0 };

	lireString(texte, 100); 

	return strtol(texte, NULL, 10); // base 10
	
}
