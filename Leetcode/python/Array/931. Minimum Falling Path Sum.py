from typing import List

MIN_ABS = -200
MAX_ABS = 200


def build_mins(matrix: List[List[int]]) -> None:
    for row in range(len(matrix) - 2, -1, -1):
        for col in range(len(matrix[0])):
            vals = [matrix[row + 1][col]]
            if col != 0:
                vals.append(matrix[row + 1][col - 1])
            if col + 1 != len(matrix[0]):
                vals.append(matrix[row + 1][col + 1])

            matrix[row][col] += min(vals)


class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        build_mins(matrix)

        return min(matrix[0])


if __name__ == "__main__":
    s = Solution()
    assert s.minFallingPathSum([[2, 1, 3], [6, 5, 4], [7, 8, 9]]) == 13
