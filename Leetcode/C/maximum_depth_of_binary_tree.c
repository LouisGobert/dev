#include "Header.h"


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode TreeNode;


int maxDepth(TreeNode* root) {

    if (!root)
        return 0;

    int valL = maxDepth(root->left);
    int valR = maxDepth(root->right);

    return 1 + ((valL > valR) ? valL : valR);

}





