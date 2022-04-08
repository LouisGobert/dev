#include "Header.h"



struct Node {
	int val;
	struct Node* left;
	struct Node* right;
	struct Node* next;
};
typedef struct Node Node;





void connectHelper(Node** queue, int lenQueue) {


	Node** newQueue = (Node**)malloc(sizeof(Node*) * (2 * lenQueue));

	int i, newLen = 0;
	for (i = 0; i < lenQueue; i++) {
		if (queue[i]->left)
			newQueue[newLen++] = queue[i]->left;
		
		if (queue[i]->right) 
			newQueue[newLen++] = queue[i]->right;
	}

	free(queue);
	if (newLen == 0) {
		free(newQueue);
		return;
	}

	newQueue[newLen - 1]->next = NULL;
	for (i = newLen - 2; i >= 0; i--)
		newQueue[i]->next = newQueue[i + 1];


	
	connectHelper(newQueue, newLen);

}

struct Node* connect(struct Node* root) {
	if (!root)
		return NULL;


	// Max de 100 noeuds
	Node** queue = (Node**)malloc(sizeof(Node*));
	queue[0] = root;
	root->next = NULL;

	connectHelper(queue, 1);
	return root;
}





//void main() {
//	Node a6 = { 15, NULL, NULL, NULL }; 
//	Node a5 = { 7, NULL, NULL, NULL };
//	//TreeNode a4 = { 15, NULL, NULL };
//	Node a3 = { 20, &a6, &a5, NULL };
//
//
//	Node l2 = { 9, NULL, NULL, NULL };
//
//	Node a1 = { 3, &l2, &a3, NULL };
//
//	Node* res = connect(&a1);
//}
