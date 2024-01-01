"""
The product difference between two pairs (a, b) and (c, d) is defined as (a * b) - (c * d).

For example, the product difference between (5, 6) and (2, 7) is (5 * 6) - (2 * 7) = 16.
Given an integer array nums, choose four distinct indices w, x, y, and z such that the product difference between pairs (nums[w], nums[x]) and (nums[y], nums[z]) is maximized.

Return the maximum such product difference.

 

Example 1:

Input: nums = [5,6,2,7,4]
Output: 34
Explanation: We can choose indices 1 and 3 for the first pair (6, 7) and indices 2 and 4 for the second pair (2, 4).
The product difference is (6 * 7) - (2 * 4) = 34.
Example 2:

Input: nums = [4,2,5,9,7,4,8]
Output: 64
Explanation: We can choose indices 3 and 6 for the first pair (9, 8) and indices 1 and 5 for the second pair (2, 4).
The product difference is (9 * 8) - (2 * 4) = 64.
"""
from typing import List


class Solution:
    def compute_difference(self, w, x, y, z) -> int:
        return (w * x) - (y * z)

    # def maxProductDifference(self, nums: List[int]) -> int:
    #     maxs = [-1]
    #     mins = [(10**4)+1]
    #     for number in nums:
    #         cur_min = mins[0]
    #         if number < cur_min:
    #             mins.pop()
    #             mins.append(number)
    #         if number > maxs[0]:
    #             maxs.pop()

    # return self.compute_difference(max_one, max_two, min_one, min_two)
    def maxProductDifference(self, nums: List[int]) -> int:
        max_one = max_two = -1
        min_one = min_two = (10**4) + 1
        for number in nums:
            if number > max_one or number > max_two:
                max_one = max(max_one, max_two)
                max_two = number
            if number < min_one or number < min_two:
                min_one = min(min_one, min_two)
                min_two = number
        return self.compute_difference(max_one, max_two, min_one, min_two)


if __name__ == "__main__":
    s = Solution()

    r = s.maxProductDifference([5, 6, 2, 7, 4])
    assert r == 34

    assert s.maxProductDifference([4, 2, 5, 9, 7, 4, 8]) == 64
