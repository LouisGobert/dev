#include "Header.h"

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode TreeNode;


/// 
///			
/// 
///				MANIERE ITERATIVE
/// 
/// 
/// 

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {

	if (!root) {
		TreeNode* newRoot = malloc(sizeof(TreeNode));
		newRoot->left = NULL;
		newRoot->right = NULL;
		newRoot->val = val;
		return newRoot;
	}
	TreeNode* HeadTemp = root;

	while (root->left || root->right)
	{
		if (val > root->val) {
			if (!root->right) {
				root->right = malloc(sizeof(TreeNode));
				root->right->right = NULL;
				root->right->left = NULL;
				root->right->val = val;
				return HeadTemp;
			}
			root = root->right;
		}
		else {
			if (!root->left) {
				root->left = malloc(sizeof(TreeNode));
				root->left->right = NULL;
				root->left->left = NULL;
				root->left->val =  val;
				return HeadTemp;
			}
			root = root->left;
		}
	}

	if (val > root->val) {
		root->right = malloc(sizeof(TreeNode));
		root->right->right = NULL;
		root->right->left = NULL;
		root->right->val = val;
		return HeadTemp;
	}
	else {
		root->left = malloc(sizeof(TreeNode));
		root->left->right = NULL;
		root->left->left = NULL;
		root->left->val = val;
		return HeadTemp;
	}


	return HeadTemp;
}



/// 
///			
/// 
///				MANIERE RECURSIVE
/// 
/// 
/// 

TreeNode* createNode(int val) {
	TreeNode* newNode = malloc(sizeof(TreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->val = val;
	return newNode;
}



struct TreeNode* insertIntoBSTRec(struct TreeNode* root, int val) {

	TreeNode* HeadTemp = root;

	if (!root)
		return createNode(val);

	if (val > root->val) {
		if (root->right)
			insertIntoBSTRec(root->right, val);
		else
			root->right = createNode(val);
	}
	else {
		if (root->left)
			insertIntoBSTRec(root->left, val);
		else {
			root->left = createNode(val);
		}
	}

	return HeadTemp;
	
}


//void main() {
//	TreeNode a6 = { 99, NULL, NULL };
//	TreeNode a5 = { 7, NULL, &a6 };
//	//TreeNode a4 = { 15, NULL, NULL };
//	TreeNode a3 = { 3, NULL, &a5 };
//
//	TreeNode l1 = { 1, NULL, NULL };
//	TreeNode l2 = { 7, NULL, NULL };
//	TreeNode a2 = { 2, &l1, &a3 };
//
//	TreeNode a1 = { 4, &a2, &l2 };
//
//	TreeNode* res = searchBST(&a1, 2);
//
//}