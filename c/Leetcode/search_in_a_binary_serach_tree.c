#include "Header.h"



 
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode TreeNode;


struct TreeNode* searchBST(struct TreeNode* root, int val) {
	if (!root) return NULL;
	if (root->val == val) return root;

	while (root)
	{
		if (val == root->val)
			return root;
		if (val > root->val)
			root = root->right;
		else
			root = root->left;
	}
	if (root && val == root->val)
		return root;
	return NULL;
}

//void main() {
//	TreeNode a6 = { 99, NULL, NULL };
//	TreeNode a5 = { 7, NULL, &a6 };
//    //TreeNode a4 = { 15, NULL, NULL };
//    TreeNode a3 = { 3, NULL, &a5 };
//
//	TreeNode l1 = { 1, NULL, NULL };
//	TreeNode l2 = { 7, NULL, NULL };
//    TreeNode a2 = { 2, &l1, &a3 };
//
//    TreeNode a1 = { 4, &a2, &l2 };
//
//	TreeNode* res = searchBST(&a1, 2);
//
//}