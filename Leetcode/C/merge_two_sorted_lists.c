

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode ListNode;


struct ListNode {
	int val;
	struct ListNode* next;
};

ListNode* deleteAtIndex(ListNode* list, int index) {



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

ListNode* addNodeAtIndex(ListNode* obj, ListNode *node, int index) {

	ListNode* HEAD = obj, *t;
	
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




ListNode* invertTwoNode(ListNode* list, int p1, int p2) {

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
	ListNode* p1Val = NULL, *HEAD = list;

	while (pos != p1 && list)
	{
		list = list->next;
		pos++;
	}

	p1Val = list;
	HEAD = deleteAtIndex(HEAD, pos);
	p1Val->next = NULL;
	HEAD = addNodeAtIndex(HEAD, p1Val, p2);

	/// Pareil pour le deuxième point
	list = HEAD;
	pos = 0;
	while (pos != p2-1 && list)
	{
		list = list->next;
		pos++;
	}

	p1Val = list;
	HEAD = deleteAtIndex(HEAD, pos);
	p1Val->next = NULL;
	HEAD = addNodeAtIndex(HEAD, p1Val, p1);

	return HEAD;

}




ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	if (!l1 && !l2)
		return NULL;
	else if (!l1)
		return l2;
	else if (!l2)
		return l1;

	ListNode* HEAD = l1, *merge = HEAD, *min = l1, *next;

	// On boucle et on ajoute l2 a la fin de l1
	while (l1->next)
		l1 = l1->next;
	
	l1->next = l2;

	l1 = HEAD;
	merge = l1;

	int posP = 0, minPos = 0, posSec = 0, tt = 0;
	while (merge) {

		l1 = merge;
		min = l1;
		minPos = posP;
		posSec = posP;
		while (l1)
		{
			if (min->val > l1->val) {
				min = l1;
				minPos = posSec;
			}

			posSec++;
			l1 = l1->next;
		}

		if (minPos != posP)
			HEAD = invertTwoNode(HEAD, minPos, posP);

		merge = HEAD;
		posP++;
		tt = 0;
		while (tt != posP)
		{
			merge = merge->next;
			tt++;
		}
		
	}


	return HEAD;


}

