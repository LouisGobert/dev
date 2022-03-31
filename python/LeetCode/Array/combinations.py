from typing import List
from itertools import combinations

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:

        arr = [i for i in range(1, n+1)]
        comb = list(combinations(arr, k))

        return comb
