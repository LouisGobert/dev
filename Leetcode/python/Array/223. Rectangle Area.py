from dataclasses import dataclass
from typing import List

from Leetcode.python.utils import draw_rectangle


@dataclass
class Rectangle:
    x_left: int
    x_right: int
    y_top: int
    y_bottom: int

    def sort(self):
        if self.x_left > self.x_right:
            t = self.x_right
            self.x_right = self.x_left
            self.x_left = t
        if self.y_top < self.y_bottom:
            t = self.y_bottom
            self.y_bottom = self.y_top
            self.y_top = t

    @property
    def as_list(self) -> List[int]:
        return [self.x_left, self.y_bottom, self.x_right, self.y_top]


def compute_area(rect: Rectangle) -> int:
    if rect.x_left == rect.x_right or rect.y_bottom == rect.y_top:
        return 0
    lenght = abs(rect.x_left - rect.x_right)
    height = abs(rect.y_top - rect.y_bottom)
    return lenght * height


def compute_same_area(rect_a: Rectangle, rect_b: Rectangle) -> int:
    # Check if overlap
    # CHeck uper left b is in rect_a
    # if rect_b.y_top > rect_a.y_bottom and

    x_right_max = min(rect_a.x_right, rect_b.x_right)
    x_left_max = max(rect_b.x_left, rect_a.x_left)
    y_top_max = min(rect_a.y_top, rect_b.y_top)
    y_bottom_max = max(rect_b.y_bottom, rect_a.y_bottom)

    if x_right_max <= x_left_max or y_bottom_max >= y_top_max:
        return 0
    print(x_left_max)
    print(x_right_max)
    print(y_top_max)
    print(y_bottom_max)
    lenght = abs(x_right_max - x_left_max)
    h = abs(y_top_max - y_bottom_max)
    return h * lenght


class Solution:
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:
        r1 = Rectangle(ax1, ax2, ay1, ay2)
        r2 = Rectangle(bx1, bx2, by1, by2)

        rectanglas_list = [r1.as_list, r2.as_list]
        # draw_rectangle(rectanglas_list)
        r1.sort()
        r2.sort()
        area1 = compute_area(r1)
        area2 = compute_area(r2)

        same_area = compute_same_area(r1, r2)
        return area1 + area2 - same_area


if __name__ == "__main__":
    s = Solution()
    assert s.computeArea(ax1=-3, ay1=0, ax2=3, ay2=4, bx1=0, by1=-1, bx2=9, by2=2) == 45
    assert s.computeArea(ax1=-2, ay1=-2, ax2=2, ay2=2, bx1=-2, by1=-2, bx2=2, by2=2) == 16
    assert s.computeArea(ax1=-2, ay1=-2, ax2=2, ay2=2, bx1=3, by1=3, bx2=4, by2=4) == 17
