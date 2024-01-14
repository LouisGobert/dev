from dataclasses import dataclass
from typing import List, Optional, Tuple


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


def compute_same_area(rect_a: Rectangle, rect_b: Rectangle) -> bool:
    x_right_max = min(rect_a.x_right, rect_b.x_right)
    x_left_max = max(rect_b.x_left, rect_a.x_left)
    y_top_max = min(rect_a.y_top, rect_b.y_top)
    y_bottom_max = max(rect_b.y_bottom, rect_a.y_bottom)

    if x_right_max <= x_left_max or y_bottom_max >= y_top_max:
        return False
    return True


def gen_rect(rectangles: List[List[int]]) -> List[Rectangle]:
    res = []
    for raw in rectangles:
        r = Rectangle(raw[0], raw[2], raw[1], raw[3])
        r.sort()
        res.append(r)
    return res


class Solution:
    def isRectangleOverlap(self, rec1: List[int], rec2: List[int]) -> bool:
        f = [
            rec1,
        ]
        rects = gen_rect([rec1, rec2])
        return compute_same_area(rects[0], rects[1])


if __name__ == "__main__":
    s = Solution()
