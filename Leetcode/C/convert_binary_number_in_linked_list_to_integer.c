#include <stdio.h>

//  Definition for singly-linked list.
struct ListNode {
	int val;
	struct ListNode* next;
};
typedef struct ListNode ListNode;


int getDecimalValue(struct ListNode* head) {

	int res = 0;

	//while (head && !head->val)
	//{
	//	head = head->next;
	//}

	while (head)
	{
		res = (res << 1 ) | head->val;
		head = head->next;
	}

	return res;
}

//void main() {
//
//	ListNode p3 = { 1, NULL };
//	ListNode p2 = { 0, &p3 };
//	ListNode p1 = { 1, &p2 };
//
//	int res = getDecimalValue(&p1);
//
//
//}

