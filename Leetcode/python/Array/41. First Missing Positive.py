"""
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
"""

SEEN = 2**32

from typing import List


class Solution:
    nums: List[int]
    lenght: int

    # def swap(self, start_index: int, index: int, clean: bool = False):
    #     if index >= self.lenght or index < 0:
    #         return False

    #     next_index = self.nums[index] - 1
    #     if clean:
    #         self.nums[start_index] = 0
    #     self.nums[index] = 1
    #     if index > next_index:
    #         return self.swap(index, next_index)
    def swap(self, num: int):
        if num > self.lenght or num <= 0:
            return
        if self.nums[num - 1] == SEEN:
            return

        next_num = self.nums[num - 1]
        self.nums[num - 1] = SEEN
        return self.swap(next_num)

    def firstMissingPositive(self, nums: List[int]) -> int:
        self.nums = nums
        self.lenght = len(nums)
        for index, num in enumerate(nums):
            if num == SEEN:
                continue
            self.swap(num)

        for index, v in enumerate(self.nums):
            if v != SEEN:
                return index + 1
        return self.lenght + 1


if __name__ == "__main__":
    s = Solution()
    """
    1  0  0  0 : next > 2
    1  1  0  0 : next > 3
    1  1  0  0 : next > 3
    1  1  0  1 : next > 4
    1  1  
    
    """

    """
    
    1 1 4 3 
    1 1 0 1 with 3 copied
    1 1 1 1
    """
    assert s.firstMissingPositive([2, 1]) == 3

    """
    0 1 4 2
    1 0 4 2
    1 1 0 4    
    """
    # assert s.firstMissingPositive([5, 1, 4, 2]) == 3

    assert s.firstMissingPositive([1, 2, 4, 3]) == 5
    assert s.firstMissingPositive([1, 1]) == 2
    assert s.firstMissingPositive([1, 2, 0]) == 3
    assert s.firstMissingPositive([1, 2, 4]) == 3
    assert s.firstMissingPositive([3, 4, -1, 1]) == 2
    """
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    0 0 0 0 0
    """
    assert s.firstMissingPositive([7, 8, 9, 11, 12]) == 1
