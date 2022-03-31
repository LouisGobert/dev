#include "Header.h"

typedef struct LinkedListValued LinkedListValued;
struct LinkedListValued {
	int value;  
	int numberOfValue;
	bool isInReturnTab;
	LinkedListValued* next;
};



LinkedListValued* LindedListValuedCreate() {

	LinkedListValued* t = malloc(sizeof * t);
	t->next = NULL;
	t->value = 0;
	t->isInReturnTab = false;
	t->numberOfValue = 0;

	return t;
}

void LinkedListValuedFree(LinkedListValued* obj) {


	LinkedListValued* temp;
	while (obj->next) {
		temp = obj->next;
		obj->next = obj->next->next;

		free(temp);

	}
	free(obj);

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElementt(int* nums, int numsSize, int* returnSize) {

	LinkedListValued* list = LindedListValuedCreate();
	LinkedListValued* head = list;

	int* returnTab = malloc(sizeof(int) * 2);
	int sizeDiv3 = numsSize / 3;
	int indexReturnTab = 0;


	for (int i = 0; i < numsSize; i++) {
		// Parcour de la liste
		list = head;
		while (list->next && list->value != nums[i])
		{
			/*if (maxMajority < list->numberOfValue) {
				maxMajority = list->numberOfValue;
				valueOfMaxMajority = list->value;
				if (maxMajority > (numsSize / 2)) {
					LinkedListValuedFree(head);
					return valueOfMaxMajority;
				}
			}*/
			list = list->next;
		}

		if (list->value == nums[i]) {
			list->numberOfValue++;
			if (list->numberOfValue > sizeDiv3 && list->isInReturnTab == false) {
				returnTab[indexReturnTab++] = nums[i];
				list->isInReturnTab = true;
				if (indexReturnTab == 2) {
					LinkedListValuedFree(head);
					*returnSize = indexReturnTab;
					return returnTab;
				}
				
			}
		}
		else {
			// Creer une nouvel listlisted
			list->next = LindedListValuedCreate();
			list->next->value = nums[i];
			list->next->numberOfValue += 1;
			if (list->next->numberOfValue > sizeDiv3 && list->next->isInReturnTab == false) {
				returnTab[indexReturnTab++] = nums[i];
				list->next->isInReturnTab = true;
				if (indexReturnTab == 2) {
					LinkedListValuedFree(head);
					*returnSize = indexReturnTab;
					return returnTab;
				}
			}
		}
	}
	*returnSize = indexReturnTab;

	LinkedListValuedFree(head);
	return returnTab;

}




//
//void main() {
//	int test[] = { 2, 2};
//	int sizeRet = 0;
//	int res = majorityElementt(test, 2, &sizeRet);
//		
//}