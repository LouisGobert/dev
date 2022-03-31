from typing import List, Optional

from BinaryTree.TreeNode import TreeNode


class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:


        stack = []
        node_list = []

        if root:
            stack = [root.right]
        while stack:
            node_list.append(root.val)

            if root.left:
                if root.right :
                    stack.append(root.right)
                root = root.left
            elif root.right:
                root = root.right
            else:
                root = stack.pop()

        return node_list
