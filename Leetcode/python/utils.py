from typing import List

import matplotlib
import matplotlib.patches as patches
import matplotlib.pyplot as plt
import numpy as np

matplotlib.use("TkAgg")


def binarySearch(list, val):
    l = 0
    r = len(list)
    midle = 0
    while l <= r:
        midle = (r + l) // 2

        if list[midle] == val:
            return midle
        else:
            if list[midle] < val:
                l = midle + 1
            else:
                r = midle - 1

        return None


def draw_rectangle(rects: List[List[int]]):
    # Extracting coordinates

    # Create figure and axes
    fig, ax = plt.subplots()

    max_left = 0
    max_right = 0
    max_top = 0
    max_bottom = 0

    colors = np.random.random((len(rects), 3))
    for index, rect in enumerate(rects):
        xi1, yi1, xi2, yi2 = rect

        max_left = min(xi1, max_left)
        max_right = max(max_right, xi2)
        max_bottom = min(yi1, max_bottom)
        max_top = max(max_top, yi2)

        width = xi2 - xi1
        height = yi2 - yi1
        # Create a Rectangle patch
        rect = patches.Rectangle((xi1, yi1), width, height, linewidth=1, edgecolor=colors[index], facecolor="none")

        # Add the rectangle to the Axes
        ax.add_patch(rect)

    # Set limits
    ax.set_xlim(max_left - 1, max_right + 1)
    ax.set_ylim(max_bottom - 1, max_top + 1)
    plt.show()
