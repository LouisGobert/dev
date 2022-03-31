#include "Header.h"



struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode ListNode;
 


struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (!head)
		return NULL;
	else if (!head->next)
		return head;

	ListNode *HEAD = head, *ptr = head;
	head = head->next;
	while (head)
	{
		if (ptr->val == head->val)
			ptr->next = head->next;
		else {
			ptr = ptr->next;
		}
		head = head->next;

	}

	return HEAD;
}


//void main() {
//	ListNode a5 = { 3,NULL };
//	ListNode a4 = { 3, &a5 };
//	ListNode a3 = { 2, &a4 };
//	ListNode a2 = { 1, &a3 };
//	ListNode a1 = { 1, &a2 };
//	
//	
//	
//	ListNode* res = deleteDuplicates(&a1);
//}