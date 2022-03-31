from typing import List

class Solution:
    def orangesRotting(self, mat: List[List[int]]) -> int:
        """
        minute = -1
        fresh_seen = False

        min_minute = [[None for _ in range(len(grid[0]))] for i in range(len(grid))]
        """
        nearest = [[None for _ in range(len(mat[0]))] for i in range(len(mat))]
        # 0 populating
        queue = []
        for y, array in enumerate(mat):
            for x, elt, in enumerate(array):
                if  mat[y][x] == 2:
                    # si pomme pourie
                    nearest[y][x] = 0
                    queue.append([y, x])
                elif mat[y][x] == 1:
                    nearest[y][x] = None


        while queue:
            point = queue.pop(0)
            self.explore(point[0], point[1], nearest, queue, mat)

        max_time = 0
        for y, array in enumerate(nearest):
            for x, elt in enumerate(array):

                if mat[y][x] == 1 and nearest[y][x] is None:
                    return -1
                if elt:
                    max_time = max(max_time, elt)


        return max_time

    def explore(self, y, x, nearest, queue, grid):

        cur_val = 1 if (nearest[y][x] is None) else nearest[y][x] + 1

        if y != 0 and (grid[y-1][x] == 1 and nearest[y - 1][x] is None):
            nearest[y - 1][x] = cur_val
            queue.append([y - 1, x])

        if x != 0 and (grid[y][x - 1] == 1 and nearest[y][x - 1] is None):
            nearest[y][x - 1] = cur_val

            queue.append([y, x - 1])

        if y != len(nearest) - 1 and (grid[y + 1][x] == 1 and nearest[y + 1][x] is None):
            nearest[y + 1][x] = cur_val
            queue.append([y + 1, x])

        if x != len(nearest[0]) - 1 and (grid[y][x + 1] == 1 and nearest[y][x + 1] is None):
            nearest[y][x + 1] = cur_val
            queue.append([y, x + 1])
            