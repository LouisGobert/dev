#include "Header.h"


typedef struct WordDictionary{
	char key;
	int childAmount;
	bool lastChar;
	struct WordDictionary** child;
} WordDictionary;


WordDictionary* wordDictionaryCreate() {
	WordDictionary* t = (WordDictionary*)malloc(sizeof(WordDictionary));
	if (t) {
		t->lastChar = false;
		t->key = 0;
		t->childAmount = 0;
		t->child = NULL;
		return t;
	}
	return NULL;
}

void wordDictionaryAddWord(WordDictionary* obj, char* word) {
	int letter = 0, i;

	while (word[letter] != '\0') {

		for (i = 0; i < obj->childAmount; i++) {
			if (obj->child[i]->key == word[letter]) {
				if (word[letter + 1] == '\0')
					obj->child[i]->lastChar = true;
				obj = obj->child[i];
				i = -2; // -10 pour ne pas faire d'overflow
			}
		}

		// Si I MAx alors la lettre à étée trouvée
		if (i != -1) {
			// Si il n'a pas d'enfant, on lui crée (malloc) sinon on realloc
			if (obj->childAmount == 0)
				obj->child = wordDictionaryCreate();
			else
				obj->child = (WordDictionary**)realloc(obj->child, sizeof(WordDictionary) * (obj->childAmount + 1));

			// Création et définition d'un enfant
			obj->child[obj->childAmount] = wordDictionaryCreate();
			obj->childAmount++;

			obj = obj->child[obj->childAmount - 1];
			obj->key = word[letter];
			obj->child = NULL;

			// Si c'est la dernièere lettre, la lettre est donc une fin de mot.
			obj->lastChar = (word[letter + 1] == '\0') ? true : false;

		}

		letter++;
	}
}


int wordSearchHelper(WordDictionary* obj, char* word, int i) {
	if (word[i] == '\0') {
		if (obj->lastChar)
			return 1;
		return 0;
	}

	if (word[i] == '.') {
		for (int x = 0; x < obj->childAmount; x++) {
			return wordSearchHelper(obj->child[x], word, i + 1);
				
		
		}
		return 0;
	}
	else {
		for (int x = 0; x < obj->childAmount; x++) {
			if (obj->child[x]->key == word[i])
				return wordSearchHelper(obj->child[x], word, i + 1);
		}
	}

	return 0;
}

bool wordDictionarySearch(WordDictionary* obj, char* word) {
	return wordSearchHelper(obj, word, 0);
}

void wordFreeHelper(WordDictionary* obj) {
	int pos = 0;
	while (pos < obj->childAmount) {
		wordFreeHelper(obj->child[pos]);
		free(obj->child[pos]);
		pos++;
	}
	free(obj->child);
}

void wordDictionaryFree(WordDictionary* obj) {
	wordFreeHelper(obj);
	free(obj);
}



//void main() {
//	WordDictionary* dic = wordDictionaryCreate();
//	char* word = "bad";
//	char* word1 = "dad";
//	char* word2 = "mad";
//	char* f1 = "pad";
//	char* f2 = "bad";
//	char* f3 = ".ad";
//	char* f4 = "b..";
//
//	wordDictionaryAddWord(dic, word);
//	wordDictionaryAddWord(dic, word1);
//	wordDictionaryAddWord(dic, word2);
//
//
//	bool res = wordDictionarySearch(dic, f1);
//	bool res1 = wordDictionarySearch(dic, f2);
//	bool res2 = wordDictionarySearch(dic, f3);
//	bool res3 = wordDictionarySearch(dic, f4);
//
//	wordDictionaryFree(dic);
//
//}