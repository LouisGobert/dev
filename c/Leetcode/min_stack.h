

typedef struct {

	int* stack;
	int tail;
	int min;
} MinStack;

MinStack* minStackCreate();

void minStackPush(MinStack* obj, int x);

void updateMin(MinStack* obj);

void minStackPop(MinStack* obj);

int minStackTop(MinStack* obj);

int minStackGetMin(MinStack* obj);

void minStackFree(MinStack* obj);
