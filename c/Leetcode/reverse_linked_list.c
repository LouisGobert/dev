#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;
};





struct ListNode* reverseListX(struct ListNode* head) {
	struct ListNode* reversed = head, * temp;

	while (reversed && reversed->next) {
		temp = reversed->next;
		if (reversed->next->next)
			reversed->next = reversed->next->next;
		else
			reversed->next = NULL;
		temp->next = head;
		head = temp;
	}
	return head;
}

