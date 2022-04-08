#include "Header.h"

#define MISE_DEPART 10000
#define TAU_JOUR 0.1

#define NB_JOUR 365

//void main() {
//
//	double somme = MISE_DEPART;
//	double lastDouble = MISE_DEPART;
//	int indexLastDouble = 0;
//
//	double doublage = 0, moyenneDoublage;
//	int nbDoublage = 0;
//	for (int i = 0; i < NB_JOUR; i++) {
//		somme += (somme / 100) * TAU_JOUR;
//		printf("Day %d: %.2f\n", i + 1, somme);
//		if (somme >= lastDouble * 2) {
//			doublage += (i - indexLastDouble);
//			indexLastDouble = i;
//			lastDouble = somme;
//
//			nbDoublage++;
//
//			moyenneDoublage = doublage / nbDoublage;
//			printf("=========================\nVALEUR X2\n=========================\n");
//		}
//		
//	}
//
//	printf("Res : %.2f\n", somme);
//	printf("X2 en moyenne tout les : %.2f\n", moyenneDoublage);
//
//
//}