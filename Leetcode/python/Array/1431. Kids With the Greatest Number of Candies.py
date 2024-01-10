from typing import List


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        grant_max = max(candies)
        r = []
        for c in candies:
            r.append(c + extraCandies >= grant_max)
        return r


if __name__ == "__main__":
    s = Solution()
    assert s.kidsWithCandies([2, 3, 5, 1, 3], 3) == [True, True, True, False, True]
