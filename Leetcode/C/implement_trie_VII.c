#include "Header.h"


typedef struct Triee Triee;
struct Triee {
	char val;
	bool isEndWord; // <- Si true, c'est une lettre de fin de mot
	/// Child est comme une linkedlist
	struct Triee** child;
} ;



/** Initialize your data structure here. */

Triee* trieCreatee() {
	Triee* t = (Triee*)malloc(sizeof(Triee));

	if (t) {
		t->isEndWord = false;
		//t->child = (Trie*)malloc(sizeof(Trie));
		t->val = 0;
		t->child = NULL;
	}
	else
		return EXIT_FAILURE;

	return t;
}

/** Inserts a word into the trie. */
void trieInsertt(Triee* trie, char* word) {

	if (!trie) return EXIT_FAILURE;
	
	/// On boucle tout le mot
	/// 2 cas possible:
	///		-> L'obj ne contient pas d'enfant			=> On crée un enfant
	///		-> L'obj contient des enfats				=> Suite
	///			 2 cas possible:
	///				-> soit une lettre est déjà présente dans le child	=> on ne fait rien
	///				-> la lettre n'est pas présente						=> on l'ajoute
	/// 
	
	int letter, len = strlen(word), pos = 0;
	Triee* trieTemp = trie;
	char l;
	for (letter = 0; letter < len; letter++) {

		l = word[letter];
		pos = 0;

		// Si il à des enfants
		// On parcour le trie en recherche du carr
		// Si on ne le trouve pas, on lui ajoute
		if (trie->child) {
			while (trie->child[pos] && trie->child[pos]->val != l)
				pos++;

			// Si la lettre à été trouvée
			if (trie->child[pos]) {
				// Si c'est la derniere lettre on la set comme fin de mot
				if (letter + 1 == len)
					trie->child[pos]->isEndWord = true;

				trie = trie->child[pos];
				continue;
			}
		}
		
		// Si il n'a pas d'enfant, on lui crée (malloc) sinon on realloc
		if (!trie->child)
			trie->child = (Triee**)malloc(sizeof(Triee));
		else
			trie->child = (Triee**)realloc(trie->child, sizeof(Triee) * (pos + 1));
		

		// On s'assure que malloc ou realloc à fonctionner
		if (trie->child == NULL)
			return EXIT_FAILURE;
		
		// Création et définition d'un enfant
		trie->child[pos] = (Triee*)malloc(sizeof(Triee));
		if (trie->child[pos] != NULL) {
			trie->child[pos + 1] = NULL;
			trie = trie->child[pos];
			trie->val = l;
			trie->child = NULL;

			// Si c'est la dernièere lettre, la lettre est donc une fin de mot.
			trie->isEndWord = (letter + 1 == len) ? true : false;
		}
		else
			return EXIT_FAILURE;

	}
}



Triee* searchTrieHelperr(Triee* trie, char* word) {
	// Parcour tour le word on recherchant dans les childs
	int i, len = strlen(word), pos;
	for (i = 0; i < len; i++) {

		// Parcours des childs
		pos = 0;
		while (trie->child && trie->child[pos] && trie->child[pos]->val != word[i])
			pos++;

		if (!trie->child || !trie->child[pos])
			return NULL;

		trie = trie->child[pos];
	}
	// Retour du child pour permettre à trieSearch de savoir si c'est un mot de fin.
	return trie;
}


/** Returns if the word is in the trie. */
bool trieSearchh(Triee* obj, char* word) {
	Triee* res = searchTrieHelperr(obj, word);
	// Cheker si c'est une derniere lettre
	return (res == NULL) ? false : res->isEndWord;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWithh(Triee* obj, char* prefix) {
	return (searchTrieHelperr(obj, prefix) == NULL) ? false : true;
}

void trieFreeHelperr(Triee* trie) {
	if (trie->child) {
		int pos = 0;
		while (trie->child[pos]) {
			trieFreeHelperr(trie->child[pos]);
			free(trie->child[pos]);
			pos++;
		}
		free(trie->child);
	}
}
void trieFreee(Triee* trie) {
	trieFreeHelperr(trie);
	free(trie);
}



/*void main() {

	Trie* tri = trieCreate();
	trieInsert(tri, "apple");
	int i = trieSearch(tri, "apple");
	int i1 = trieSearch(tri, "app");

	int i3 = trieStartsWith(tri, "app");
	trieInsert(tri, "app");
	int i4 = trieSearch(tri, "app");

	int i5 = trieSearch(tri, "a");
	trieInsert(tri, "a");

	int i6 = trieSearch(tri, "a");
	

	trie* t = triecreate();
	bool x = triestartswith(t, "a");

	trieFree(tri);

	Trie* trie = trieCreate();
	trieInsert(trie, "app");
	trieInsert(trie, "apple"); 
	trieInsert(trie, "beer");
	trieInsert(trie, "add");
	trieInsert(trie, "jam");
	trieInsert(trie, "rental");
	trieSearch(trie,"apps" );
	trieSearch(trie, "app");
	trieSearch(trie, "ad");
	trieSearch(trie,"applepie" );
	trieSearch(trie,"rest" );
	trieSearch(trie, "jan");
	trieSearch(trie, "rent");
	trieSearch(trie,"beer" );
	trieSearch(trie, "jam");
	trieStartsWith(trie,"apps" );
	trieStartsWith(trie, "app");
	trieStartsWith(trie, "ad");
	trieStartsWith(trie, "applepie");
	trieStartsWith(trie, "rest");
	trieStartsWith(trie,"jan" );
	trieStartsWith(trie, "rent");
	trieStartsWith(trie, "beer");
	trieStartsWith(trie, "jam");

	trieFree(trie);
	
}*/

