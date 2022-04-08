//#include "Header.h"
//
//
//typedef struct Trie Trie;
//struct Trie {
//	
//	Trie *child[26];
//	// Si is est true, la lettre est la
//	bool is;
//	bool isWord;
//};
//
//
//
//void createChild(Trie* obj);
//
///** Initialize your data structure here. */
//
//Trie* trieCreate() {
//	Trie* t = malloc(sizeof(*t));
//	t->is = false;
//	t->isWord = false;
//	for (int i = 0; i < 26; i++) {
//		t->child[i] = NULL;
//	}
//	return t;
//}
//
///** Inserts a word into the trie. */
//void trieInsert(Trie* obj, char* word) {
//
//	if (!obj) return;
//	int childPos;
//	// On pourcours le trie
//	for (int i = 0, n = strlen(word); i < n; i++) {
//
//		// Si c'est enfant existes
//		// Sinon on les crées
//		childPos = word[i] - 'a';
//		if (!obj->child[childPos]) {
//			// Si enfant existe et est présent
//			createChild(obj);
//		}
//
//		// On set la lettre comme présente
//		obj = obj->child[childPos];
//		obj->is = true;
//
//
//		// Si c'est la derniere lettre, on indique c'est c'est un mot
//		if (i + 1 == n)	obj->isWord = true;
//			
//	}
//}
//
//void createChild(Trie* obj) {
//	//*obj->child = (Trie*)malloc(sizeof(Trie) * 26);
//	for (int i = 0; i < 26; i++) {
//		obj->child[i] = trieCreate();
//	}
//}
//
///** Returns if the word is in the trie. */
//bool trieSearch(Trie* obj, char* word) {
//	//if (!obj) return false;
//
//	int i, n = strlen(word);
//	// On pourcours le trie
//	for (i = 0; i < n && obj; i++) {
//
//		// On regarde si il est présent
//		// SI il ne les pas, on le crée
//		if (obj->child[word[i] - 'a'] && obj->child[word[i] - 'a']->is != true) {
//			return false;
//		}
//		obj = obj->child[word[i] - 'a'];
//	}
//
//	// Check si les childs sont null
//	if (obj && obj->isWord && i == n) return true;
//	return false;
//}
//
///** Returns if there is any word in the trie that starts with the given prefix. */
//bool trieStartsWith(Trie* obj, char* prefix) {
//	if (!obj) return false;
//
//	// On pourcours le trie
//	int i, n = strlen(prefix);
//	for (i = 0; i < n && obj; i++) {
//
//		// On regarde si il est présent
//		// SI il ne les pas, on le crée
//		if (!obj->child[prefix[i] - 'a'] || obj->child[prefix[i] - 'a']->is != true) {
//			return false;
//		}
//		obj = obj->child[prefix[i] - 'a'];
//	}
//
//	// Si on est bien arrivé à la fin et pas si on est arrivé en obj null
//	if (i == n)	return true;
//	return false;
//}
//
//void trieFree(Trie* obj) {
//
//	free(obj);
//}
//
//
//
////void main() {
////
////	Trie* tri = trieCreate();
////	trieInsert(tri, "apple");
////	int i = trieSearch(tri, "apple");
////	int i1 = trieSearch(tri, "app");
////
////	int i3 = trieStartsWith(tri, "app");
////	trieInsert(tri, "app");
////	int i4 = trieSearch(tri, "app");
////
////	int i5 = trieSearch(tri, "a");
////	trieInsert(tri, "a");
////
////	int i6 = trieSearch(tri, "a");
////	trieFree(tri);
////
////	/*Trie* t = trieCreate();
////	bool x = trieStartsWith(t, "a");*/
////
////	//trieFree(t);
////}
//
