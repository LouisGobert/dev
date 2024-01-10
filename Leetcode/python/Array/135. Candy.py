from typing import List, Optional


def generate_decreasing_count(array: List[int], decrease: List[int], start_index: int) -> None:
    for index in range(start_index, len(array)):
        if decrease[index] != -1:
            continue
        val = array[index]
        if index + 1 == len(array):
            decrease[index] = 0
            return
        next_val = array[index + 1]
        if next_val < val:
            if decrease[index + 1] == -1:
                generate_decreasing_count(array, decrease, index + 1)
            decrease[index] = decrease[index + 1] + 1
        else:
            decrease[index] = 0


class Solution:
    def candy(self, ratings: List[int]) -> int:
        drecrease_left: List[int] = [-1] * len(ratings)
        generate_decreasing_count(ratings, drecrease_left, 0)
        print(drecrease_left)

        counter = [1] * len(ratings)
        for index, rate in enumerate(ratings):
            if index != 0:
                # Check left neighbors
                if ratings[index - 1] < rate:
                    counter[index] = counter[index - 1] + 1
            if index + 1 != len(ratings) and ratings[index + 1] < rate:
                counter[index] = max(drecrease_left[index] + 1, counter[index])

        return sum(counter)


if __name__ == "__main__":
    s = Solution()
    # 1 2 1 2 1
    assert s.candy([1, 3, 2, 2, 1]) == 7
    assert s.candy([5, 4, 3, 2, 1, 0]) == 21
    assert s.candy([1, 0, 2]) == 5
    assert s.candy([1, 2, 3, 4, 5, 5]) == 16
    """
    1 2 3 4 5 1
    
    """
    assert s.candy([1, 2, 2]) == 4
