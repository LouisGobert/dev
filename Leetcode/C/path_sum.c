#include "Header.h"


//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode TreeNode;


bool hasPathSum(TreeNode* root, int sum) {

    if (!root)
        return false;

    if (!root->left && !root->right) {
        if (sum-root->val == 0)
            return true;
        return false;
    }

    sum -= root->val;
    return (hasPathSum(root->left, sum)) || (hasPathSum(root->right, sum));
    return false;
}


