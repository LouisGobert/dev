#include "Header.h"


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode TreeNode;


void levelOrderHelper(int** tab, int indexTab, TreeNode** queue, int lenQueue, int** returnColumnSizes, int* returnSize) {
	if (lenQueue == 0)
		return;

	TreeNode** newQueue = (TreeNode**)malloc(sizeof(TreeNode*) * (2 * lenQueue));
	tab[indexTab] = malloc(sizeof(int) * (2 * lenQueue));

	TreeNode* temp;
	int i, iNQ = 0;
	for (i = 0; i < lenQueue; i++) {
		temp = queue[i];
		if (temp->left) {
			tab[indexTab][iNQ] = temp->left->val;
			printf("Ajout de %d niveau %d\n", temp->left->val, indexTab);
			newQueue[iNQ++] = temp->left;

		}

		if (temp->right) {
			tab[indexTab][iNQ] = temp->right->val;
			printf("Ajout de %d niveau %d\n", temp->right->val, indexTab);
			newQueue[iNQ++] = temp->right;

		}
	}

	free(queue);
	(*returnColumnSizes)[indexTab] = iNQ;
	levelOrderHelper(tab, ++indexTab, newQueue, iNQ, returnColumnSizes, returnSize);
	(*returnSize)++;

}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
	if (!root) {
		*returnSize = 0;
		return NULL;
	}


	// Max de 100 noeuds
	TreeNode** queue = (TreeNode**)malloc(sizeof(TreeNode*));
	int** tab = (int**)malloc(sizeof(int*) * 1000);
	*returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
	queue[0] = root;
	tab[0] = malloc(sizeof(int) * 1);
	tab[0][0] = root->val;

	(*returnColumnSizes)[0] = 1;
	*returnSize = 1;
	levelOrderHelper(tab, 1, queue, 1, returnColumnSizes, returnSize);


	*returnSize -= 1;
	return tab;
}





//void main() {
//	TreeNode a6 = { 99, NULL, NULL };
//	TreeNode a5 = { 7, NULL, &a6 };
//    //TreeNode a4 = { 15, NULL, NULL };
//    TreeNode a3 = { 9, NULL, &a5 };
//
//	TreeNode l1 = { 3, NULL, NULL };
//	TreeNode l2 = { 5, NULL, NULL };
//    TreeNode a2 = { 2, &l1, &l2 };
//
//    TreeNode a1 = { 3, &a2, &a3 };
//
//	int sizeRtn = 0;
//	int* resSize = NULL;
//    int **res = levelOrder(&a1, &sizeRtn, &resSize);
//
//	for (int i = 0; i < sizeRtn; i++) {
//		for (int x = 0; x < resSize[i]; x++)
//			printf("%d", res[i][x]);
//		printf("\n");
//	}
//
//	free(resSize);
//	free(res);
//}