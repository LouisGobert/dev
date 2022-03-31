#include "Header.h"


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode TreeNode;
 
int helper(TreeNode* root, int *tiltSum) {

	int leftSum = 0, rightSum = 0;

	if (root->left) {
		leftSum = helper(root->left, tiltSum);
	}
	if (root->right) {
		rightSum = helper(root->right, tiltSum);
	}

	*tiltSum += abs(leftSum - rightSum);
	return (leftSum + rightSum + root->val);

}

int findTilt(struct TreeNode* root) {
	if (!root)
		return 0;

	int tiltSum = 0;
	helper(root, &tiltSum);
	return tiltSum;
}



//void main() {
//	
//
//
//    TreeNode a5 = { 7, NULL, NULL };
//    //TreeNode a4 = { 15, NULL, NULL };
//    TreeNode a3 = { 9, NULL, &a5 };
//
//	TreeNode l1 = { 3, NULL, NULL };
//	TreeNode l2 = { 5, NULL, NULL };
//    TreeNode a2 = { 2, &l1, &l2 };
//
//    TreeNode a1 = { 3, &a2, &a3 };
//
//    int m = findTilt(&a1);
//
//
//}