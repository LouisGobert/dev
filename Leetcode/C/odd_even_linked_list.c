#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;
};


struct ListNode* oddEvenList(struct ListNode* head) {

	// ODD  = impaire
	// EVEN = paire

	struct ListNode* even = NULL, *sEven = NULL, *sOdd = NULL;
	sOdd = head;
	if (head->next)
		even = head->next;

	sEven = even;

	while (head && head->next)
	{
		if (head->next && head->next->next){
			head->next = head->next->next;
			head = head->next;
		}
		else
			head->next = NULL;

		if (even->next && even->next->next)
			even->next = even->next->next;
		else
			even->next = NULL;

		
		even = even->next;
	}

	head->next = sEven;
	return sOdd;
}


