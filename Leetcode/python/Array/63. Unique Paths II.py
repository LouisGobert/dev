from os import path
from typing import List


class Solution:
    obstacle_grid: List[List[int]]

    def explore(self, path_count: List[List[int]], x, y) -> int:
        # Explore starting a x and y and return the number of path for current x, y
        len_x = len(path_count[0])
        len_y = len(path_count)

        count = 0
        if x + 1 != len_x and self.obstacle_grid[y][x + 1] != 1:
            if path_count[y][x + 1] == -1:
                path_count[y][x + 1] = self.explore(path_count, x + 1, y)
            count += path_count[y][x + 1]
        if y + 1 != len_y and self.obstacle_grid[y + 1][x] != 1:
            if path_count[y + 1][x] == -1:
                path_count[y + 1][x] = self.explore(path_count, x, y + 1)
            count += path_count[y + 1][x]

        path_count[y][x] = count
        return count

    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        len_x = len(obstacleGrid[0])
        len_y = len(obstacleGrid)
        if len_x == len_y == 1 or obstacleGrid[0][0] == 1:
            return 1 if obstacleGrid[0][0] == 0 else 0
        self.obstacle_grid = obstacleGrid
        path_count = [[-1] * len_x for i in range(len_y)]

        path_count[-1][-1] = 1
        count = self.explore(path_count, 0, 0)
        return path_count[0][0]


if __name__ == "__main__":
    s = Solution()
    assert s.uniquePathsWithObstacles([[0, 0, 0], [0, 1, 0], [0, 0, 0]]) == 2
    assert s.uniquePathsWithObstacles([[0, 1], [0, 0]]) == 1
    assert s.uniquePathsWithObstacles([[0]]) == 1
    assert s.uniquePathsWithObstacles([[1, 0]]) == 0
