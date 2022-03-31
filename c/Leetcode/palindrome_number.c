#include "Header.h"

typedef struct {
	int* stack;
	int size;
	int pos;
	int posFront;
} Stack;


Stack* stackCreate(int maxSize) {

	Stack* stack = malloc(sizeof(Stack));
	stack->stack = malloc(sizeof(int) * maxSize);
	stack->size = maxSize;
	stack->posFront = 0;
	stack->pos = 0;

	return stack;
}

void stackPush(Stack* obj, int x) {
	if (obj->pos < obj->size) {

		obj->stack[(obj->pos)++] = x;

	}
}

int stackPop(Stack* obj) {
	if (obj->pos == 0)
		return -1;

	return obj->stack[--(obj->pos)];
}

int stackPopFront(Stack* obj) {
	if (obj->pos == 0)
		return -1;

	return obj->stack[(obj->posFront)++];
}



void stackFree(Stack* obj) {
	free(obj->stack);
	free(obj);
}





bool isPalindromee(int x) {



	if (x < 0)
		return false;
	else if (x < 10)
		return true;

	// Create stack
	Stack* cs = stackCreate(10);
	while (x > 9)
	{
		stackPush(cs, x % 10);
		x /= 10;
	}
	stackPush(cs , x);

	int i, l = cs->pos / 2;
	for (i = 0; i < l; i++) 
		if (stackPop(cs) != stackPopFront(cs))
			return false;


	return true;




}


//void main() {
//	int n = 1231;
//	
//	bool res = isPalindromee(n);
//
//}