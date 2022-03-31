#include "unit.h"
#include "LinkedList.h"
#include "LinkedListTest.h"


void testLinkedListPrint() {
	initUnitTest("Print LinkedList");

	linkedListPrint(&l1);

	displayUnitTestReport();
}

void testLinkedListAddAtIndex(){

	initUnitTest("Add At Index - LinkedList");
	int tab[6] = {1, 2, 0, 3, 4, 5};
	linkedListAddAtIndex(&l1, 2, 0);

	int* res = linkedListToArray(&l1);
	assertIntArrayEquals(tab, res, 6);

	free(res);
	displayUnitTestReport();
}



void testAllLinkedList() {
	testLinkedListPrint();
	testLinkedListAddAtIndex();
}

