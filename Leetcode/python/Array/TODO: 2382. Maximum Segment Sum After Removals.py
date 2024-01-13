import bisect
import heapq
from copy import deepcopy
from dataclasses import dataclass
from turtle import right
from typing import List, Set, Tuple

import rich


@dataclass
class Entry:
    # points: List[int]
    start_index: int
    end_index: int
    sum: int
    was_splited: bool = False

    def __gt__(self, other) -> bool:
        return True


def binary_search(sum_list: List[Entry], index: int) -> Tuple[Entry, int]:
    left = 0
    right = len(sum_list) - 1
    while True:
        middle = (right + left) // 2
        if right == left:
            middle = right
        if sum_list[middle].start_index <= index and sum_list[middle].end_index >= index:
            return sum_list[middle], middle
        if sum_list[middle].start_index >= index:
            right = middle - 1
        else:
            left = middle + 1 if left + 1 != middle else middle + 2


def binary_insert(nums: List[Entry], entry: Entry) -> None:
    lo = 0
    hi = None
    if lo < 0:
        raise ValueError("lo must be non-negative")
    if hi is None:
        hi = len(nums)
    while lo < hi:
        mid = (lo + hi) // 2
        if nums[mid].start_index < entry.start_index:
            lo = mid + 1
        else:
            hi = mid

    nums.insert(lo, entry)
    # return lo


class Solution:
    unremoved_index: Set[int]
    heap: List[Tuple[int, Entry]]
    sum_list: List[Entry]
    incremented_nums: List[int]
    reverse_incremented_nums: List[int]
    nums: List[int]

    def split_entry(self, entry: Entry, index: int) -> List[Entry]:
        entry.was_splited = True
        splited_entries = []
        if entry.start_index != index:
            left_val = self.reverse_incremented_nums[entry.start_index] - self.reverse_incremented_nums[index]
            if left_val != 0:
                splited_entries.append(Entry(entry.start_index, index - 1, left_val))

        if entry.end_index != index:
            right_val = self.incremented_nums[entry.end_index] - self.incremented_nums[index]
            if right_val != 0:
                splited_entries.append(Entry(index + 1, entry.end_index, right_val))

        return splited_entries

    def get_max(self, remove_index: int) -> int:
        if len(self.heap) == 0:
            return 0
        max_sum, entry = self.heap[0]
        if entry.was_splited:
            heapq.heappop(self.heap)
            return self.get_max(remove_index)
        return max_sum

    def split(self, index: int) -> None:
        entry, to_del = binary_search(self.sum_list, index)
        self.sum_list.pop(to_del)

        spliteds = self.split_entry(entry, index)
        for e in spliteds:
            heapq.heappush(self.heap, (-e.sum, e))
            binary_insert(self.sum_list, e)
            # self.sum_list.append(e)

        # self.sum_list = sorted(self.sum_list, key=lambda t: t.start_index)

    def maximumSegmentSum(self, nums: List[int], removeQueries: List[int]) -> List[int]:
        first_entry = Entry(0, len(nums) - 1, sum(nums))
        self.heap = [(-first_entry.sum, first_entry)]
        res = []
        self.sum_list = [first_entry]
        self.nums = nums

        self.incremented_nums = []
        self.reverse_incremented_nums = [0] * len(nums)
        for i, n in enumerate(nums):
            if i == 0:
                self.incremented_nums.append(n)
                self.reverse_incremented_nums[-1] = nums[-1]
                continue
            self.incremented_nums.append(nums[i] + self.incremented_nums[i - 1])
            self.reverse_incremented_nums[(-i) - 1] = nums[-i - 1] + self.reverse_incremented_nums[-i]

        for remove_index in removeQueries:
            self.split(remove_index)
            res.append(-self.get_max(remove_index))

        return res


if __name__ == "__main__":
    e1 = Entry(5, 6, 8)
    e2 = Entry(1, 2, 8)
    e3 = Entry(2, 3, 8)
    e4 = Entry(6, 7, 8)
    numss = []
    binary_insert(numss, e1)
    binary_insert(numss, e2)
    binary_insert(numss, e3)
    binary_insert(numss, e4)

    assert numss == [e2, e3, e1, e4]

    s = Solution()
    #  1  3  8 14  15
    # 15 14 12  7   1 - REVERSE
    #  0  2  5  6   1 = 14
    #  0  2  5  0   1 = 7
    #  0  2  0  0   1 = 2
    #  0  2  0  0   0 = 2
    #  0  0  0  0   0 = 0
    assert s.maximumSegmentSum(nums=[1, 2, 5, 6, 1], removeQueries=[0, 3, 2, 4, 1]) == [14, 7, 2, 2, 0]

    # 1 3 6 10 15
    # 1 2 3  0  5 = 6
    # 0 2 3  0  5 = 5
    # 0 2 3  0  0 = 5
    # 0 2 0  0  0 = 2
    # 0 0 0  0  0 =10
    assert s.maximumSegmentSum(nums=[1, 2, 3, 4, 5], removeQueries=[3, 0, 4, 2, 1]) == [6, 5, 5, 2, 0]

    assert s.maximumSegmentSum([1, 2, 5, 6, 1], [0, 3, 2, 4, 1])
    assert s.maximumSegmentSum(
        [244, 19, 445, 671, 801, 103, 291, 335, 781, 33, 51, 789, 746, 510, 38, 7, 529, 905],
        [4, 8, 11, 12, 1, 5, 0, 9, 6, 17, 3, 15, 14, 7, 2, 13, 16, 10],
    )
