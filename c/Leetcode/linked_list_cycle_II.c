#include <stdio.h>

//  Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode* next;
};
/*/
struct ListNode* detectCycle(struct ListNode* head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			slow = head;
			while (slow != fast) {
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return NULL;
}*/

struct ListNode* detectCycle(struct ListNode* head) {
	if (!head || !(head->next))
		return NULL;

	struct ListNode* p1 = head, * p2 = head;

	while (p2 && p2->next) {
		p1 = p1->next;
		p2 = p2->next->next;

		if (p1 == p2) {
			p1 = head;
			while (p1 != p2) {
				p1 = p1->next;
				p2 = p2->next;
			}
			return p1;
		}
	}
	return NULL;

}