#include "Header.h"


struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TreeNode;


TreeNode* deleteNode(TreeNode* root, int key) {
	if (!root) return NULL;

	TreeNode* lastRoot = NULL, * HeadTemp = root;
	while (root->val != key)
	{
		lastRoot = root;

		if (key > root->val)
			root = root->right;
		else
			root = root->left;
	}

	// Count the child
	if (!root->left && !root->right) {
		if (!lastRoot)
			return NULL;
		else {
			if (lastRoot->left->val == key)
				lastRoot->left = NULL;
			else
				lastRoot->right = NULL;
		}
	}
	else if (!root->left) {
		if (!lastRoot)
			return root->right;
		else {
			if (lastRoot->left->val == key)
				lastRoot->left = NULL;
			else
				lastRoot->right = NULL;
		}
	}
	
		



	return HeadTemp;
}



void main() {
	TreeNode a6 = { 99, NULL, NULL };
	TreeNode a5 = { 7, NULL, &a6 };
	//TreeNode a4 = { 15, NULL, NULL };
	TreeNode a3 = { 3, NULL, &a5 };

	TreeNode l1 = { 1, NULL, NULL };
	TreeNode l2 = { 7, NULL, NULL };
	TreeNode a2 = { 2, &l1, &a3 };

	TreeNode a1 = { 4, &a2, &l2 };

	TreeNode* res = searchBST(&a1, 2);

}