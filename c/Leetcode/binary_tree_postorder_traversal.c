#include "Header.h"




//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode TreeNode;


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* postorderTraversal(TreeNode* curr, int* returnSize) {
    if (!curr) {
        *returnSize = 0;
        return NULL;
    }
    


    int* nodeValue = (int*)malloc(sizeof(int) * 100);
    TreeNode** stack = (TreeNode**)malloc(sizeof(TreeNode*) * 100);
    int posNodeValue = 0, stackPos = 0;
    bool up = false;

    if (!curr->right && !curr->left)
    {
        *returnSize = 1;
        nodeValue[0] = curr->val;
        return nodeValue;
    }

    while (stackPos >= 0)
    {
        while (curr) {
            stack[stackPos++] = curr;
            curr = curr->left;
        }
        
        // Pour reprendre le dernier node valide
        curr = stack[--stackPos];
        if (!curr->right) {
            nodeValue[posNodeValue++] = curr->val;
            printf("%d\n", curr->val);  
            

            // On remonte
            if (stack[stackPos - 1]->right && stack[stackPos - 1]->right != curr) {
                curr = stack[stackPos-1]->right;
                stack[stackPos] = curr;
            }
            else {
                stackPos--;
                while (stackPos >= 0 && (stack[stackPos]->right == curr || !stack[stackPos]->right))
                {
                    curr = stack[stackPos];
                    nodeValue[posNodeValue++] = curr->val;
                    printf("%d\n", curr->val);
                    stackPos--;
                }
                if (stackPos != -1) {
                    curr = stack[stackPos++]->right;
                    stack[stackPos] = curr;
          
                }
            }
        }
        else {
            curr = curr->right;
            stack[++stackPos] = curr;
        }
    }
    *returnSize = posNodeValue;
    return nodeValue;
}






