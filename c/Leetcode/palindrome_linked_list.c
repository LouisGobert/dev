#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode ListNode;


struct ListNode {
	int val;
	struct ListNode* next;
};

ListNode* reverseList(ListNode* head) {
	ListNode* reversed = head, * temp;

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


bool isPalindrome(ListNode* head) {

	if (!head || !head->next)
		return true;

	ListNode* HEAD = head, * second;

	int lng = 1, mid;
	while (head->next) {
		head = head->next;
		lng++;
	}

	// On obtient l'index du millieux
	mid = (lng /2) + ((lng % 2 != 0) ? 1 : 0);
	//mid = (lng / 2) ;
	//if (lng % 2 != 0)
	//	mid++;

	// On boucle pour set la seconde chaine
	head = HEAD;
	lng = 1;

	while (lng != mid)
	{
		head = head->next;
		lng++;
	}


	second = reverseList(head->next);

	
	while (second) {
		if (second->val != HEAD->val)
			return false;

		second = second->next;
		HEAD = HEAD->next;
	}
	return true;

}

