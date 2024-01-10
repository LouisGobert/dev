# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional

from Leetcode.python.BinaryTree.TreeNode import TreeNode


class Solution:
    leaf: list[int]

    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        self.leaf = []
        self.traversePreOrder(root1)
        leaf_one = self.leaf
        self.leaf = []
        self.traversePreOrder(root2)
        return leaf_one == self.leaf

    def traversePreOrder(self, node: TreeNode) -> None:
        if node.left is None and node.right is None:
            self.leaf.append(node.val)
            return
        if node.left:
            self.traversePreOrder(node.left)
        if node.right:
            self.traversePreOrder(node.right)


if __name__ == "__main__":
    s = Solution()
