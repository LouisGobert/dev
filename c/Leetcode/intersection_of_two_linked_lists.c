#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* getIntersectionNodeXXX(struct ListNode* headA, struct ListNode* headB) {

	if (!headA || !headB)
		return NULL;
	else if (headA->next == headB || headB->next == headA)
		return headB;

	struct ListNode* temp = headB;
	while (headA) {

		while (headB) {
			if (headA == headB) {
				return headA;
			}
			headB = headB->next;
		}

		headB = temp;
		headA = headA->next;
	}
	return NULL;

}
