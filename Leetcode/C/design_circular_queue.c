#include "Header.h"



typedef struct {
	int* queue;
	int len;
	int head;
	int tail;
	int nbElement;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* mcq = malloc(sizeof(MyCircularQueue));
	mcq->queue = malloc(sizeof(int) * k);
	mcq->len = k;
	mcq->head = 0;
	mcq->tail = -1;
	mcq->nbElement = 0;

	return mcq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
		return false;

	obj->tail = (obj->tail + 1) % obj->len;
	obj->queue[obj->tail] = value;
	++obj->nbElement;

	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->queue[obj->head] = -1;
	obj->head = (obj->head + 1) % obj->len;
	--obj->nbElement;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {

	return (obj->nbElement) ? obj->queue[obj->head] : -1;
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	return (obj->nbElement) ? obj->queue[obj->tail] : -1;
}

/** Checks whether the circular queue is empty or not. */
 bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->nbElement == 0;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return obj->nbElement == obj->len;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->queue);
	free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/


//void main() {
//	MyCircularQueue* mcq = myCircularQueueCreate(3);
//
//
//	clock_t start = clock();
//	for (int i = 0; i < 10000000; i++) {
//		myCircularQueueEnQueue(mcq, 1);
//		myCircularQueueEnQueue(mcq, 2);
//		myCircularQueueEnQueue(mcq, 3);
//		myCircularQueueEnQueue(mcq, 4);
//
//		myCircularQueueRear(mcq);
//		myCircularQueueIsFull(mcq);
//
//
//		myCircularQueueDeQueue(mcq);
//		myCircularQueueDeQueue(mcq);
//
//		myCircularQueueRear(mcq);
//		myCircularQueueDeQueue(mcq);
//
//	};
//
//	clock_t time = clock() - start;
//	printf("Time : %dms", time);
//	myCircularQueueFree(mcq);
//
//}





