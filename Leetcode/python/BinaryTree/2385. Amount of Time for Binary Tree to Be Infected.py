# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import Optional, Set

from TreeNode import TreeNode


class Solution:
    node_count: int
    infected_node: Set[int]
    new_ly_infected: Set[int]

    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        self.infected_node = set([start])
        time_count = 0
        self.node_count = 0
        self.count_node(root)

        while len(self.infected_node) != self.node_count:
            self.new_ly_infected = set()
            self.infect(root)
            time_count += 1
            print(f"Infected a t {time_count}: {len(self.infected_node)}")
            self.infected_node.update(self.new_ly_infected)
        return time_count

    def count_node(self, node: Optional[TreeNode]):
        if node is not None:
            self.node_count += 1
            self.count_node(node.left)
            self.count_node(node.right)

    def infect(self, node: Optional[TreeNode]) -> bool:
        if node is not None:
            if node.val in self.infected_node:
                if node.right is not None:
                    self.new_ly_infected.add(node.right.val)
                if node.left is not None:
                    self.new_ly_infected.add(node.left.val)
            if node.right is not None and node.right.val in self.infected_node:
                self.new_ly_infected.add(node.val)
            if node.left is not None and node.left.val in self.infected_node:
                self.new_ly_infected.add(node.val)

            if self.infect(node.left) and node.val in self.infected_node:
                node.left = None
            if self.infect(node.right) and node.val in self.infected_node:
                node.right = None

            if (
                node.right is None
                and node.left is None
                and (node.val in self.new_ly_infected or node.val in self.infected_node)
            ):
                return True
            return False

        return True


if __name__ == "__main__":
    l = TreeNode(2)
    r = TreeNode(3)
    root = TreeNode(1, l, r)

    s = Solution()
    assert s.amountOfTime(root, 1) == 1

    two = TreeNode(2)
    nine = TreeNode(9)
    four = TreeNode(4, nine, two)
    five = TreeNode(5, None, four)

    ten = TreeNode(10)
    six = TreeNode(6)
    three = TreeNode(3, ten, six)
    one = TreeNode(1, five, three)
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
