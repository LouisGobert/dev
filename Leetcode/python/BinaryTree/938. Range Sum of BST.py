# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    left: Optional["TreeNode"]
    right: Optional["TreeNode"]
    val: int

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        node_values = []
        self.traverse(node_values, root)
        sums = 0
        for val in node_values:
            if val >= low and val <= high:
                sums += val
        return sums

    def traverse(self, node_list: list[int], node: Optional[TreeNode]):
        if node is not None:
            node_list.append(node.val)
            self.traverse(node_list, node.left)
            self.traverse(node_list, node.right)
