#include "Trie.h"





Trie* trieCreate() {
	Trie* t = (Trie*)malloc(sizeof(Trie));
	if (t) {
		t->lastChar = false;
		t->key = 0;
		t->childAmount = 0;
		t->child = NULL;
		return t;
	}
	return EXIT_FAILURE;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* trie, char* word) {

	/// On boucle tout le mot : 
	/// 2 cas possible:
	///		-> L'obj ne contient pas d'enfant			=> On crée un enfant
	///		-> L'obj contient des enfants :
	///			 2 cas possible:
	///				-> soit une lettre est déjà présente dans le child	=> on ne fait rien,
	///																	   sauf si c'est la dernière lettre.
	///				-> la lettre n'est pas présente						=> on l'ajoute
	/// 

	int letter = 0, i;

	while (word[letter] != '\0') {

		for (i = 0; i < trie->childAmount; i++) {
			if (trie->child[i]->key == word[letter]) {
				if (word[letter + 1] == '\0')
					trie->child[i]->lastChar = true;
				trie = trie->child[i];
				i = 100000; // -10 pour ne pas faire d'overflow
			}
		}

		// Si I MAx alors la lettre à étée trouvée
		if (i < 100000) {
			// Si il n'a pas d'enfant, on lui crée (malloc) sinon on realloc
			if (trie->childAmount == 0)
				trie->child = trieCreate();
			else
				trie->child = (Trie**)realloc(trie->child, sizeof(Trie) * (trie->childAmount + 1));

			// Création et définition d'un enfant
			trie->child[trie->childAmount] = trieCreate();
			trie->childAmount++;

			trie = trie->child[trie->childAmount-1];
			trie->key = word[letter];
			trie->child = NULL;

			// Si c'est la dernièere lettre, la lettre est donc une fin de mot.
			trie->lastChar = (word[letter + 1] == '\0') ? true : false;

		}

		letter++;
	}
}


/// <summary> Fonction qui parcours les lettres du mot et qui s'assures donc que le mot soit bien présent dans
/// le Trie, si oui, on return le dernier Trie, sinon, false. </summary>
/// <param name="trie"> Le trie dans le quel il faut chercher </param>
/// <param name="word"> Le mot à rechercher </param>
/// <returns> Le child (si d'application) pour permettre à trieSearch de savoir si c'est un mot de fin.</returns>
Trie* searchTrieHelper(Trie* trie, char* word) {
	int i = 0, pos;
	while (word[i] != '\0') {
		pos = 0;
		while (pos < trie->childAmount && trie->child[pos]->key != word[i])
			pos++;
	
		if (pos == trie->childAmount)
			return NULL;

		trie = trie->child[pos];
		i++;
	}
	return trie;
}


/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word) {
	Trie* res = searchTrieHelper(obj, word);
	// Cheker si c'est une derniere lettre
	return (res == NULL) ? false : res->lastChar;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix) {
	return (searchTrieHelper(obj, prefix) == NULL) ? false : true;
}

void trieFreeHelper(Trie* trie) {
	int pos = 0;
	while (pos < trie->childAmount) {
		trieFreeHelper(trie->child[pos]);
		free(trie->child[pos]);
		pos++;
	}
	free(trie->child);
}
void trieFree(Trie* trie) {
	trieFreeHelper(trie);
	free(trie);
}



//void main() {
//
//	Trie* tri = trieCreate();
//	trieInsert(tri, "apple");
//	int i = trieSearch(tri, "apple");
//	int i1 = trieSearch(tri, "app");
//
//	int i3 = trieStartsWith(tri, "app");
//	trieInsert(tri, "app");
//	int i4 = trieSearch(tri, "app");
//
//	int i5 = trieSearch(tri, "a");
//	trieInsert(tri, "a");
//
//	int i6 = trieSearch(tri, "a");
//
//
//	bool x = trieStartsWith(tri, "a");
//
//	trieFree(tri);
//
//	//Trie* trie = trieCreate();
//	//trieInsert(trie, "app");
//	//trieInsert(trie, "apple");
//	//trieInsert(trie, "beer");
//	//trieInsert(trie, "add");
//	//trieInsert(trie, "jam");
//	//trieInsert(trie, "rental");
//	//int x1 =trieSearch(trie,"apps" );
//	//int x2 =trieSearch(trie, "app");
//	//int x3= trieSearch(trie, "ad");
//	//int x4 =trieSearch(trie,"applepie" );
//	//int x44 =trieSearch(trie,"rest" );
//	//int x11 =trieSearch(trie, "jan");
//	//int x111 =trieSearch(trie, "rent");
//	//int x22 =trieSearch(trie,"beer" );
//	//int x222= trieSearch(trie, "jam");
//	//int x2222 =trieStartsWith(trie, "apps");
//	//int x223 =trieStartsWith(trie, "app");
//	//int x445 =trieStartsWith(trie, "ad");
//	//int x455= trieStartsWith(trie, "applepie");
//	//int x56 =trieStartsWith(trie, "rest");
//	//int x566= trieStartsWith(trie,"jan" );
//	//int x98 =trieStartsWith(trie, "rent");
//	//int x556= trieStartsWith(trie, "beer");
//	//int x654 =trieStartsWith(trie, "jam");
//
//	//trieFree(trie);
//
//}
//
