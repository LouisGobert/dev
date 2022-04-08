#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
int sudokuValidity(int sudokuCopy[9][9], int line, int row);
void resolve(int sudoku[9][9]);
void afficher(int sudoku[9][9]);
int checkBySum(int sudoku[9][9]);
void calculate(int sudoku[9][9], int index, int grillePosib[81][12]);
void getPossibility(int sudoku[9][9], int grillePosib[81][12]);


//	-----LIGNE------
// {}{}{}{}{}{}{}{}{}	|
// {}{}{}{}{}{}{}{}{}	C
// {}{}{}{}{}{}{}{}{}	O
// {}{}{}{}{}{}{}{}{}	L xxxxxxxxxxx
// {}{}{}{}{}{}{}{}{}	L y
// {}{}{}{}{}{}{}{}{}	O y
// {}{}{}{}{}{}{}{}{}	N y
// {}{}{}{}{}{}{}{}{}	E y
// {}{}{}{}{}{}{}{}{}	|


main()
{
	int sudoku[9][9] = { {0,0,0,4,7,0,8,5,0},
							{7,0,0,0,0,0,0,4,0 },
							{0,0,0,8,9,0,0,0,0 } ,
							{0,0,0,0,0,0,0,2,1 } ,
							{0,0,0,0,1,3,0,0,0 } ,
							{5,4,0,0,0,0,0,0,0 } ,
							{0,0,9,0,0,0,0,0,0 } ,
							{0,0,8,0,0,0,6,0,9 } ,
							{0,6,0,5,2,0,0,0,0 } };

	resolve(sudoku);
}


void resolve(int sudoku[9][9]) {

	int grillePosib[81][12] = { {0} };
	printf("D�marrage...\n");
	clock_t tStart = clock();

	// Obtention de l'ordre des casses pour optimisation
	getPossibility(sudoku, grillePosib);

	// L'index de la premierre casse a essayer
	int index = 0;
	while (grillePosib[index][9] == 0)
		index++;


	// Calcul du jeux
	calculate(sudoku, index, grillePosib);

	///------- AFFICHAGE DES RESULTATS -------///
	clock_t tEnd = clock();
	afficher(sudoku);
	printf("V�rification = %d\n", checkBySum(sudoku));
	printf("Temps : %.0fms", (((double)(tEnd)-(double)(tStart)) / (double)CLOCKS_PER_SEC)*1000);
}


///<summary>Fonction qui calcule les coups, qui les testes,
/// et qui les valides si ils sont justes, c'est la "vrai" fonction
//  qui s'occupe de r�soudre le sudoku
void calculate(int sudoku[9][9], int index, int grillePosib[81][12]) {
	
	int casse;
	int y;
	int x;
	int nbCoup;

	/// ----- TOUT EST REMPLI ----- ///
	while (index != 81) {

		casse = grillePosib[index][10];
		y = casse / 9;
		x = casse % 9;
		nbCoup = grillePosib[casse][11];


		/// ----- CAS D'UNE CASSE >= 0 ----- ///
		if (nbCoup < grillePosib[index][9]) {
			// on incr�mente de 1 et on retest
			sudoku[y][x] = grillePosib[casse][nbCoup];
			grillePosib[casse][11]++;

			// Si Valide		-> On passe a la casse suivante 
			// Si Non-valide	-> On ne fais rien et re-boucle
			
			if (sudokuValidity(sudoku, y, x)) {
				// Valide -> casse suivante
				index++;
			}
			
		}
		/// ----- CAS OU LA CASSE MAX EST ATTEINTE ----- ///
		else {
			// Retour en arriere
			sudoku[y][x] = 0;
			index--;
			grillePosib[casse][11] = 0;
		}
	}
}


void getPossibility(int sudoku[9][9], int grillePosib[81][12]) {

	// On test toutes les possibilit�s pour toutes les casses
	int nbPosCasse, x, y; // nombre de possibilit� pour cette casse
	for (int casse = 0; casse < 81; casse++) {
		y = casse / 9;
		x = casse % 9;
		nbPosCasse = 0;

		// Si le jeux ne contient pas de casse de base
		if (sudoku[y][x] == 0) {
			// On teste les 9 pos
			for (int i = 1; i < 10; i++) {
				// Si le nombre peux convenir dans cette casse
				sudoku[y][x] = i;
				if (sudokuValidity(sudoku, y, x)) {
					grillePosib[casse][nbPosCasse] = i;
					nbPosCasse++;
				}
				sudoku[y][x] = 0;
			}
		}
		// On set le num�ro de casse et le nombre de possibilit�
		grillePosib[casse][9] = nbPosCasse;
		grillePosib[casse][10] = casse;
	}

	/// ----- TRIAGE PAR ORDRE CROISSANT ----- ///
	int i, z, temp1, temp2;
	for (i = 0; i < 81; i++) {
		for (z = 0; z < 80 - i; z++) {
			if (grillePosib[z][9] > grillePosib[z + 1][9]) {
				temp1 = grillePosib[z][9];
				temp2 = grillePosib[z][10];
				grillePosib[z][9] = grillePosib[z + 1][9];
				grillePosib[z][10] = grillePosib[z + 1][10];

				grillePosib[z + 1][9] = temp1;
				grillePosib[z + 1][10] = temp2;

			}
		}
	}
}


// Return 1 si le nombre n'est pas d�ja pr�sent
// dans la collone, donc si la collone est correct
int sudokuValidity(int sudokuCopy[9][9], int y, int x) {
	int valeurDepart = sudokuCopy[y][x]; // La valeur de la casse a test�

	///----------TEST DE COLONNE----------///
	///------------ET DE LIGNE------------///
	for (int i = 0; i < 9; i++)
		if ((y != i && valeurDepart == sudokuCopy[i][x]) || (x != i && valeurDepart == sudokuCopy[y][i]))
			return 0;


	///----------TEST DE BLOC----------///
	// Les coordonn�es du d�but du blocs
	int startRow = (x / 3) * 3;
	int startLine = (y / 3) * 3;

	for (int i = 0; i < 3; i++)
		for (int z = 0; z < 3; z++)
			if ((y != startLine + z && x != startRow + i) && valeurDepart == sudokuCopy[startLine + z][startRow + i])
				return 0;

	// Aucune erreur d�tect�e
	return 1;
}


/// <summary>Fonction qui return 1 sur le jeux est correct.
/// Il vas faire la somme total des nombre qui doit �tre �gale = 405 </summary>
int checkBySum(int sudoku[9][9]) {
	int sum = 0;
	for (int i = 0; i < 9; i++)
		for (int z = 0; z < 9; z++)
			sum += sudoku[i][z];

	return sum == 405;
}

void afficher(int sudoku[9][9]) {
	printf("---------\n");
	for (int i = 0; i < 9; i++) {
		for (int x = 0; x < 9; x++)
			printf("%d,", sudoku[i][x]);
		printf("\n");
	}
	printf("---------\n\n");
}
