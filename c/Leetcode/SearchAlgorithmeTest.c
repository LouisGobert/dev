#include "SearchAlgorithmeTest.h"



void testBinarySearch() {
	initUnitTest("Test binary search");

	int tab1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int res = binarySearch(tab1, 12, 10);
	assertIntEquals(-1, res);

	res = binarySearch(tab1, 2, 10);
	assertIntEquals(1, res);


	displayUnitTestReport();


}