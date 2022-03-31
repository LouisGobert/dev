#include "Header.h"



typedef struct {
	int* stack;
	int size;
	int pos;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {

	CustomStack* customStack = malloc(sizeof(CustomStack));
	customStack->stack = malloc(sizeof(int) * maxSize);
	customStack->size = maxSize;
	customStack->pos = 0;

	return customStack;
}

void customStackPush(CustomStack* obj, int x) {
	if (obj->pos < obj->size) {

		obj->stack[(obj->pos)++] = x;

	}
}

int customStackPop(CustomStack* obj) {
	if (obj->pos == 0)
		return -1;

	return obj->stack[--(obj->pos)];
}

void customStackIncrement(CustomStack* obj, int k, int val) {

	for (int i = 0; i < obj->pos && i < k; i++) {
		obj->stack[i] += val;
	}
}

void customStackFree(CustomStack* obj) {
	free(obj->stack);
	free(obj);
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);

 * int param_2 = customStackPop(obj);

 * customStackIncrement(obj, k, val);

 * customStackFree(obj);
*/

//
//void main() {
//
//
//	CustomStack* cs = customStackCreate(2);
//
//	customStackPush(cs, 10);
//	customStackPush(cs, 13);
//	customStackPush(cs, 45);
//
//	customStackIncrement(cs, 13, 10);
//
//	int res1 = customStackPop(cs);
//	int res2 = customStackPop(cs);
//	int res3 = customStackPop(cs);
//	int r = customStackPop(cs);
//
//
//	customStackFree(cs);
//
//}