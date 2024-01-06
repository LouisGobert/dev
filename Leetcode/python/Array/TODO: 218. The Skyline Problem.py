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

    def construct_final_array(self, array: list[int]) -> List[List[int]]:
        final_array = []
        last_value = 0
        for x, arr in enumerate(array):
            if last_value != arr:
                final_array.append([x, arr])
                last_value = arr

        return final_array

    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        sorted_building = sorted(buildings, key=lambda b: b[0])

        heights: list[List[int]] = [sorted_building[0]]

        for building in heights:
            next_max: List[int] = [0, 0, -1]
            for next_building in sorted_building:
                next_height = next_building[2]
                # next_height > building[1] and
                if next_height > next_max[2] and next_building[0] <= building[0] + building[1]:
                    next_max = next_building
            heights.append(next_max)

        return []


if __name__ == "__main__":
    s = Solution()
    assert s.getSkyline([[2, 9, 10], [3, 7, 15], [5, 12, 12], [15, 20, 50], [19, 24, 8]]) == [
        [2, 10],
        [3, 15],
        [7, 12],
        [12, 0],
        [15, 10],
        [20, 8],
        [24, 0],
    ]

    assert s.getSkyline([[0, 2, 3], [2, 5, 3]]) == [[0, 3], [5, 0]]
