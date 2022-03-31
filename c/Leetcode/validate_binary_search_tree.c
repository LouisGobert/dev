#include "Header.h"


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode TreeNode;


 
bool helperValidBST(TreeNode *root, int max, int min) {
	if (!root) return true;

	if (max != INT_MIN && root->val > max) return false;
	if (min != INT_MAX && root->val < min) return false;


	if (!helperValidBST(root->left, root->val, min)) return false;
	if (!helperValidBST(root->right, max, root->val)) return false;

	return true;
	
}

bool isValidBST(struct TreeNode* root) {
	
	int min = INT_MAX, max= INT_MIN;
	return helperValidBST(root, INT_MIN, INT_MAX);
}


//void main() {
//	TreeNode a6 = { 7, NULL, NULL };
//	TreeNode a5 = { 3, NULL, NULL };
//    TreeNode nn = { 1, NULL, NULL };
//    TreeNode a3 = { 6, &nn, &a6 };
//	TreeNode l1 = { 1, NULL, NULL };
//	TreeNode l2 = { 4, &a5, NULL };
//    TreeNode a2 = { 2, &l1, &l2 };
//
//    TreeNode a1 = { 5, &a2, &a3 };
//
//	bool res = isValidBST(&a1);
//}