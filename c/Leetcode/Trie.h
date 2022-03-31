#ifndef TRIE_H
#define TRIE_H

#include "Header.h"

/// <summary> Trie est une structure permettant d'y ins�r� des mots.
/// Nous pouvons ensuites savoir si un mot est pr�sent de la trie de
/// mani�re �fficace et optimis�e. 
/// Nous pouvons �galement savoir si un pr�fix est pr�sent. /// </summary>
/// 
/// <param = "key"> C'est la cl� trie, dans le cas d'un trie de string, c'est un caract�re. </param>
/// <param = "childAmount"> C'est le nombre d'enfant que le Trie poss�de 
///		-> Louis -> Loit, le Trie avec key = "L" poss�de donc 2 childs </param>
///	<param = "lastChar"> Permet de savoir si c'est la deni�re lettre d'un mot. </param>
/// 
typedef struct Trie {
	char key;
	int childAmount;
	bool lastChar;
	struct Trie** child;
} Trie;




void trieInsert(Trie* trie, char* word);
Trie* searchTrieHelper(Trie* trie, char* word);
bool trieSearch(Trie* obj, char* word);
bool trieStartsWith(Trie* obj, char* prefix);
void trieFreeHelper(Trie* trie);
void trieFree(Trie* trie);


#endif // !TRIE_H