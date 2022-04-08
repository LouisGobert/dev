#include "Header.h"



struct Node {
	int val;
	struct Node* left;
	struct Node* right;
	struct Node* next;
};
typedef struct Node Node;
 




void connectHelperr(Node** queue, int lenQueue) {
	if (!queue[0]->left) {
		free(queue);
		return;
	}

	Node** newQueue = (Node**)malloc(sizeof(Node*) * (2 * lenQueue));

	Node* test;
	int i, iNQ = 0;
	for (i = 0; i < lenQueue; i++) {
		test = queue[i]->left;
		printf("Nouveau dans queue : %d left\n", queue[i]->left->val);
		newQueue[iNQ++] = queue[i]->left;
		printf("Nouveau dans queue : %d right\n", queue[i]->right->val);
		newQueue[iNQ++] = queue[i]->right;
	}

	newQueue[iNQ-1]->next = NULL;
	for (i = iNQ - 2; i >= 0; i--) {
		printf("Connextion de %d a %d\n", newQueue[i]->val, newQueue[i + 1]->val);
		newQueue[i]->next = newQueue[i + 1];
	}

	for (i = 0; i < iNQ; i++) {
		printf("%d\n", newQueue[i]->val);
	}
	


	free(queue);
	connectHelper(newQueue, iNQ);

}

struct Node* connectt(struct Node* root) {
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
//	Node a6 = { 12, NULL, NULL, NULL }; 
//	Node a5 = { 7, NULL, NULL, NULL };
//	//TreeNode a4 = { 15, NULL, NULL };
//	Node a3 = { 9, &a6, &a5, NULL };
//
//	Node l1 = { 3, NULL, NULL, NULL };
//	Node l2 = { 5, NULL, NULL, NULL };
//	Node a2 = { 2, &l1, &l2, NULL };
//
//	Node a1 = { 3, &a2, &a3, NULL };
//
//	int sizeRtn = 0;
//	int* resSize = NULL;
//	Node* res = connect(&a1, &sizeRtn, &resSize);
//}
