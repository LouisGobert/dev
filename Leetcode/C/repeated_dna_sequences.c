#include "Header.h"


//typedef struct Triee Triee;
//struct Triee {
//	
//	Triee *child[4];
//	// Si is est true, la lettre est la
//	bool is;
//	int cpt;
//};
//
//int getChildPoss(char s);
//void createChildd(Triee* obj);
//
///** Initialize your data structure here. */
//
//Triee* trieCreatee() {
//	Triee* t = malloc(sizeof(*t));
//	t->is = false;
//	t->cpt = 0;
//	for (int i = 0; i < 4; i++) {
//		t->child[i] = NULL;
//	}
//	return t;
//}

///** Inserts a word into the trie. */
//bool trieInsertt(Triee* obj, char* word) {
//
//	if (!obj) return false;;
//	int childPos;
//	// On pourcours le trie
//	for (int i = 0, n = strlen(word); i < n; i++) {
//
//		// Si c'est enfant existes
//		// Sinon on les crées
//		childPos = getChildPoss(word[i]);
//		if (!obj->child[childPos]) {
//			// Si enfant existe et est présent
//			createChildd(obj);
//		}
//
//		// On set la lettre comme présente
//		obj = obj->child[childPos];
//		obj->is = true;
//
//
//		// Si c'est la derniere lettre, on indique c'est c'est un mot
//		if (i + 1 == n) {
//			//printf("fin du mot %s trouve avec i = %d et n = %s\n", word, i, n);
//			obj->cpt++;
//		}
//
//		// Si le cpt est 
//		if (obj->cpt >= 2) {
//			obj->cpt = INT_MIN;
//			return true;
//		} 	
//	}
//	
//	return false;
//}

//int getChildPoss(char s) {
//	switch (s)
//	{
//	case 'A':
//		return 0;
//	case 'C':
//		return 1;
//	case 'G':
//		return 2;
//	default:
//		return 3;
//	}
//}

//void createChildd(Triee* obj) {
//	//*obj->child = (Triee*)malloc(sizeof(Triee) * 26);
//	for (int i = 0; i < 4; i++) {
//		obj->child[i] = trieCreate();
//	}
//}
//
//
//void trieFreee(Triee* obj) {
//
//	free(obj);
//}




///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//char** findRepeatedDnaSequences(char* s, int* returnSize) {
//
//	int len = strlen(s);
//	Triee* tri = trieCreate();
//
//	char** returnTab = NULL;
//	*returnSize = 0;
//
//	char tempChar[11];
//	int i, x;
//
//	for (i = 0; i < len - 9; i++) {
//		strncpy(tempChar, &s[i], 10);
//		tempChar[10] = '\0';
//		if (trieInsert(tri, tempChar)) {
//			returnTab = (char**)realloc(returnTab, sizeof(char*) * (*returnSize + 1));
//
//			returnTab[*returnSize] = (char*)malloc(sizeof(char)*11);
//			strncpy(returnTab[*returnSize], tempChar, 11);
//	
//			++* returnSize;
//		}
//	}
//
//	trieFree(tri);
//	return returnTab;
//}


//
//
//void main() {
//
//	char* s = "AAAAAAAAAAAAAAAAAAAACGACGCAATTTAGAACGGGCCGCACTGCAACCATTGCTCAGACAACGCATGAGTTAAATTTCACAAGTGATAGTGGCTTGCGAGACGTGGGTTGGTGGTAGCGTACGCCCGCTATTCGCCCCTAACGTGACGGGATTATAAGGTCGCTTCCCGGAATGCGCAGACGAGTCTCCGGTTTAGCCTAGACGTCTCACGCGCGCAAGGCGTCAGTTCTCACTATCTCGCACAGGTGTATTCTATTAGTTATGGGTTCTCACTACAGTCGGTTACTTCCTCATCCATTTCTGCATACGGGTCAACTAACAGTGTCATGGGGTATTGGGAAGGATGCGTTTTTAAACCCTCTCAGTAGCGCGAGGATGCCCACAAATACGACGGCGGCCACGGATCTAATGCGAAGCTAGCGACGCTTTCCAGCAACGAGCGCCCCACTTATGACTGCGTGGGGCGCTCCGCTTTCCTAGAGAACATAGATGGTGTTTTCGAATCGTAACCACTTA";
//;
//
//	int size = 0;
//	char** res = findRepeatedDnaSequences(s, &size);
//	
//	for (int i = 0; i < size; i++)
//		printf("%s\n", res[i]);
//	free(res);
//
//}
//















typedef struct Trie Trie;
struct Trie {
	char val;
	bool isEndWord; // <- Si true, c'est une lettre de fin de mot
	/// Child est comme une linkedlist
	struct Trie** child;
	int nb;
};



/** Initialize your data structure here. */

