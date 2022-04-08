from typing import List, Optional


# Definition for a binary tree nod

class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        node_list = []
        self.traverse(node_list, root)
        return node_list

    def traverse(self, node_list, node: Optional[TreeNode]):
        if node:
            node_list.append(node.val)
            self.traverse(node_list, node.left)
            self.traverse(node_list, node.right)

        return
