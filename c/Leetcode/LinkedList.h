#ifndef LINDKED_LIST_H
#define LINDKED_LIST_H

#include "Header.h"


typedef struct LinkedList {
	int val;
	struct LinkedList* next;

} LinkedList;


void linkedListPrint(LinkedList* root);
int* linkedListToArray(LinkedList* root);
int linkedListLen(LinkedList* root);
bool linkedListAddAtIndex(LinkedList* root, int index, int val);
int linkedListGet(LinkedList* root, int index);


#endif // !LINDKED_LIST_H
