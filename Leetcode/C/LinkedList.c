#include "LinkedList.h"



int linkedListGet(LinkedList* root, int index) {

	if (!root || index < 0)
		return -1;

	int pos = 0;
	while (root->next && pos < index)
	{
		root = root->next;
		pos++;
	}

	if (pos == index)
		return root->val;
	return -1;
}

void linkedListAddAtHead(LinkedList* root, int val) {

}

void linkedListAddAtTail(LinkedList* root, int val) {

}


bool linkedListAddAtIndex(LinkedList* root, int index, int val) {

	if (!root || index < 0)				// No solution
		return false;				
	else if (index == 0)				// Head solution
		linkedListAddAtHead(root, val);		
	else {								// Inside solution

		// Loop until we arive at the index
		int i = 0;
		while (i < index && root->next)
		{
			root = root->next;
			i++;
		}

		// If we are at end of linkedlist -> addAtTail
		if (!root->next)
			linkedListAddAtTail(root, val);
		else
		{
			/// 1: Create un new node
			/// 2: Add him the value want
			/// 3: Link tmp next to root next
			/// 4: Link root next to temp
			LinkedList* tmp = (LinkedList*)malloc(sizeof(tmp));
			tmp->val = val;
			tmp->next = root->next;
			root->next = tmp;
		}
	}
	return true;
}


int linkedListLen(LinkedList* root) {

	if (!root)
		return -1;

	int len = 0;
	while (root)
	{
		root = root->next;
		len++;
	}
	return len;
}


int* linkedListToArray(LinkedList* root) {

	if (!root)
		return NULL;

	int len = linkedListLen(root), i;
	int* array = (int*)malloc(sizeof(int) * len);

	for (i = 0; i < len; i++) {
		array[i] = root->val;
		root = root->next;
	}
}

void linkedListPrint(LinkedList* root) {
	
	while (root)
	{
		printf("%d -> ", root->val);
		root = root->next;
	}
}



/*void main() {

	testAllLinkedList();
}*/