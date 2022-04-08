#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//  Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode* next;
};


bool hasCycle(struct ListNode* head) {
	if (!head || !(head->next))
		return false;

	struct ListNode* p2 = head->next;

	while (p2 != head) {

		if (p2->next && p2->next->next)
			p2 = p2->next->next;
		else
			return false;

		head = head->next;
	}
	return true;
}


