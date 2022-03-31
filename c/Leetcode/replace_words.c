///*In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".
//
//Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.
//
//Return the sentence after the replacement.
//
// */
//#include "Header.h"
//#include "Trie.h"
//
//
////void getWord(char* tempWord, int spacePos, int wlen, char* sentence) {
////	for (int i = spacePos, x = 0; i < wlen + spacePos; i++, x++)
////		tempWord[x] = sentence[i];
////	tempWord[wlen] = '\0';
////}
//
//
//bool searchFirstOcc(Trie* trie,char *newSentence,  int *len, char *sentence, int i, int endPos) {
//	int pos;
//	int tempLen = *len;
//	while (i < endPos) {
//		pos = 0;
//		while (pos < trie->childAmount && trie->child[pos]->key != sentence[i])
//			pos++;
//
//		if (pos == trie->childAmount) {
//			*len = tempLen;
//			return false;
//		}
//
//		trie = trie->child[pos];
//		
//		newSentence[*len] = trie->key;
//		++* len;
//
//		// Si c'est la fin du mot, on return le mot
//		if (trie->lastChar) {
//			return true;
//		}
//		i++;
//	}
//	*len = tempLen;
//	return false;
//}
//
//char* replaceWords(char** dictionary, int dictionarySize, char* sentence) {
//
//	int i, wlen = 0, spacePos = 0, y;
//	Trie* trie = trieCreate();
//	for (i = 0; i < dictionarySize; i++)
//		trieInsert(trie, dictionary[i]);
//	
//
//	
//	char* newSentence = malloc(sizeof(char) * 1001 *1000);
//	int sentLen = 0;
//	i = 0;
//	while (sentence[i] != '\0')
//	{
//		if (sentence[i] == 32 || sentence[i+1] == '\0') {
//
//			if (sentence[i + 1] == '\0') wlen++;
//			
//			
//			
//			if (!searchFirstOcc(trie, newSentence, &sentLen, sentence, spacePos, wlen+spacePos)) {
//				// Si c'est faut on doit rajouté le mot .
//				for (y = 0; y < wlen; y++)
//					newSentence[sentLen++] = sentence[spacePos  + y];
//			}
//
//			newSentence[sentLen] = ' ';
//			newSentence[++sentLen] = '\0';
//
//			spacePos = i+1;
//			wlen = 0;
//		}
//		else
//			wlen++;
//
//		i++;
//	}
//
//
//	trieFree(trie);
//	newSentence[sentLen - 1] = '\0';
//	return newSentence;
//}
//
//
//
//
////void main() {
////
////
////	char** dictionnary = (char**)malloc(sizeof(char*) *1000);
////	char* d1 = "cat";
////	char* d2 = "bat";
////	char* d3 = "rat";
////
////	dictionnary[0] = d1;
////	dictionnary[1] = d2;
////	dictionnary[2] = d3;
////	char* res = replaceWords(dictionnary, 3, "the cattle was rattled by the battery");
////
////	free(res);
////	free(dictionnary);
////}