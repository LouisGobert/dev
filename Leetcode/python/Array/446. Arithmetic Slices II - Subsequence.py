import array
from itertools import combinations
from typing import List, Tuple

from numpy import append
from rich.pretty import pretty_repr


def is_sequence(array: List[int]) -> bool:
    last_number = array[0]
    diff = array[1] - array[0]
    for number in array[1:]:
        if last_number + diff != number:
            return False

        last_number = number
    return True


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return 0
        count = 0

        generated: List[List[int]] = []
        for i in range(3, len(nums) + 1):
            com = combinations(nums, i)
            for arr in com:
                if is_sequence(arr):
                    count += 1
        return count


if __name__ == "__main__":
    s = Solution()
    x = combinations([7, 7, 7, 7, 7], 3)
    assert s.numberOfArithmeticSlices([1, 2, 3, 4, 5, 6]) == 12
    assert s.numberOfArithmeticSlices([7, 7, 7, 7, 7]) == 16
    assert s.numberOfArithmeticSlices([2, 4, 6, 8, 10]) == 7
    """
    1,2,3,4,5,6
    -----------
    1,2,3
    1,2,3,4
    1,2,3,4,5
    1,2,3,4,5,6
    2,3,4
    2,3,4,5
    2,3,4,5,6
    3,4,5
    3,4,5,6
    4,5,6
    
    1,3,5
    2,4,6
    """

    """
    0,1,2,3,4
    ---------
    1 - 0,1,2
    2 - 0,1,2,3
    3 - 0,1,2,3,4
    4 - 0,1,3
    5 - 0,1,3,4
    6 - 0,1,4
    7 - 0,2,3
    8 - 0,2,4
    9 - 0,2,3,4
   10 - 0,3,4
   11 - 1,2,3
   12 - 1,2,3,4
   13 - 1,2,4
   14 - 1,3,4
   15 - 2,3,4
    """
