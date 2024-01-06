from collections import defaultdict
from typing import List


class Solution:
    min_op_for_number: dict[int, int]

    def min_operation_for_number(self, inital_number: int) -> int:
        # For this num, try to find the fatest way to delete it by 3 or 2
        min_op = 10**7
        for number in range(inital_number, 0, -3):
            if number % 3 == 0:
                min_op = min(number // 3 + (inital_number - number) // 3, min_op)
            if number % 2 == 0:
                min_op = min(number // 2 + (inital_number - number) // 3, min_op)

        for number in range(inital_number, 0, -2):
            if number % 3 == 0:
                min_op = min(number // 3 + (inital_number - number) // 2, min_op)
            if number % 2 == 0:
                min_op = min(number // 2 + (inital_number - number) // 2, min_op)

        return min_op if min_op != 10**7 else -1

    def minOperations(self, nums: List[int]) -> int:
        counter = defaultdict(int)
        for num in nums:
            counter[num] += 1

        total = 0
        for num in counter.values():
            min_op = self.min_operation_for_number(num)
            if min_op == -1:
                return -1
            total += min_op
        # Check if one number is not divisable by
        return total


if __name__ == "__main__":
    s = Solution()
    assert s.minOperations([2, 3, 3, 2, 2, 4, 2, 3, 4]) == 4
    # 2 2 2 2 2
    assert s.minOperations([2, 2, 2, 2, 2]) == 2
    assert s.minOperations([14, 12, 14, 14, 12, 14, 14, 12, 12, 12, 12, 14, 14, 12, 14, 14, 14, 12, 12]) == 7
