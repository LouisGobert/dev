from distutils.util import subst_vars
from typing import List


class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        r = []
        for col_index in range(len(matrix[0])):
            sub_r = []
            for row_index in range(len(matrix)):
                sub_r.append(matrix[row_index][col_index])

            r.append(sub_r)

        return r


if __name__ == "__main__":
    s = Solution()

    r = s.transpose([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    assert r == [[1, 4, 7], [2, 5, 8], [3, 6, 9]]

    assert s.transpose([[1, 2, 3], [4, 5, 6]]) == [[1, 4], [2, 5], [3, 6]]
    assert s.transpose([[1]]) == [[1]]

    """
    [1, 2, 3], 
    [4, 5, 6]
    
    [1, 4], 
    [2, 5], 
    [3, 6]]
    """
