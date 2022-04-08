#include "Header.h"



typedef struct MapSum {
	char ch;
	int value;
	bool isEndWord; // <- Si true, c'est une lettre de fin de mot
	/// Child est comme une linkedlist
	struct MapSum** child;
}MapSum;

MapSum* searchTrieHelperS(MapSum* trie, char* word);

/** Initialize your data structure here. */

MapSum* mapSumCreate() {
	MapSum* t = (MapSum*)malloc(sizeof(MapSum));

	if (t) {
		t->isEndWord = false;
		//t->child = (Trie*)malloc(sizeof(Trie));
		t->ch = 0;
		t->child = NULL;
	}
	else
		return EXIT_FAILURE;

	return t;
}

/** Inserts a word into the trie. */
void mapSumInsert(MapSum* trie, char* word, int val) {

	if (!trie) return EXIT_FAILURE;

	// On v�rifie que la cl� n'existe pas
	int toDecrement = 0;
	MapSum* res = searchTrieHelperS(trie, word);
	if (res && res->isEndWord) {
		toDecrement = res->value;
	}

	toDecrement = (val > toDecrement) ? val - toDecrement : -toDecrement + val;
	//toDecrement = toDecrement + (val - toDecrement);
	/// On boucle tout le mot
	/// 2 cas possible:
	///		-> L'obj ne contient pas d'enfant			=> On cr�e un enfant
	///		-> L'obj contient des enfats				=> Suite
	///			 2 cas possible:
	///				-> soit une lettre est d�j� pr�sente dans le child	=> on ne fait rien
	///				-> la lettre n'est pas pr�sente						=> on l'ajoute
	/// 

	int letter, len = strlen(word), pos = 0;
	char l;
	for (letter = 0; letter < len; letter++) {

		l = word[letter];
		pos = 0;

		// Si il � des enfants
		// On parcour le trie en recherche du carr
		// Si on ne le trouve pas, on lui ajoute
		if (trie->child) {
			while (trie->child[pos] && trie->child[pos]->ch != l)
				pos++;

			// Si la lettre � �t� trouv�e
			if (trie->child[pos]) {
				// Si c'est la derniere lettre on la set comme fin de mot
				if (letter + 1 == len)
					trie->child[pos]->isEndWord = true;

				trie->child[pos]->value += toDecrement;
				trie = trie->child[pos];
				continue;
			}
		}

		// Si il n'a pas d'enfant, on lui cr�e (malloc) sinon on realloc
		if (!trie->child)
			trie->child = (MapSum**)malloc(sizeof(MapSum));
		else
			trie->child = (MapSum**)realloc(trie->child, sizeof(MapSum) * (pos + 1));


		// On s'assure que malloc ou realloc � fonctionner
		if (trie->child == NULL)
			return EXIT_FAILURE;

		// Cr�ation et d�finition d'un enfant
		trie->child[pos] = (MapSum*)malloc(sizeof(MapSum));
		if (trie->child[pos] != NULL) {
			trie->child[pos + 1] = NULL;
			trie = trie->child[pos];
			trie->ch = l;
			trie->value = toDecrement;
			trie->child = NULL;

			// Si c'est la derni�ere lettre, la lettre est donc une fin de mot.
			trie->isEndWord = (letter + 1 == len) ? true : false;
		}
		else
			return EXIT_FAILURE;

	}
}



MapSum* searchTrieHelperS(MapSum* trie, char* word) {
	// Parcour tour le word on recherchant dans les childs
	int i, len = strlen(word), pos;
	for (i = 0; i < len; i++) {

		// Parcours des childs
		pos = 0;
		while (trie->child && trie->child[pos] && trie->child[pos]->ch != word[i])
			pos++;

		if (!trie->child || !trie->child[pos])
			return NULL;

		trie = trie->child[pos];
	}
	// Retour du child pour permettre � trieSearch de savoir si c'est un mot de fin.
	return trie;
}


void trieFreeHelperS(MapSum* trie) {
	if (trie->child) {
		int pos = 0;
		while (trie->child[pos]) {
			trieFreeHelperS(trie->child[pos]);
			free(trie->child[pos]);
			pos++;
		}
		free(trie->child);
	}
}


void mapSumFree(MapSum* trie) {
	trieFreeHelperS(trie);
	free(trie);
}



int mapSumSum(MapSum * obj, char* prefix) {
	MapSum* t = searchTrieHelperS(obj, prefix);
	if (t)
		return t->value;
	return 0;
}


//void main() {
//
//	MapSum* tri = mapSumCreate();
//
//
//	mapSumInsert(tri, "apple", 3);
//	int x = mapSumSum(tri, "app");
//
//	mapSumInsert(tri, "app", 2);
//	int xd = mapSumSum(tri, "app");
//	mapSumFree(tri);
//
//
//
//}






