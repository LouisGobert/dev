#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
// Converti un nombre hex en binaire
int hexToDecimal(int hex0, int hex1) {

	// si hex n'est pas en a b c d e f
	int somme = 0;
	if (hex0 <= 57) {
		somme += (hex0 - 48) * 16;
	}
	else {
		somme += (10 + (hex0 - 97))* 16;
	}

	if (hex1 <= 57) {
		somme += (hex1 - 48);
	}
	else {
		somme += (10 + (hex1 - 97));
	}

	return somme;
}

long decToBinary(int dec) {
	int k = 0;
	long binary = 0;
	for (int i = 7; i >= 0; i--) {
		k = dec >> i;

		if (k & 1)
			binary += 1 * pow(10, i);
		
	}
	
	return binary;
}

int trameAnalyse(long tab[], int octet) {
	int order[5] = {6, 6, 2, octet - 18, 4 };
	char format[][50] = {{"Adresse de destination"} , {"Adresse source"}, {"Protocole de couche 3"}, {"Donn�e"}, {"CRC"} };

	int pos = 0;

	for (int i = 0; i < 5; i++) {
		printf("\n\n%s\n", format[i]);
		for (int x = 0; x < order[i]; x++) {
			printf("%08d  ", tab[pos]);
			pos++;
		}
	}

}

int main()
{
	printf("Startting trame annalyser\n\n");
	FILE* fichier = NULL;
	int bit0 = 0;
	int bit1 = 0;
	int dec = 0;
	long bin = 0;
	long tab[209] = { 0 };
	char donnee[200] = {0};
	int posdonnee = 0;

	// Variable stockant le nombre d'octet trouv�
	int nbOfOctet = 0;

	fichier = fopen("hex.txt", "r");

	if (fichier != NULL) {

		do {

			// Permet de n'obtenir que les int qui ne sont pas des espaces ni des retour chariot
			
			do {
				bit0 = fgetc(fichier);
			} while (bit0 == 32 || bit0 == 10);
			bit1 = fgetc(fichier);
			
			
			
			// Si EOF au bit0 on stop la boucle
			if (bit0 == EOF || bit1 == EOF)
				break;
			
			printf("%c%c ", bit0, bit1);
			// Calcul de leur valeur en d�cimal
			dec = hexToDecimal(bit0, bit1);
			if (nbOfOctet > 13) {
				donnee[posdonnee] = dec;
				posdonnee++;
			}
			bin = decToBinary(dec);

			tab[nbOfOctet] = bin;
			nbOfOctet += 1;

			// Ajout du long au tableau
			
		} while (bit0 != EOF|| bit1 != EOF);

		fclose(fichier);
	}
	else {
		printf("Erreur lors de l'ouverture du fichier");
	}

	printf("\nNombre d'octet trouv� : %d", nbOfOctet);
	for (int i = 0; i < 200; i++)
		printf("%c", donnee[i]);
	trameAnalyse(tab, nbOfOctet);

	scanf("");
	
}

/*
	FF = 1 octet
*/
