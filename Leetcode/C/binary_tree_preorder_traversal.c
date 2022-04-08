#include "Header.h"




//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode TreeNode;

bool inExplored(TreeNode* node, TreeNode** explored, int n);

 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
/*int* preorderTraversal(TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int* nodeValue = (int*)malloc(sizeof(int) * 100);
    TreeNode** stack = (TreeNode**)malloc(sizeof(TreeNode*) * 100);
    TreeNode *node = root;
    TreeNode** explored = (TreeNode**)malloc(sizeof(TreeNode*) * 100);
    int pos = 0, stackPos = 0, exploredPos = 0;

    // On ajoute le noeud de basse (root)
    nodeValue[0] = root->val;
    stack[pos] = root;
    
    pos++;
    do
    {
        // Si il y a un enfant à gauche
        // Si non
        //  -> on regarde si il y à un enfant à droite
        // Si non
        // On boucle pour remonter 
        if (stack[stackPos]->left && !inExplored(stack[stackPos]->left, explored, exploredPos)) {
            node = node->left;

            // Ajout de la valeur à la liste
            nodeValue[pos] = node->val;
            pos++;

            // Ajout du nood dans le liste des
            stackPos++;
            stack[stackPos] = node;
        }
        else if (stack[stackPos]->right && !inExplored(stack[stackPos]->right, explored, exploredPos)) {
            node = node->right;

            nodeValue[pos] = node->val;
            pos++;

            stackPos++;
            stack[stackPos] = node;
        }
        else {
            // SI pas d'enfant à droite ni a gauche, le node est considéré comme epxloré
            explored[exploredPos] = node;
            exploredPos++;

            // On remonte de 1 dans l'arbre
            stackPos--;
            if (stackPos != -1)
                node = stack[stackPos];            
        }

        
    } while (stackPos != -1);

    *returnSize = pos;
    return nodeValue;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(TreeNode* curr, int* returnSize) {
    if (!curr) {
        *returnSize = 0;
        return NULL;
    }

    int* nodeValue = (int*)malloc(sizeof(int) * 100);
    TreeNode** stack = (TreeNode**)malloc(sizeof(TreeNode*) * 100);
    int posNodeValue = 0, stackPos = 0;


    while (curr || stackPos != 0)
    {
       
        while (curr) {
            nodeValue[posNodeValue++] = curr->val;
            stack[stackPos++] = curr;
            curr = curr->left;
        }

        curr = stack[--stackPos];
        
        curr = curr->right;
    }



    *returnSize = posNodeValue;
    return nodeValue;
}


/// <summary>
/// Return True if node is in visexploredited.
/// n = pos de fin de explored
/// </summary>
bool inExplored(TreeNode* node, TreeNode** explored, int n) {

    // Explored est linéaire (pas un arbre)
    for (int i = 0; i < n; i++) 
        if (node == explored[i])
            return true;

    return false;
    
}




