#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;
};


struct ListNode* removeElements(struct ListNode* head, int val) {

	if (!head)
		return NULL;


	// Delete the first ele
	while (head->val == val) {
		if (!head->next)
			return NULL;
		head = head->next;
	}

	// We memorize the start of the LN
	struct ListNode* mem = head, *temp;

	while (head && head->next) {
		
		
		if (head->next->val == val) {
			temp = head;
			while (temp && temp->next && temp->next->val == val)
			{
				temp = temp->next;
			}
			head->next = temp->next;
		}
			

		head = head->next;
	}

	return mem;

}

