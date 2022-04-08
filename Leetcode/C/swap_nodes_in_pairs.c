#include "Header.h"


typedef struct ListNode ListNode;
struct ListNode {
	int val;
	struct ListNode* next;
};


struct ListNode* swapPairs(struct ListNode* head) {
	if (!head)
		return NULL;
	else if (!head->next)
		return head;


	ListNode* temp = head->next;
	head->next = head->next->next;
	temp->next = head;

	head->next = swapPairs(head->next);


	return temp;
}

//void main() {
//
//	ListNode a5 = { 5,NULL };
//	ListNode a4 = { 4, &a5 };
//	ListNode a3 = { 3, &a4 };
//	ListNode a2 = { 2, &a3 };
//	ListNode a1 = { 1, &a2 };
//
//
//
//	ListNode* res = swapPairs(&a1);
//
//}