Trie* trieCreateDNA() {
	Trie* t = (Trie*)malloc(sizeof(Trie));
	t->isEndWord = false;
	//t->child = (Trie*)malloc(sizeof(Trie));
	t->val = 0;
	t->child = NULL;

	return t;
}

/** Inserts a word into the trie. */
int trieInsertDNA(Trie* trie, char* word) {

	if (!trie) return EXIT_FAILURE;

	/// On boucle tout le mot
	/// 2 cas possible:
	///		-> L'obj ne contient pas d'enfant			=> On crée un enfant
	///		-> L'obj contient des enfats				=> Suite
	///			 2 cas possible:
	///				-> soit une lettre est déjà présente dans le child	=> on ne fait rien
	///				-> la lettre n'est pas présente						=> on l'ajoute
	/// 

	int letter, len = 10, pos = 0;
	for (letter = 0; letter < len; letter++) {

		pos = 0;

		// Si il à des enfants
		// On parcour le trie en recherche du carr
		// Si on ne le trouve pas, on lui ajoute
		if (trie->child) {
			while (trie->child[pos] && trie->child[pos]->val != word[letter])
				pos++;

			// Si la lettre à été trouvée
			if (trie->child[pos]) {
				// Si c'est la derniere lettre on la set comme fin de mot
				if (letter + 1 == len && trie->child[pos]->nb >= 0) {
					trie->child[pos]->isEndWord = true;
					trie->child[pos]->nb = INT_MIN;
					return true;
				}

				trie = trie->child[pos];
				continue;
			}
		}

		// Si il n'a pas d'enfant, on lui crée (malloc) sinon on realloc
		if (!trie->child)
			trie->child = (Trie**)malloc(sizeof(Trie));
		else
			trie->child = (Trie**)realloc(trie->child, sizeof(Trie) * (pos + 1));

		// Création et définition d'un enfant
		trie->child[pos] = (Trie*)malloc(sizeof(Trie));
		trie->child[pos + 1] = NULL;
		trie = trie->child[pos];
		trie->val = word[letter];
		trie->child = NULL;
		trie->nb = 0;
		// Si c'est la dernièere lettre, la lettre est donc une fin de mot.
		trie->isEndWord = (letter + 1 == len) ? true : false;
		


	}

	return false;
}


void trieFreeHelperDNA(Trie* trie) {
	if (trie->child) {
		int pos = 0;
		while (trie->child[pos]) {
			trieFreeHelperDNA(trie->child[pos]);
			free(trie->child[pos]);
			pos++;
		}
		free(trie->child);
	}
}
void trieFreeDNA(Trie* trie) {
	trieFreeHelperDNA(trie);
	free(trie);
}




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRepeatedDnaSequences(char* s, int* returnSize) {

	int len = strlen(s) - 9;
	Trie* tri = trieCreateDNA();

	char** returnTab = NULL;
	*returnSize = 0;

	char tempChar[11];
	int i;

	for (i = 0; i < len; i++) {
		if (trieInsertDNA(tri, &s[i])) {
			returnTab = (char**)realloc(returnTab, sizeof(char*) * (*returnSize + 1));

			returnTab[*returnSize] = (char*)malloc(sizeof(char) * 11);
			strncpy(returnTab[*returnSize], &s[i], 10);
			returnTab[*returnSize][10] = '\0';

			++* returnSize;
		}
	}

	trieFreeDNA(tri);
	return returnTab;
}







//void main() {
//
//	char* s = "AAAAAAAAAAAAAAAAAAAACGACGCAATTTAGAACGGGCCGCACTGCAACCATTGCTCAGACAACGCATGAGTTAAATTTCACAAGTGATAGTGGCTTGCGAGACGTGGGTTGGTGGTAGCGTACGCCCGCTATTCGCCCCTAACGTGACGGGATTATAAGGTCGCTTCCCGGAATGCGCAGACGAGTCTCCGGTTTAGCCTAGACGTCTCACGCGCGCAAGGCGTCAGTTCTCACTATCTCGCACAGGTGTATTCTATTAGTTATGGGTTCTCACTACAGTCGGTTACTTCCTCATCCATTTCTGCATACGGGTCAACTAACAGTGTCATGGGGTATTGGGAAGGATGCGTTTTTAAACCCTCTCAGTAGCGCGAGGATGCCCACAAATACGACGGCGGCCACGGATCTAATGCGAAGCTAGCGACGCTTTCCAGCAACGAGCGCCCCACTTATGACTGCGTGGGGCGCTCCGCTTTCCTAGAGAACATAGATGGTGTTTTCGAATCGTAACCACTTA";
//;
//
//	int size = 0;
//	char** res = findRepeatedDnaSequences(s, &size);
//	
//	for (int i = 0; i < size; i++)
//		printf("%s\n", res[i]);
//	free(res);
//
//}
//