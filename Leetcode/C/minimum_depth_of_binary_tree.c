#include "Header.h"


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode TreeNode;


static inline int mini(int l, int r) { return (l < r) ? l+1 : r+1; }

int minDepth(struct TreeNode* root) {
    if (!root)
        return 0;
    
    if (!root->right && !root->left) return 1;

    int valL, valR;
    valL = valR = 9999;

    if (root->left)
        valL = minDepth(root->left);
    if (root->right)
        valR = minDepth(root->right);

    return mini(valR, valL);


}

//
//void main() {
//
//    TreeNode a5 = { 7, NULL, NULL };
//    TreeNode a4 = { 15, NULL, NULL };
//    TreeNode a3 = { 20, &a4, &a5 };
//    TreeNode a2 = { 9, NULL, NULL };
//    TreeNode a1 = { 3, &a2, &a3 };
//
//    int m = minDepth(&a1);
//}





