#include "Header.h"


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

void maxHelper(TreeNode* root, int *lMin, int *lMax, int *maxEcart) {

	int min = INT_MAX, max = INT_MIN;
	int minR = INT_MAX, maxR = INT_MIN;
	int ecart;

	if (root->left) {
		maxHelper(root->left, &min, &max, maxEcart);

		if ((ecart = abs(min - root->val)) > *maxEcart) {
			*maxEcart = ecart;
		}
		if ((ecart = abs(max - root->val)) > *maxEcart) {
			*maxEcart = ecart;
		}
	} 

	if (root->right) {
		maxHelper(root->right, &minR, &maxR, maxEcart);

		if ((ecart = abs(minR - root->val)) > *maxEcart) {
			*maxEcart = ecart;
		}
		if ((ecart = abs(maxR - root->val)) > *maxEcart) {
			*maxEcart = ecart;
		}
	}

	if (root->val > maxR && root->val > max)
		*lMax = root->val;
	else
		*lMax = (maxR > max) ? maxR : max;


	if (root->val < minR && root->val < min)
		*lMin = root->val;
	else
		*lMin = (minR < min) ? minR : min;


}

int maxAncestorDiff(struct TreeNode* root) {

	int maxEcart = 0, l = 0, r  =0;
	maxHelper(root, &l, &r, &maxEcart);
	return maxEcart;
}



//void main() {
//
//
//	//   TreeNode a5 = { 7, NULL, NULL };
//	//   //TreeNode a4 = { 15, NULL, NULL };
//	//   TreeNode a3 = { 9, NULL, &a5 };
//
//	   //TreeNode l1 = { 3, NULL, NULL };
//	   //TreeNode l2 = { 5, NULL, NULL };
//	//   TreeNode a2 = { 2, &l1, &l2 };
//
//	//   TreeNode a1 = { 3, &a2, &a3 };
//
//	TreeNode b4 = { 3, NULL, NULL };
//	TreeNode b3 = {0, &b4, NULL};
//	TreeNode b2 = { 2, NULL, &b3 };
//	TreeNode b1 = { 1, NULL, &b2 };
//
//    int m = maxAncestorDiff(&b1);
//
//}