#include "Header.h"
typedef struct {

	int stack[5000];
	int tail;
	int min;
} MinStak;



MinStak* minStackCreatee() {
	MinStak* ms = malloc(sizeof(MinStak));
	ms->tail = -1;
	return ms;
}

void minStackPushh(MinStak* obj, int x) {
	obj->stack[++obj->tail] = x;
}



void minStackPopp(MinStak* obj) {
	if (obj->tail >= 0) {
		// Mise à jour du minimum
		--obj->tail;
	}

}

int minStackTopp(MinStak* obj) {
	if (obj->tail >= 0)
		return obj->stack[obj->tail];
	return -1;
}


void minStackFreee(MinStak* obj) {
	free(obj);
}


bool isValid(char* s) {

	MinStak* ms = minStackCreatee();


	int pos = 0;
	char ch, ch2;
	while (s[pos] != '\0')
	{
		ch = s[pos];
		if (ch == '(' || ch == '[' || ch == '{') {
			minStackPushh(ms, ch);
		}
		else {

			ch2 = minStackTopp(ms);
			if (ch == ')' && ch2 != '(' || ch == ']' && ch2 != '[' || ch == '}' && ch2 != '{' || ch2 == -1)
				return false;
			minStackPopp(ms);
		}
		pos++;
	}

	ch2 = minStackTopp(ms);
	minStackFreee(ms);
	// On vérifie que le stack est vide
	if (ch2 == -1) {
		return true;
	}
	return false;
}

//
//void main() {
//
//	char* s = "(]";
//	int val = isValid(s);
//
//}