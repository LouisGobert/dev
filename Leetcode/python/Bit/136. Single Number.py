from functools import reduce
from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        """
        2,2,1

        10
        console.log("🚀 ~ 10:", 10)
        10
        01

        """
        return reduce(lambda x, y: x ^ y, nums, 0)


if __name__ == "__main__":
    s = Solution()
    assert s.singleNumber([8, 8, 9]) == 9
