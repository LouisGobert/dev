"""Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

 

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 105"""
import math
from typing import List


class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        min_lenght = math.ceil(len(arr) * 0.25000000001)
        i = 0
        if min_lenght == 1:
            return arr[0]
        while i < len(arr):
            if arr[i] == arr[min(i + min_lenght - 1, len(arr) - 1)]:
                return arr[i]
            i += 1

        raise ValueError


if __name__ == "__main__":
    s = Solution()

    r = s.findSpecialInteger([1, 2, 2, 6, 6, 6, 6, 7, 10])
    assert r == 6

    assert s.findSpecialInteger([1, 1]) == 1

    assert s.findSpecialInteger([1]) == 1

    assert s.findSpecialInteger([1, 2, 3, 3]) == 3
    assert s.findSpecialInteger([1, 1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 12, 12]) == 1
