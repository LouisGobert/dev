from typing import Counter, List


class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        counter = Counter(nums)
        required_sub_array = max(counter.values())
        result = []
        for i in range(required_sub_array):
            result.append([])

        counter_lenght = len(counter)
        for i in range(counter_lenght):
            number, number_count = counter.popitem()
            for ii in range(number_count):
                result[ii].append(number)

        return result


if __name__ == "__main__":
    s = Solution()
    s.findMatrix([1, 3, 4, 1, 2, 3, 1]) == [[1, 3, 4, 2], [1, 3], [1]]
