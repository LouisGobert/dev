from functools import reduce
from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        lenght = len(nums)
        res = [nums[0]]
        for i in range(1, lenght):
            res.append(nums[i] * res[-1])

        for i in range(lenght - 2, -1, -1):
            nums[i] *= nums[i + 1]

        left = 1
        for i in range(lenght):
            # left = 1 if i == 0 else res[i]
            right = 1 if i + 1 == lenght else nums[i + 1]
            t = res[i]
            res[i] = left * right
            left = t
        return res


if __name__ == "__main__":
    s = Solution()
    assert s.productExceptSelf([2, 3, 5, 0]) == [0, 0, 0, 30]
    """
    2 6  30  0
    0  0  0   0 
    
    """

    assert s.productExceptSelf([1, 2, 3, 4]) == [24, 12, 8, 6]
    """
        [
            1   2  6 12
        ]
        [ 
            24 24 12  4
        ]
        - 24
        - 12
        - 8
        - 6
    """
    assert s.productExceptSelf([-1, 1, 0, -3, 3]) == [0, 0, 9, 0, 0]
