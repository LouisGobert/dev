#include "unit.h"

void initUnitTest(const char *functionName) {
	printf("Running tests for '%s'...\n", functionName);
	unitTest.startTime = clock();
	unitTest.runs = 0;
	unitTest.failures = 0;
}

void displayUnitTestReport() {
	clock_t endTime = clock();
	double elapsedTime = (double)(endTime - unitTest.startTime) / CLOCKS_PER_SEC;
	printf("Tests finished after %.3f s\n", elapsedTime);
	printf("Runs: %d, Failures: %d\n\n", unitTest.runs, unitTest.failures);
}

int compareArrays(const void *t1, const void *t2, int length, size_t datasize) {
	int i;
	for (i = 0; i < length; i++) {
		if (memcmp((char *)t1 + i * datasize, (char *)t2 + i * datasize, datasize) != 0) {
			return i;
		}
	}
	return -1;
}

int compareFloatArrays(const float *t1, const float *t2, int length, float delta) {
	int i;
	for (i = 0; i < length; i++) {
		if (fabs(t1[i] - t2[i]) > fabs(delta)) {
			return i;
		}
	}
	return -1;
}

int checkIntArrayBetween(const int *t, int length, int lower, int upper) {
	int i;
	for (i = 0; i < length; i++) {
		if (t[i] < lower || t[i] > upper) {
			return i;
		}
	}
	return -1;
}

int checkFloatArrayBetween(const float *t, int length, float lower, float upper, float delta) {
	int i;
	for (i = 0; i < length; i++) {
		if (t[i] < lower - delta || t[i] > upper + delta) {
			return i;
		}
	}
	return -1;
}