from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        self.parent: Optional["TreeNode"] = None
        self.explored = False

    def print(self):
        queue = [self]

        # TODO

    @staticmethod
    def getTree(num: int):
        t1 = None

        if num == 0:
            t1 = None
        elif num == 1:
            t3 = TreeNode(3, None, None)
            t2 = TreeNode(2, t3, None)
            t1 = TreeNode(1, None, t2)
            """
                1
                 \
                  2
                 /
                3  
            """

        elif num == 2:
            t3 = TreeNode(3, None, None)
            t2 = TreeNode(2, None, None)
            t1 = TreeNode(1, t2, t3)
            """
                1
               / \
              2   3 
            """

        elif num == 3:
            t4 = TreeNode(5, None, None)
            t3 = TreeNode(2, None, None)
            t2 = TreeNode(3, t4, None)
            t1 = TreeNode(1, t2, t3)
            """
                1
              /   \
             3     2
            /
           5        
            """
        elif num == 4:
            t5 = TreeNode(7, None, None)
            t4 = TreeNode(4, None, None)
            t3 = TreeNode(3, None, t5)
            t2 = TreeNode(1, None, t4)
            t1 = TreeNode(2, t2, t3)
            """
                2
              /   \
             1     3
              \     \
               4     7        
            """

        return t1
