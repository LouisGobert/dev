from typing import List

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:


        nearest = [[None for _ in range(len(mat[0]))] for i in range(len(mat))]
        # 0 populating
        queue = []
        for y, array in enumerate(mat):
            for x, elt, in enumerate(array):
                if not mat[y][x]:
                    nearest[y][x] = 0
                    queue.append([y, x])
                else:
                    nearest[y][x] = 10000000000



        while queue:
            point = queue.pop(0)
            self.explore(point[0], point[1], nearest, queue)


        return nearest

    def explore(self, y, x, nearest, queue):

        cur_val = 1 if (nearest[y][x] is None) else nearest[y][x] + 1

        if y != 0 and (nearest[y-1][x] is None or nearest[y-1][x] > cur_val):
            nearest[y-1][x] = cur_val
            queue.append([y-1,x])

        if x != 0 and (nearest[y][x-1] is None or nearest[y][x-1] > cur_val):
            nearest[y][x-1] = cur_val

            queue.append([y, x-1])


        if y != len(nearest) - 1 and (nearest[y+1][x] is None or nearest[y+1][x] > cur_val):
            nearest[y+1][x] = cur_val
            queue.append([y + 1, x])


        if x != len(nearest[0]) - 1 and (nearest[y][x+1] is None or nearest[y][x+1] > cur_val):
            nearest[y][x+1] = cur_val
            queue.append([y, x+1])
