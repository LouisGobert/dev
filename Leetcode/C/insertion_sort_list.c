#include "Header.h"

struct ListNode {

	int val;
	struct ListNode* next;

};

typedef struct ListNode ListNode;

ListNode* deleteAtIndexxx(ListNode* list, int index) {



	// La premiere casse
	if (index == 0) {
		return list->next;
	}

	ListNode* HEAD = list;

	int i = 0;
	while (list && index - 1 != i) {
		list = list->next;
		i++;
	}

	if (index - 1 == i) {
		if (list->next)
			list->next = list->next->next;
		else
			list->next = NULL;
	}

	return HEAD;
}

ListNode* addNodeAtIndexxx(ListNode* obj, ListNode* node, int index) {

	ListNode* HEAD = obj, * t;

	// If index -> 0
	if (index == 0) {
		node->next = obj;
		obj = node;
		return obj;
	}

	/* On boucle jusq'à arriver a l'obj d'index -1*/
	int i = 0;
	while (i != index - 1 && obj->next != NULL) {
		obj = obj->next;
		i++;
	}

	if (obj->next == NULL)
		obj->next = node;
	else {
		t = obj->next;
		obj->next = node;
		node->next = t;


	}

	return HEAD;

}

int linked_list_lennn(ListNode* ll) {

	if (!ll)
		return 0;

	int ln = 0;
	while (ll)
	{
		ll = ll->next;
		ln++;
	}
	return ln;
}

ListNode* invertTwoNodeee(ListNode* list, int p1, int p2) {

	if (!list || p1 == p2)
		return NULL;

	// Get the p1 and his pos
	// Dellete Him
	int pos = 0;

	if (p1 > p2) {
		pos = p1;
		p1 = p2;
		p2 = pos;
	}
	pos = 0;
	ListNode* p1Val = NULL, * HEAD = list;

	while (pos != p1 && list)
	{
		list = list->next;
		pos++;
	}

	p1Val = list;
	HEAD = deleteAtIndexxx(HEAD, pos);
	p1Val->next = NULL;
	HEAD = addNodeAtIndexxx(HEAD, p1Val, p2);

	/// Pareil pour le deuxième point
	list = HEAD;
	pos = 0;
	while (pos != p2 - 1 && list)
	{
		list = list->next;
		pos++;
	}

	p1Val = list;
	HEAD = deleteAtIndexxx(HEAD, pos);
	p1Val->next = NULL;
	HEAD = addNodeAtIndexxx(HEAD, p1Val, p1);

	return HEAD;

}

struct ListNode* insertionSortList(struct ListNode* head) {
	

	if (!head)
		return NULL;
	if (!head->next)
		return head;

	int len = linked_list_lennn(head);
	int indexList;

	int indexSubList;
	ListNode* headTemp = head;
	ListNode* subList = head;
	ListNode* minNode;
	int minPos, t;

	for (indexList = 0; indexList < len - 1; indexList++) {

		minNode = head;
		subList = head->next;
		minPos = indexList;
		indexSubList = indexList + 1;

		while (subList) {
			if (minNode->val > subList->val) {
				minNode = subList;
				minPos = indexSubList;
			}



			subList = subList->next;
			indexSubList++;
		}

		// If the min have change
		if (minPos != indexList) {
			headTemp = invertTwoNodeee(headTemp, indexList, minPos);
			head = headTemp;
			t = 0;
			while (t != indexList)
			{
				head = head->next;
				t++;
			}
		}

		head = head->next;
	}

	return headTemp;

}


//void main() {
//
//	/*ListNode a5 = { 0,NULL };
//	ListNode a4 = { 4, &a5 };
//	ListNode a3 = { 3, &a4 };
//	ListNode a2 = { 5, &a3 };
//	ListNode a1 = { -1, &a2 };*/
//
//	ListNode aa1 = { 1, NULL };
//
//
//
//	ListNode* p = insertionSortList(&aa1);
//}