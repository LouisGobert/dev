// GOBERT Louis
// E180596
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

typedef enum jour {LUNDI, MARDI, MERCREDI} jour;

typedef struct { 
	int jour; 
	int mois;
	int annee;
} date;

typedef struct {
	char nom[30];
	char prenom[30];
	date anniv;
	float moyenne;

} personne;

void afficherTableau(const int tab[], int x, int y) {
	for (int i = 0, ii; i < x; i++)
		for (ii = 0; ii < y; ii++)
			printf("%d, ", tab[(i * x) + ii]);
}

void viderBuffer() {
	int c = 0;
	while (c != '\n') c = getchar();
}

// D�claration des fonctions
bool ecrireObjDirect(personne pers); 
bool ecrireObjPtr(personne* pers);
void lirePersonnePtr(personne* pers);
void afficherPersonnePtr(personne* pers);

void main() {

	setlocale(LC_ALL, "");
	//jour l;
	//date dt = { 11, 10, 2000 };
	//printf("%02d/%02d/%04d", dt.jour, dt.mois, dt.annee);

	//int tab[4];

	//for (int i = 0; i < 4; i++) {
	//	printf("Entrer la valeur %d : ", i + 1);
	//	//scanf("%d", &tab[i]);
	//	//viderBuffer();
	//}


	//int tab2d[3][3] = { {1,2,3},{4, 5, 6}, {7, 8, 9} };

	//float cotes[3][3];

	//for (int i = 0; i < 3; i++) {
	//	for (int x = 0; x < 3; x++) {
	//		printf("Cotes %d n%d : ", i + 1, x + 1);
	//		//scanf("%f", &cotes[i][x]);
	//		//viderBuffer();
	//	}
	//}

	//afficherTableau(tab2d, 3, 3);
	//printf("Entrer une phrase : ");
	//char phrase[50];
	////gets(phrase);


	//printf("Votre phrase : %s", phrase);


	//// Pour aligner le texte correctement
	//printf("\ntest alignage %d", 99);
	//printf("\ntest alig %6d", 919);

	//////////////////////////////////////////////////////
	///													//
	///				PARTIE FICHIER						//
	///													//
	//////////////////////////////////////////////////////

	//////////////////////////////////////
	/// Afficher tout les caract�res	//
	//////////////////////////////////////
	printf("Lecture du fichier caract�re par caract�re : \n");

	FILE* fichier;
	fichier = fopen("test.txt", "r");
	if (fichier == NULL)
		return EXIT_FAILURE;
	
	
	int c;
	while ((c = fgetc(fichier)) != EOF)
	{
		printf("%c", c);
	}
	fclose(fichier);

	//////////////////////////////////////
	/// Afficher tout ligne par ligne	//
	//////////////////////////////////////
	printf("\nLecture du fichier ligne par ligne : \n");

	fichier = fopen("test.txt", "r");
	if (!fichier)
		return EXIT_FAILURE;

	char buffer[100];
	
	while (fgets(buffer, 100, fichier))
	{
		printf("%s", buffer);
	}

	fclose(fichier);

	//////////////////////////////////////
	///		Lire avec formatage			//
	//////////////////////////////////////
	printf("\nLecture du fichier avec formatage : \n");

	char nom[2][30];
	char fin[2][4];
	date anniv[2];

	fichier = fopen("log.txt", "r");

	if (!fichier)
		return EXIT_FAILURE;

	int i = 0;
	
	while (fgets(buffer, 100, fichier))
	{
		sscanf(buffer, "%s %d/%d/%d", nom[i], &anniv[i].jour, &anniv[i].mois, &anniv[i].annee);
		printf("%s", buffer);
		i++;
	}
	fclose(fichier);

	//////////////////////////////////////
	///Ecriture dans un fichier binaire //
	//////////////////////////////////////

	fichier = fopen("dateLog.txt", "wb");
	if (!fichier)
		return EXIT_FAILURE;

	// 2 car que 2 anniv dans le tableau
	fwrite(anniv, sizeof(date), 2, fichier);

	fclose(fichier);


	//////////////////////////////////////
	///Lecure dans un fichier binaire   //
	//////////////////////////////////////
	fichier = fopen("dateLog.txt", "rb");
	if (!fichier)
		return EXIT_FAILURE;

	// 2 car que 2 anniv dans le tableau
	date nouvAnniv[2];
	int nbAnniv;
	nbAnniv = fread(nouvAnniv, sizeof(date), 2, fichier);

	fclose(fichier);



	//////////////////////////////////////
	///		Ecrire avec formatage	    //
	//////////////////////////////////////

	/* Sh�ma : 
	* 
	* Gobert Louis
	* 11/10/2000
	* 19.34/20
	
	*/

	// Cr�ation de la persone et de la date
	date anniv_louis = { 11, 10, 2000 };
	date anniv_athe = { 14, 10, 2000 };
	personne louis = { "Gobert", "Louis", anniv_louis, 19.234234 };
	personne athe = { "Foxhal", "Ath�nais", anniv_athe, 13.23 };
	
	if (!ecrireObjDirect(louis))
		return EXIT_FAILURE;

	if (!ecrireObjPtr(&athe))
		return EXIT_FAILURE;


	//////////////////////////////////////////////////////////////
	///		Lecture d'un fichier et stockage dans object	    //
	//////////////////////////////////////////////////////////////

	personne temp;
	strcpy(temp.nom, "Gobert");

	lirePersonnePtr(&temp);
	afficherPersonnePtr(&temp);
	
	strcpy(temp.nom, "Foxhal");
	lirePersonnePtr(&temp);
	afficherPersonnePtr(&temp);


	//////////////////////////////////////////////////////////////
	///				Acquitition d'une date	et affichage	    //
	//////////////////////////////////////////////////////////////

	date dateTemp;
	printf("\nEntrer la date d'anniv xx/xx/xx : ");
	scanf(" %d/%d/%d", &dateTemp.jour, &dateTemp.mois, &dateTemp.annee);

	char test;
	getchar();

	printf("Tu es n� le %d/%d/%d\n", dateTemp.jour, dateTemp.mois, dateTemp.annee);

	printf("\nEntrer la date d'anniv de louis xx/xx/xx : ");
	scanf(" %d/%d/%d", &dateTemp.jour, &dateTemp.mois, &dateTemp.annee);
	printf("Tu es n� le %d/%d/%d\n", dateTemp.jour, dateTemp.mois, dateTemp.annee);
	getchar();

	//////////////////////////////////////////////////////////////
	///				Acquitition d'un seul caract�re			    //
	//////////////////////////////////////////////////////////////

	printf("\nLecture du caract�re : ");
	char ch;
	ch = getchar();

	return;
	
}

