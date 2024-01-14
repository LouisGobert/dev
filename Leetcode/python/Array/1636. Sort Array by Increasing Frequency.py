from collections import Counter
from typing import List, Tuple


class Solution:
    def insert_decreasing(self, red: List[int], freqs: List[Tuple[int, int]]) -> None:
        freqs.sort(reverse=True)
        for v, count in freqs:
            red.extend([v] * count)

    def frequencySort(self, nums: List[int]) -> List[int]:
        res: List[int] = []
        counter = Counter(nums)
        freqences = counter.most_common()

        index = len(freqences) - 2
        last_freq = freqences[-1][1]
        same_freq = [freqences[-1]]
        while index >= 0:
            val, freq = freqences[index]
            if freq == last_freq:
                same_freq.append(freqences[index])
            else:
                self.insert_decreasing(res, same_freq)
                same_freq = [freqences[index]]
                last_freq = freqences[index][1]
            index -= 1
        self.insert_decreasing(res, same_freq)
        return res


if __name__ == "__main__":
    s = Solution()
    assert s.frequencySort([1, 1, 2, 2, 2, 3]) == [3, 1, 1, 2, 2, 2]
    assert s.frequencySort([1, 5, 0, 5]) == [1, 0, 5, 5]
    assert s.frequencySort([3, 8, 7, -7, 5, 3, -7]) == [8, 7, 5, 3, 3, -7, -7]
