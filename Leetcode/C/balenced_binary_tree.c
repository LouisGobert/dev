#include "Header.h"

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode TreeNode;


int maxDepthh(TreeNode* root) {

    if (!root)
        return 0;

    int valL = maxDepthh(root->left);
    int valR = maxDepthh(root->right);
    if (valL == INT_MIN || valR == INT_MIN)
        return INT_MIN;
    if (abs(valL-valR) > 1)
        return INT_MIN;

    return 1 + ((valL > valR) ? valL : valR);

}


bool isBalanced(struct TreeNode* root) {
    return maxDepthh(root) != INT_MIN;
}
//
//void main() {
//
//   
//	TreeNode n5 = {7, NULL, NULL};
//	TreeNode n4 = {15, NULL, NULL};
//	TreeNode n3 = {20, &n4, &n5};
//	TreeNode n2 = {9, NULL, NULL};
//	TreeNode n1 = {3, &n2, &n3};
//
//	int res = isBalanced(&n1);
//}