from collections import Counter
from typing import List, Tuple


class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        counter = Counter(arr)
        min_element: List[Tuple[int, int]] = counter.most_common()[::-1]

        total_distinct_number = len(min_element)
        deleted_number = 0
        for number, number_count in min_element:
            if number_count <= k:
                deleted_number += 1
            k -= number_count
            if k <= 0:
                break

        return total_distinct_number - deleted_number


if __name__ == "__main__":
    s = Solution()
    assert s.findLeastNumOfUniqueInts([5, 5, 4], 1) == 1
    assert s.findLeastNumOfUniqueInts([4, 3, 1, 1, 3, 3, 2], 3) == 2
