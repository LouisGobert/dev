from typing import List

MAX_VALUE = (10**4) + 1


class Solution:
    def jump(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        min_jump = [MAX_VALUE] * len(nums)

        for index in range(len(nums) - 1, -1, -1):
            num = nums[index]
            index_min_count = MAX_VALUE
            if index + 1 == len(nums):
                min_jump[-1] = 0
                continue
            for next_index in range(index + 1, index + num + 1):
                if next_index >= len(nums):
                    break
                index_min_count = min(min_jump[next_index], index_min_count)

            min_jump[index] = index_min_count + 1

        return min_jump[0]


if __name__ == "__main__":
    s = Solution()
    assert s.jump([2, 3, 1, 1, 4]) == 2
    assert s.jump([2, 3, 0, 1, 4]) == 2
    assert s.jump([0]) == 0
    assert s.jump([2, 1]) == 1
