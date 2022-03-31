#include "Header.h"


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode TreeNode;


bool symmetricHelper(TreeNode* left, TreeNode* right) {

	if (!left && !right)
		return true;
	else if (!left || !right)
		return false;

	return (left->val == right->val && symmetricHelper(left->left, right->right) && symmetricHelper(left->right, right->left));
}


bool isSymmetric(struct TreeNode* root) {
	return symmetricHelper(root, root);
}



//void main() {
//	TreeNode r3 = { 3, NULL, NULL };
//	TreeNode r2 = { 4, NULL, NULL };
//    TreeNode r1 = { 2, &r2, &r3 };
//
//	TreeNode l3 = { 4, NULL, NULL };
//	TreeNode l2 = { 3, NULL, NULL };
//    TreeNode l1 = { 2, &l2, &l3 };
//
//    TreeNode a1 = { 1, &l1, &r1 };
//
//    bool res = isSymmetric(&a1);
//	
//}