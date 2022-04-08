#include "Header.h"


/*Given two strings A and B of lowercase letters, return true if you can swap two letters in A so the result is equal to B, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at A[i] and A[j].
For example, swapping at indices 0 and 2 in "abcd" results in "cbad".*/



bool buddyStrings(char* A, char* B) {
	int lnA = strlen(A), lnB = strlen(B);
	
	// Check if minium lenght is reach
	if (lnA >= 2 && lnB >= 2 && lnA == lnB) {
		char t;
		int diff[2], nbDiv = 0, i, x;
		if (lnA == 2) {
			t = A[0];
			A[0] = A[1];
			A[1] = t;
			if (!strcmp(A, B))
				return true;
			return false;
		}

		// Count and find the 2 dif pos
		for (i = 0; i < lnA; i++) {
			if (A[i] != B[i]) {
				if (nbDiv == 2)
					return false;
				diff[nbDiv] = i;
				nbDiv++;
			}
		}

		if (nbDiv == 0) // try to find duplicate 
		{
		for (i = 0; i < lnA - 1; i++)
			for (x = i + 1; x < lnA; x++)
				if (A[i] == A[x])
					return true;
		}
				
		else if (nbDiv == 2) {
			t = A[diff[0]];
			A[diff[0]] = A[diff[1]];
			A[diff[1]] = t;
			if (!strcmp(A, B))
				return true;
		}
	}
	return false;
}

