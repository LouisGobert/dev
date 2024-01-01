"""1464. Maximum Product of Two Elements in an Array
Easy
2.4K
229
Companies
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
 

Example 1:

Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 
Example 2:

Input: nums = [1,5,4,5]
Output: 16
Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
Example 3:

Input: nums = [3,7]
Output: 12
"""


from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        max_one = -1
        max_two = -1
        for number in nums:
            if number >= max_one:
                max_two = max_one
                max_one = number
            else:
                max_two = max(max_two, number)

        return (max_one - 1) * (max_two - 1)


if __name__ == "__main__":
    s = Solution()

    assert s.maxProduct([3, 4, 5, 2]) == 12
    assert s.maxProduct([10, 2, 5, 2]) == 36