// Ecriture d'un fichier, on le cr�e ou si il existe on l'�crase 
// avec l'objet sans pointeur
bool ecrireObjDirect(personne pers) {

	// 30 + 4 pour .txt
	char nomFichier[30 + 4];
	strcpy(nomFichier, pers.nom);


	FILE* fichier = fopen(strcat(nomFichier, ".txt"), "w");
	if (!fichier)
		return false;

	fprintf(fichier, " %s %s\n%d/%d/%d\n%.2f", pers.nom, pers.prenom, pers.anniv.jour, pers.anniv.mois, pers.anniv.annee, pers.moyenne);

	fclose(fichier);
	return true;

}

// Ecriture d'un fichier, on le cr�e ou si il existe on l'�crase
// avec le pointeur de l'objet
bool ecrireObjPtr(personne *pers) {

	// 30 + 4 pour .txt
	char nomFichier[30 + 4];
	strcpy(nomFichier, pers->nom);


	FILE* fichier = fopen(strcat(nomFichier, ".txt"), "w");
	if (!fichier)
		return false;

	fprintf(fichier, "%s %s\n%d/%d/%d\n%.2f\n", pers->nom, pers->prenom, pers->anniv.jour, pers->anniv.mois, pers->anniv.annee, pers->moyenne);

	fclose(fichier);
	return true;

}


void lirePersonnePtr(personne *pers) {
	// 30 + 4 pour .txt
	char nomFichier[30 + 4];
	strcpy(nomFichier, pers->nom);
	printf("\nLecture des informations concernant %s :\n", nomFichier);


	FILE* fichier = fopen(strcat(nomFichier, ".txt"), "r");
	if (!fichier) {
		printf("Erreur de lecture.\n");
		return EXIT_FAILURE;
	}

	fscanf(fichier, "%s %s\n%d/%d/%d\n%f", &pers->nom, &pers->prenom, &pers->anniv.jour,
		&pers->anniv.mois, &pers->anniv.annee, &pers->moyenne);


	fclose(fichier);
}

void afficherPersonnePtr(personne* pers) {

	printf("\n\nAffichage des donn�es de : %s %s\nDate de naissance : %d/%d/%d\nMoyenne : %.2f\n",
		pers->nom, pers->prenom, pers->anniv.jour, pers->anniv.mois, pers->anniv.annee, pers->moyenne);
}
