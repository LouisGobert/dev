from collections import defaultdict
from typing import List, Tuple

import matplotlib.pyplot as plt

# NOT SOLUTIONED


def draw_skyline(buildings):
    """
    Draw the skyline based on the buildings' information.
    """
    # Get the skyline points
    skyline = [
        [2, 10],
        [3, 15],
        [7, 12],
        [12, 0],
        [15, 10],
        [20, 8],
        [24, 0],
    ]

    # Prepare data for plotting
    x = [skyline[0][0]]
    y = [0]
    for i in range(len(skyline)):
        x.extend([skyline[i][0], skyline[i][0]])
        y.extend([y[-1], skyline[i][1]])
    x.append(skyline[-1][0])
    y.append(0)

    # Plot the skyline
    plt.figure(figsize=(10, 5))
    plt.plot(x, y, linewidth=2)
    plt.fill_between(x, y, step="pre", alpha=0.4)
    plt.title("City Skyline")
    plt.xlabel("X coordinate")
    plt.ylabel("Height")
    plt.grid(True)
    plt.show()


# draw_skyline([])


class Solution:
    heights: list[Tuple[int, int, int]]

    def construct_final_array(self, array: list[Tuple[int, int]]) -> List[List[int]]:
        final_array = []
        last_height = 0
        for x_pos, height in array:
            if last_height != height:
                final_array.append([x_pos, height])
                last_height = height

        return final_array

    def find_biggest_height_for_x(self, x: int, building: List[List[int]]) -> int:
        ...
        maxx = 0
        for left, right, height in building:
            if left <= x and right > x:
                maxx = max(maxx, height)
            if left > x:
                return maxx

        return maxx

    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        sorted_building = sorted(buildings, key=lambda b: b[0])
        heights: dict[int, int] = defaultdict(int)

        x_to_check = set()
        for b in sorted_building:
            x_to_check.add(b[0])
            x_to_check.add(b[1])

        for index, x_pos in enumerate(x_to_check):
            # b_left, b_right, b_height = b
            # if b[0] not in heights:
            heights[x_pos] = self.find_biggest_height_for_x(x_pos, sorted_building)
        # for index, b in enumerate(sorted_building):
        #     b_left, b_right, b_height = b
        #     if b[0] not in heights:
        #         heights[b[0]] = self.find_biggest_height_for_x(b_left, sorted_building[: index + 1])
        #     elif b[2] > sorted_building[b[0]][2]:
        #         heights[b_left] = b_height

        #     if b_right not in heights:
        #         heights[b_right] = self.find_biggest_height_for_x(b_left, sorted_building[: index + 1])
        #     elif b_height > sorted_building[b_right][2]:
        #         heights[b_right] = b_height

        pre_sorted = sorted(list(heights.items()), key=lambda t: t[0])
        return self.construct_final_array(pre_sorted)


if __name__ == "__main__":
    s = Solution()
    assert s.getSkyline([[2, 9, 10], [3, 7, 15], [5, 12, 12], [15, 20, 50], [19, 24, 8]]) == [
        [2, 10],
        [3, 15],
        [7, 12],
        [12, 0],
        [15, 50],
        [20, 8],
        [24, 0],
    ]

    assert s.getSkyline([[0, 2, 3], [2, 5, 3]]) == [[0, 3], [5, 0]]
