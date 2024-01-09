from typing import List

FLAG = 2
OBSTACLE = -1
START = 1
EMPTY = 0

Grid = List[List[int]]


def count_empty(grid: Grid) -> int:
    count = 0
    for x in range(len(grid[0])):
        for y in range(len(grid)):
            if grid[y][x] == EMPTY:
                count += 1
    return count


class Solution:
    total_empty_cell: int
    path_discovered: int
    len_x: int
    len_y: int

    def explore(self, grid: Grid, x: int, y: int, discovered: int) -> None:
        if grid[y][x] == FLAG:
            if discovered == self.total_empty_cell + 1:
                self.path_discovered += 1
            return
        if grid[y][x] == OBSTACLE:
            return

        # Discover other 4 directions
        grid[y][x] = OBSTACLE
        if x + 1 != self.len_x:
            self.explore(grid, x + 1, y, discovered + 1)
        if x - 1 >= 0:
            self.explore(grid, x - 1, y, discovered + 1)
        if y + 1 != self.len_y:
            self.explore(grid, x, y + 1, discovered + 1)
        if y - 1 >= 0:
            self.explore(grid, x, y - 1, discovered + 1)

        grid[y][x] = EMPTY

    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        self.total_empty_cell = count_empty(grid)
        self.path_discovered = 0
        self.len_x = len(grid[0])
        self.len_y = len(grid)

        # Try to found start point
        for x in range(len(grid[0])):
            for y in range(len(grid)):
                if grid[y][x] == START:
                    self.explore(grid, x, y, 0)
                    return self.path_discovered


if __name__ == "__main__":
    s = Solution()
    assert s.uniquePathsIII([[1, 0, 0, 0], [0, 0, 0, 0], [0, 0, 2, -1]]) == 2
