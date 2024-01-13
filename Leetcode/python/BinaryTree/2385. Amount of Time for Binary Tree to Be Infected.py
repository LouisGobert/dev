# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional, Set

from TreeNode import TreeNode


class Solution:
    start: int
    start_node: Optional[TreeNode]
    explored_node: Set[int]

    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        self.start = start
        self.explored_node = set()
        if root is None:
            return 0

        if root.val == start:
            ...

        self.make_undirected(root, None)
        start_node = self.found_start_node(root)
        assert start_node is not None
        print(f"Start node found: {start_node.val}")

        max_deep = self.count_deep(start_node)
        return max_deep

    def count_deep(self, node: Optional[TreeNode]) -> int:
        if node is None:
            return 0

        self.explored_node.add(node.val)
        node.explored = True
        maxx = 0
        if node.right is not None and not node.right.val in self.explored_node:
            maxx = max(self.count_deep(node.right) + 1, maxx)
        if node.left is not None and not node.left.val in self.explored_node:
            maxx = max(self.count_deep(node.left) + 1, maxx)
        if node.parent is not None and not node.parent.val in self.explored_node:
            maxx = max(self.count_deep(node.parent) + 1, maxx)

        return maxx

    def found_start_node(self, node: Optional[TreeNode]) -> Optional[TreeNode]:
        if node is None:
            return None

        if node.val == self.start:
            return node

        n = self.found_start_node(node.left)
        if n is not None:
            return n
        n = self.found_start_node(node.right)
        if n is not None:
            return n

    def make_undirected(self, node: Optional[TreeNode], parent: Optional[TreeNode]) -> None:
        if node is not None:
            node.parent = parent

            self.make_undirected(node.right, node)
            self.make_undirected(node.left, node)


if __name__ == "__main__":
    s = Solution()

    two = TreeNode(2)
    nine = TreeNode(9)
    four = TreeNode(4, nine, two)
    five = TreeNode(5, None, four)

    ten = TreeNode(10)
    six = TreeNode(6)
    three = TreeNode(3, ten, six)
    one = TreeNode(1, five, three)
    #          1
    #     5          3
    #   -   4     10    6
    #     9   2
    assert s.amountOfTime(one, 3) == 4

    # [       1,
    #       2, null,
    #     3, null,
    #   4 ,null,
    # 5 ]
    five = TreeNode(5)
    four = TreeNode(4, five)
    three = TreeNode(3, four)

    two = TreeNode(2, three)
    one = TreeNode(1, two)

    assert s.amountOfTime(one, 4) == 3

    l = TreeNode(2)
    r = TreeNode(3)
    root = TreeNode(1, l, r)

    assert s.amountOfTime(root, 1) == 1
