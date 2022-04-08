#include "Header.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode TreeNode;


int sumHelper(TreeNode* root, int L, int R) {
	if (!root)
		return 0;

	int sum = 0;
	if (root->val >= L && root->val <= R)
		sum += root->val;

	if (root->left && root->val > L)
		sum += sumHelper(root->left, L, R);
	if (root->right && root->val < R)
		sum += sumHelper(root->right, L, R);

	return sum;
}


int rangeSumBST(struct TreeNode* root, int L, int R) {
	return sumHelper(root, L, R);
}
//
//void main() {
//	TreeNode n6 = {18, NULL, NULL};
//	TreeNode n5 = {7, NULL, NULL};
//	TreeNode n4 = {3, NULL, NULL};
//	TreeNode n3 = {15, NULL, &n6};
//	TreeNode n2 = {5, &n4, &n5};
//	TreeNode n1 = {10, &n2, &n3};
//
//	int res = rangeSumBST(&n1, 7, 15);
//}