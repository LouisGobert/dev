#include <stdio.h>
#include <stdlib.h>
#define VOID -1010101


typedef struct MyLinkedList MyLinkedList;
struct MyLinkedList {

	int val;
	MyLinkedList* next;

};

int myLinkedListGet(MyLinkedList* obj, int index);

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {

	MyLinkedList* t = malloc(sizeof * t);
	t->next = NULL;
	t->val = VOID;

	return t;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {


	for (int i = 0; i < index; i++) {

		if (obj->next == NULL) {
			return -1;
		}
		obj = obj->next;
	}

	return obj->val;

}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {

	// If the Ll is not empty
	if (obj->val != VOID) {
		MyLinkedList* copy = malloc(sizeof * copy);
		*copy = *obj;

		obj->next = copy;
		obj->val = val;

		printf("");
	}
	else {
		obj->val = val;
	}

}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {

	if (obj->val == VOID) {
		obj->val = val;
	}
	else {

		MyLinkedList* tail = malloc(sizeof * tail);
		tail->val = val;
		tail->next = NULL;

		// On boucle jusqu'a trouvé la fin
		while (obj->next != NULL)
		{
			obj = obj->next;
		}

		obj->next = tail;
	}
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list,
the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
/*
*		##  ##  ##  ##  ##
		0   1   2   3   4

*/
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

	// If index -> 0
	if (index == 0) {
		myLinkedListAddAtHead(obj, val);
		return;
	}

	/* On boucle jusq'à arriver a l'obj d'index -1*/
	int i = 0;
	while (i != index - 1 && obj->next != NULL) {
		obj = obj->next;
		i++;
	}



	if (obj->next == NULL)
		myLinkedListAddAtTail(obj, val);
	else {
		MyLinkedList* temp = malloc(sizeof * temp);
		temp->val = val;
		temp->next = obj->next;

		obj->next = temp;
	}

}

/** Delete the index-th node in the linked list, if the index is valid. */
/*
*		##  ##  ##  ##  ##
		0   1   2   3   4

*/
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {

	MyLinkedList* temp;

	if (index == 0) {

		if (!obj->next) {
			obj->val = VOID;
		}
		else {
			*obj = *obj->next;
		}


		return;
	}


	int i = 0;
	while (obj->next != NULL && index - 1 > i) {
		obj = obj->next;
		i++;
	}
	if (index - 1 == i) {
		if (obj->next != NULL)
			obj->next = obj->next->next;


	}
	else {
		// Delete the last item
		temp = obj->next;
		obj->next = NULL;
		free(temp);
	}

}

void myLinkedListFree(MyLinkedList* obj) {


	MyLinkedList* temp;
	while (obj->next) {
		temp = obj->next;
		obj->next = obj->next->next;

		free(temp);

	}

}

void printLinkedList(MyLinkedList* obj) {

	int i = 0;
	printf("%d = %d\n", i + 0, obj->val);
	while (obj->next != NULL) {

		i++;
		obj = obj->next;
		printf("%d = %d\n", i, obj->val);


	}
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/


/*void main() {

	MyLinkedList* obj = myLinkedListCreate();

	myLinkedListAddAtTail(obj, 1);
	printf("%d\n", myLinkedListGet(obj, 0));

	/*
	int param_1 = myLinkedListGet(obj, 2);


	myLinkedListAddAtHead(obj, 0);
	myLinkedListAddAtTail(obj, 1);
	myLinkedListAddAtTail(obj, 2);
	myLinkedListAddAtTail(obj, 3);


	myLinkedListAddAtIndex(obj, 2, 99);
	myLinkedListAddAtIndex(obj, 3, 33);
	myLinkedListAddAtIndex(obj, 0, -1);


	printLinkedList(obj);
	printf("\n----------------\n");

	myLinkedListDeleteAtIndex(obj, 0);
	printLinkedList(obj);
	printf("\n----------------\n");
	myLinkedListDeleteAtIndex(obj, 2);

	printLinkedList(obj);
	printf("\n----------------\n");


	myLinkedListDeleteAtIndex(obj, 4);
	myLinkedListDeleteAtIndex(obj, 0);
	myLinkedListDeleteAtIndex(obj, 0);
	myLinkedListDeleteAtIndex(obj, 0);
	myLinkedListDeleteAtIndex(obj, 0);




	printLinkedList(obj);

	



	myLinkedListFree(obj);


}*/
