#ifndef TRIE_H
#define TRIE_H

#include "Header.h"

/// <summary> Trie est une structure permettant d'y inséré des mots.
/// Nous pouvons ensuites savoir si un mot est présent de la trie de
/// manière éfficace et optimisée. 
/// Nous pouvons également savoir si un préfix est présent. /// </summary>
/// 
/// <param = "key"> C'est la clé trie, dans le cas d'un trie de string, c'est un caractère. </param>
/// <param = "childAmount"> C'est le nombre d'enfant que le Trie possède 
///		-> Louis -> Loit, le Trie avec key = "L" possède donc 2 childs </param>
///	<param = "lastChar"> Permet de savoir si c'est la denière lettre d'un mot. </param>
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