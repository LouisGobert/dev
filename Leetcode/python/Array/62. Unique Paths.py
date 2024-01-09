from os import path
from typing import List


class Solution:
    def explore(self, path_count: List[List[int]], x, y) -> int:
        # Explore starting a x and y and return the number of path for current x, y
        len_x = len(path_count[0])
        len_y = len(path_count)

        count = 0
        if x + 1 != len_x:
            if path_count[y][x + 1] == -1:
                path_count[y][x + 1] = self.explore(path_count, x + 1, y)
            count += path_count[y][x + 1]
        if y + 1 != len_y:
            if path_count[y + 1][x] == -1:
                path_count[y + 1][x] = self.explore(path_count, x, y + 1)
            count += path_count[y + 1][x]

        return count

    def uniquePaths(self, m: int, n: int) -> int:
        if m == 1 == n:
            return 1
        path_count = [[-1] * n for i in range(m)]
        print(path_count)

        path_count[-1][-1] = 1
        count = self.explore(path_count, 0, 0)
        return count


if __name__ == "__main__":
    s = Solution()
    assert s.uniquePaths(3, 7) == 28
    assert s.uniquePaths(3, 2) == 3
    assert s.uniquePaths(1, 1) == 1
