from typing import List


class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        longest = 1
        maxx = 0
        last_val = nums[0]
        for num in nums[1:]:
            if num > last_val:
                longest += 1
            else:
                maxx = max(longest, maxx)
                longest = 1
            last_val = num

        return max(maxx, longest)


if __name__ == "__main__":
    s = Solution()
    assert s.findLengthOfLCIS([1, 3, 5, 4, 7]) == 3
    assert s.findLengthOfLCIS([1, 3, 5, 7]) == 4
