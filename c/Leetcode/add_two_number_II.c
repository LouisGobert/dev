#include "Header.h";

struct ListNode {
	int val;
	struct ListNode* next;
	
};
typedef struct ListNode ListNode; 


typedef struct {
	int* stack;
	int size;
	int pos;
} stackO;


stackO* stackCreatee(int maxSize) {

	stackO* stack = malloc(sizeof(stackO));
	stack->stack = malloc(sizeof(int) * maxSize);
	stack->size = maxSize;
	stack->pos = 0;

	return stack;
}

void stackPushh(stackO* obj, int x) {
	if (obj->pos < obj->size) {
		obj->stack[(obj->pos)++] = x;
	}
}

int stackPopp(stackO* obj) {
	if (obj->pos == 0)
		return -1;
	return obj->stack[--(obj->pos)];
}


void stackFreee(stackO* obj) {
	free(obj->stack);
	free(obj);
}


struct ListNode* reverseListt(struct ListNode* head) {
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




struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

	// Create the two stack
	stackO* stack1 = stackCreatee(50);
	stackO* stack2 = stackCreatee(50);

	ListNode* head1 = l1, * head2 = l2, * newList, * headNewList;

	// Create stack
	while (l1)
	{
		stackPushh(stack1, l1->val);
		l1 = l1->next;
	}

	while (l2)
	{
		stackPushh(stack2, l2->val);
		l2 = l2->next;
	}


	if (stack1->pos > stack2->pos)
		newList = head1;
	else
		newList = head2;

	headNewList = newList;
	// Sum and create new list
	int sum, c = 0, t;
	while (newList->next)
	{
		sum = c;
		if ((t = stackPopp(stack1)) != -1)
			sum += t;
		if ((t = stackPopp(stack2)) != -1)
			sum += t;

		if (sum > 9) {
			c = 1;
			sum %= 10;
		}
		else
			c = 0;

		newList->val = sum;
		newList = newList->next;
	}

	sum = c;
	if ((t = stackPopp(stack1)) != -1)
		sum += t;
	if ((t = stackPopp(stack2)) != -1)
		sum += t;

	if (sum > 9) {
		c = 1;
		sum %= 10;
	}
	else
		c = 0;

	newList->val = sum;


	if (c) {
		if (headNewList == head1) {
			newList->next = head2;
		}
		else
			newList->next = head1;

		newList = newList->next;
		newList->next = NULL;
		newList->val = 1;
	}

	return reverseListt(headNewList);
}

//void main() {
//	ListNode b4 = { 9, NULL };
//	ListNode b3 = { 9, NULL };
//	ListNode b2 = { 9,&b3 };
//	ListNode b1 = { 9, &b2 };
//
//	ListNode a3 = { 1, NULL };
//	ListNode a2 = { 0, &a3 };
//	ListNode a1 = { 1, &a2 };
//
//
//
//	ListNode* res = addTwoNumbers(&a1, &b1);
//
//	while (res)
//	{
//		printf("%d -> ", res->val);
//		res = res->next;
//	}
//}