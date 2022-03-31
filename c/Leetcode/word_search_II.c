#include "Header.h"



int existHelperr(char** board, int x, int y, int x_max, int y_max, int indexWord, char* word) {
	// On recois une lettre a rechercher en partant d'une position donnée
	///
	/// Vers la gauche
	///
	if (x != 0 && board[y][x - 1] == word[indexWord]) {
		if (word[++indexWord] != '\0') {
			board[y][x - 1] = '0';
			if (existHelperr(board, x - 1, y, x_max, y_max, indexWord, word) == -1) {
				board[y][x - 1] = word[--indexWord];
				return -1;
			}
			else board[y][x - 1] = word[--indexWord];
		}
		else return -1;

	}
	///
	/// Vers la droite
	///
	if (x + 1 < x_max && board[y][x + 1] == word[indexWord]) {
		if (word[++indexWord] != '\0') {
			board[y][x + 1] = '0';
			if (existHelperr(board, x + 1, y, x_max, y_max, indexWord, word) == -1) { 
				board[y][x + 1] = word[--indexWord];
				return -1;
			}
			else board[y][x + 1] = word[--indexWord];

		}
		else return -1;
	}
	///
	/// Vers le haut
	///
	if (y != 0 && board[y - 1][x] == word[indexWord]) {
		if (word[++indexWord] != '\0') {
			board[y - 1][x] = '0';
			if (existHelperr(board, x, y - 1, x_max, y_max, indexWord, word) == -1) {
				board[y - 1][x] = word[--indexWord];
				return -1;
			}
			else board[y - 1][x] = word[--indexWord];
		}
		else return -1;

	}
	///
	/// Vers le bas
	///
	if (y + 1 < y_max && board[y + 1][x] == word[indexWord]) {
		if (word[++indexWord] != '\0') {
			board[y + 1][x] = '0';
			if (existHelperr(board, x, y + 1, x_max, y_max, indexWord, word) == -1) {
				board[y + 1][x] = word[--indexWord];
				return -1;
			}
			else board[y + 1][x] = word[--indexWord];
		}
		else return -1;

	}
	return 0;
}


bool existt(char** board, int boardSize, int* boardColSize, char* word) {
	int x_max = boardColSize[0];
	int y_max = boardSize;
	char temp;

	// Find the first letter
	for (int y = 0; y < y_max; y++) {
		for (int x = 0; x < x_max; x++) {
			if (board[y][x] == word[0]) {
				temp = word[0];
				board[y][x] = '0';
				if (word[1] != '\0') {
					if (existHelperr(board, x, y, x_max, y_max, 1, word) == -1) {
						board[y][x] = temp;
						return true;
					}
					else {
						board[y][x] = temp;
					}

				}
				else return true;
			}
		}
	}
	return false;

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
	int* wordFinded = malloc(sizeof(int) * wordsSize); // Contient l'index des mot trouve
	int nbWordFinded = 0;

	for (int i = 0; i < wordsSize; i++) {
		if (existt(board, boardSize, boardColSize, words[i])) {
			wordFinded[nbWordFinded++] = i;
		}
	}

	char** returnTab = malloc(sizeof(char*) * nbWordFinded);
	for (int i = 0; i < nbWordFinded; i++) {
		returnTab[i] = words[wordFinded[i]];
	}

	free(wordFinded);
	*returnSize = nbWordFinded;
	return returnTab;
}




//void main() {
//	char boardd[4][4] = { {'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'},{'i', 'f', 'l', 'v'} };
//	char** board = malloc(sizeof(char*) * 4);
//	for (int i = 0; i < 4; i++)
//		board[i] = boardd[i];
//
//
//	char* word[4] = { "oath","pea","eat","rain" };
//
//	int bordColSize[3] = { 4, 3, 3 };
//	int rees = 0;
//	char** res = findWords(board, 4, bordColSize, word, 4, &rees);
//	free(board);
//
//}
