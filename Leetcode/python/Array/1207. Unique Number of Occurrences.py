from collections import Counter
from typing import List


class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        counter = Counter(arr)
        unique_set = set()
        for v in counter.values():
            if v in unique_set:
                return False
            unique_set.add(v)

        return True
