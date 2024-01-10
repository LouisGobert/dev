from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0] * len(temperatures)

        index = 0
        bigger_than = [0] * len(temperatures)
        while index + 1 < len(temperatures):
            if temperatures[index + 1] > temperatures[index]:
                res[index] = 1
                index += 1
                continue
            nextt = 1
            while index + nextt < len(temperatures):
                if temperatures[index + nextt] > temperatures[index]:
                    res[index] = nextt
                    nextt = len(temperatures)
                nextt += 1

            index += 1
        return res


if __name__ == "__main__":
    s = Solution()
    assert s.dailyTemperatures([73, 74, 75, 71, 69, 72, 76, 73]) == [1, 1, 4, 2, 1, 1, 0, 0]
