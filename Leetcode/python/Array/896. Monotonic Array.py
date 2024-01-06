from typing import List


class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        if len(nums) == 1:
            return True
        is_increase = None  # Mean unknows

        last_number = nums[0]
        for num in nums[1:]:
            if num != last_number and is_increase is None:
                is_increase = last_number < num
            elif num != last_number and is_increase is not None:
                if is_increase and num < last_number:
                    return False
                if not is_increase and num > last_number:
                    return False

            last_number = num
        return True


if __name__ == "__main__":
    s = Solution()

    assert s.isMonotonic([1, 2, 2, 3])
    assert s.isMonotonic([6, 5, 4, 4])
    assert s.isMonotonic([1, 3, 2]) is False
