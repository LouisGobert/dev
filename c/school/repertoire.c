#include "repertoire.h"

void vider_buffer_clavier()
{
	int c;

	do
	{
		c = getchar();
	}
	while (c != EOF && c != '\n');
}

/**
 * Echanger le contenu de deux structures de type contact � partir de leurs adresses m�moires.
 * Cette fonction est utilis�e lors de l'ajout d'un contact.
 */
void echanger_contacts(struct contact *adrC1, struct contact *adrC2)
{
	struct contact temp = *adrC1;
	*adrC1 = *adrC2;
	*adrC2 = temp;
}

/**
 * Afficher un contact de la mani�re suivante :
 * FAFRA Steve
 * T�l. : 081601423
 * n�(e) le 17/06/1992
 * 
 * Le nom doit �tre affich� en lettres majuscules. Pour ce faire, d�clarer un tableau o� chacune des lettres
 * du nom du contact sera copi�e en son �quivalent majuscule. Aidez-vous de la fonction "toupper" de la biblioth�que
 * <ctype.h> (d�j� incluse).
 */
void afficher_un_contact(const struct contact *adrC)
{
	char nom_maj[LG_NOM];
	int i = 0;

	while (adrC->nom[i] != '\0')
	{
		nom_maj[i] = toupper(adrC->nom[i]);
		i++;
	}
	nom_maj[i] = '\0';

	printf("%s %s\n", nom_maj, adrC->prenom);
	printf("T%cl. : %s\n", 130, adrC->telephone);
	printf("n%c(e) le %02d/%02d/%d\n\n", 130, adrC->naissance.jour, adrC->naissance.mois, adrC->naissance.annee);
}

/**
 * Afficher l'ensemble des contacts du r�pertoire.
 * Utiliser pour ce faire la fonction "afficher_un_contact" d�finie ci-dessus.
 */
void afficher_le_repertoire(const struct contact rep[], int nbC)
{
	int i;

	for (i = 0; i < nbC; i++)
		afficher_un_contact(&rep[i]);
}

/**
 * R�aliser la saisie en console des donn�es relatives � un contact, c'est-�-dire :
 * Nom :
 * Pr�nom :
 * T�l�phone :
 * Date de naissance (jj mm aaaa) :
 * 
 * Le nouveau contact est enregistr� � la suite des autres contacts dans le tableau. Ensuite, � l'aide
 * de permutations successives vers la gauche, il est plac� de mani�re � ce que tous les contacts
 * soient tri�s alphab�tiquement par nom.
 * 
 * Pour comparer une cha�ne de caract�res � une autre sans tenir compte de la casse, utiliser la
 * fonction "stricmp".
 * 
 * Ne pas oublier d'incr�menter le nombre de contacts.
 */
void ajouter_un_contact(struct contact rep[], int *nbC)
{
	struct contact nouveau;
	int i, nbVal; //, compNoms;

	// Acqu�rir les donn�es du nouveau contact.
	printf("Nom : ");
	gets(nouveau.nom);

	printf("Pr%cnom : ", 130);
	gets(nouveau.prenom);

	printf("T%cl%cphone : ", 130, 130);
	gets(nouveau.telephone);

	printf("Date de naissance (jj mm aaaa) : ");
	nbVal = scanf("%d%d%d", &nouveau.naissance.jour, &nouveau.naissance.mois, &nouveau.naissance.annee);

	if (nbVal != 3)
	{
		// Remarque : les tests pour la vadilit� des donn�es peuvent �tre plus complets.
		printf("\nDate incorrecte ! Recommencez l'encodage.");
		vider_buffer_clavier();
		return;
	}

	// D�caler d'une case vers la droite tous les contacts ayant un nom alphab�tiquement plus grand.
	i = *nbC - 1;
	while (i >= 0 && stricmp(rep[i].nom, nouveau.nom) > 0)
	{
		// Remarque : cette technique n'utilise pas les permutations.
		rep[i + 1] = rep[i];
		i--;
	}

	// On peut compl�ter la condition de la boucle pr�c�dente afin de comparer les pr�noms lorsque les noms des contacts sont identiques.
	/*
	while (i >= 0 && ((compNoms = stricmp(rep[i].nom, nouveau.nom)) > 0 || (compNoms == 0 && stricmp(rep[i].prenom, nouveau.prenom) > 0))) { ... }
	*/

	// Copier le nouveau contact.
	rep[i + 1] = nouveau;

	// Incr�menter le nombre de contacts.
	(*nbC)++;
}

/**
 * Effectuer une recherche s�quentielle ou dichotomique dans le tableau pour trouver un contact
 * ayant le m�me nom que celui fourni en argument. Si le contact existe, la fonction retourne sa
 * position au sein du tableau. Dans le cas contraire, la valeur -1 est retourn�e.
 * 
 * Pour comparer une cha�ne de caract�res � une autre sans tenir compte de la casse, utiliser la
 * fonction "stricmp".
 */
int rechercher_un_contact(const struct contact rep[], int nbC, const char *nom)
{
	int i, deb, mil, fin, compNoms;

	// Recherche s�quentielle
	/*
	i = 0;
	while (i < nbC && (compNoms = stricmp(rep[i].nom, nom)) < 0)
		i++;

	if (i < nbC && compNoms == 0)
		return i;

	return -1;
	*/

	// Recherche dichotomique
	deb = 0;
	fin = nbC - 1;
	while (deb <= fin)
	{
		mil = (deb + fin) / 2;

		if ((compNoms = stricmp(rep[mil].nom, nom)) == 0)
			return mil;

		if (compNoms < 0)
			deb = mil + 1;
		else
			fin = mil - 1;
	}

	return -1;
}

/**
 * Retirer le contact situ� � la position fournie en argument. Pour ce faire, d�caler de 1 vers la gauche
 * tous les contacts qui lui succ�dent.
 * 
 * Ne pas oublier de d�cr�menter le nombre de contacts.
 */
void supprimer_un_contact(struct contact rep[], int *nbC, int pos)
{
	int i;

	// D�caler d'une case vers la gauche tous les contacts situ�s apr�s le contact � supprimer.
	for (i = pos; i < *nbC - 1; i++)
		rep[i] = rep[i + 1];

	// D�cr�menter le nombre de contacts.
	(*nbC)--;
}
