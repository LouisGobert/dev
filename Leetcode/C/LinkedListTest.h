#ifndef LINKED_LIST_TEST_H
#define LINKED_LIST_TEST_H


#include "LinkedList.h"

void testLinkedListPrint();
void testLinkedListAddAtIndex();
void testAllLinkedList();

LinkedList l5 = { 5, NULL};
LinkedList l4 = { 4, &l5};
LinkedList l3 = { 3, &l4};
LinkedList l2 = { 2, &l3};
LinkedList l1 = { 1, &l2};

#endif

