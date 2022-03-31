# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional
from BinaryTree.TreeNode import *


class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:

        if root1 and root2:
            root1.val += root2.val
            self.merge(root1, root2)

        if root1:
            return root1
        return root2

    def merge(self, root1: Optional[TreeNode], root2: Optional[TreeNode]):

        if root1.left and root2.left:
            root1.left.val += root2.left.val
            self.merge(root1.left, root2.left)

        elif root2.left:
            # pas de left au root1
            root1.left = root2.left

        if root1.right and root2.right:
            root1.right.val += root2.right.val
            self.merge(root1.right, root2.right)
        elif root2.right:
            root1.right = root2.right
