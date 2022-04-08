#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {

	struct ListNode* pA = headA, * pB = headB;
	int lA = 0, lB = 0;

	// On compte le len A
	while (headA->next) {
		headA = headA->next;
		lA++;
	}

	// On compte le len B
	while (headB->next) {
		headB = headB->next;
		lB++;
	}

	if (headA != headB)
		return NULL;

	headA = pA;
	headB = pB;
	int diff;
	if (lA > lB) {
		diff = lA - lB;
		for (int i = 0; i < diff; i++) {
			headA = headA->next;

		}
	}
	else {
		diff = lB - lA;
		for (int i = 0; i < diff; i++) {

			headB = headB->next;
		}
	}

	while (headA != headB) {

		headA = headA->next;
		headB = headB->next;
	}

	return headA;



}

