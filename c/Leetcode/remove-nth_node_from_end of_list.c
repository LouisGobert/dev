#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;
};



struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

	if (!head->next)
		return NULL;

	int step = 0;
	struct ListNode* runner = head, *walker = head;

	while (runner->next) {

		if (step >= n)
			walker = walker->next;

		step++;
		runner = runner->next;
	}

	if (n == 1) {
		walker->next = NULL;
	}
	else if (n - 1 == step) {
		// Remove the first element
		return head->next;
	}
	else {
		if (walker->next->next)
			walker->next = walker->next->next;
	}
		
	
	return head;

}


