#include "Header.h"




//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
typedef struct TreeNode TreeNode;

struct ListNode {
    TreeNode* tree;
    struct ListNode* next;
};
typedef struct ListNode ListNode;

void addNode(ListNode* head, TreeNode *node) {
    head->next = malloc(sizeof(ListNode));
    head = head->next;
    head->next = NULL;
    head->tree = node;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(TreeNode* curr, int* returnSize) {
    if (!curr) {
        *returnSize = 0;
        return NULL;
    }

    int* nodeValue   =  (int*)malloc(sizeof(int) * 100);
    TreeNode** stack =  (TreeNode**)malloc(sizeof(TreeNode*) * 100);
    int posNodeValue = 0, stackPos = 0;


    while (curr || stackPos != 0)
    {
        while (curr) {
            stack[stackPos++] = curr;
            curr = curr->left;
        }

        curr = stack[--stackPos];
        nodeValue[posNodeValue++] = curr->val;
        curr = curr->right;
    }

    

    *returnSize = posNodeValue;
    return nodeValue;
}




