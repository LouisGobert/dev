

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

typedef struct ListNode ListNode;


struct ListNode {
	int val;
	struct ListNode* next;
};

void insertAtEnd(ListNode* obj, int val) {

	while (obj->next)
	{
		obj = obj->next;
	}

	ListNode* value = malloc(sizeof * value);
	value->next = NULL;
	value->val = val;

	obj->next = value;
}

struct ListNode* addTwoNumber(struct ListNode* l1, struct ListNode* l2) {

	if (!l1 || !l2)
		return false;

	int c = 0, sum;
	ListNode* value = malloc(sizeof * value), *head;
	value->val = -1;
	value->next = NULL;
	head = value;

	while (l1 || l2 || c)
	{
		
		sum = ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0) + c;
		c = 0;
		insertAtEnd(value, sum % 10);
		if (sum >= 10) {
			c = 1;
		} 

		if (l1)
			l1 = l1->next;

		if (l2)
			l2 = l2->next;

		value = value->next;
		
		
	}


	// Create a ListNode with sum

	return head->next;
}



