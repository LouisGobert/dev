#include "Header.h"
#include "min_stack.h"

//typedef struct {
//
//	int* stack;
//	int tail;
//	int min;
//} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
	MinStack* ms = malloc(sizeof(MinStack));
	ms->stack = malloc(sizeof(int));
	ms->tail = -1;
	ms->min = INT_MAX;
	return ms;
}

void minStackPush(MinStack* obj, int x) {
	obj->stack = (int*)realloc(obj->stack, sizeof(int) * (obj->tail + 2));
	obj->stack[++obj->tail] = x;
	if (obj->min > x)
		obj->min = x;
}

/// <summary> Permet la mise à jour du minimum lorsque celui si est supprimé </summary>
/// <param name="obj"> L'objet MinStack </param>
void updateMin(MinStack* obj) {

	obj->min = INT_MAX;
	for (int i = 0; i < obj->tail; i++)
		if (obj->stack[i] < obj->min)
			obj->min = obj->stack[i];
}

void minStackPop(MinStack* obj) {
	if (obj->tail >= 0) {
		// Mise à jour du minimum
		if (obj->stack[obj->tail] == obj->min)
			updateMin(obj);

		obj->stack = (int*)realloc(obj->stack, sizeof(int) * (--obj->tail + 1));
	}

}

int minStackTop(MinStack* obj) {
	if (obj->tail >= 0)
		return obj->stack[obj->tail];
	return -1;
}

int minStackGetMin(MinStack* obj) {
	return obj->min;
}

void minStackFree(MinStack* obj) {
	free(obj->stack);
	free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/

//void main() {
//
//	MinStack* m = minStackCreate();
//	minStackPush(m, 12);
//	minStackPush(m, 23);
//
//	int* temp = m->stack;
//	int z = m->tail+1;
//	
//
//	printArray(temp, z);
//	minStackPop(m);
//	printArray(temp, m->tail + 1);
//
//	minStackFree(m);
//
//
//
//
//}