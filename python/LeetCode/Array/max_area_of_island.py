from typing import List

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:

        max_area = 0

        for y, array in enumerate(grid):

            for x, elt in enumerate(array):

                if elt:
                    max_area = max(max_area, self.explore(y, x, grid, 0))

        return  max_area


    def explore(self, y, x, grid, area) -> int:

        grid[y][x] = 0
        area += 1

        if y != 0 and grid[y-1][x]:
            area = self.explore(y-1, x, grid, area)
        if y != len(grid)-1 and grid[y+1][x]:
            area = self.explore(y+1, x, grid, area)

        if x != 0 and grid[y][x-1]:
            area = self.explore(y, x-1, grid, area)
        if x != len(grid[0])-1 and grid[y][x+1]:
            area = self.explore(y, x+1, grid, area)


        return area

