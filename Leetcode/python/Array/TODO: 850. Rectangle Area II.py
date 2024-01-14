from dataclasses import dataclass
from typing import List, Optional, Tuple

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


def gen_rect(rectangles: List[List[int]]) -> List[Rectangle]:
    res = []
    for raw in rectangles:
        r = Rectangle(raw[0], raw[2], raw[1], raw[3])
        r.sort()
        res.append(r)
    return res


def get_min_max_y(rects: List[Rectangle]) -> Tuple[int, int]:
    mins = 10**10
    maxx = -(10**10)
    for rec in rects:
        mins = min(mins, rec.y_bottom)
        maxx = max(maxx, rec.y_top)
    return (mins, maxx)


def area_from_range(ranges: List[int]) -> int:
    if len(ranges) == 0:
        return 0


class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        total_area = 0

        rects: List[Rectangle] = gen_rect(rectangles)
        rects = sorted(rects, key=lambda t: t.x_left)
        draw_rectangle([r.as_list for r in rects])

        mins, maxx = get_min_max_y(rects)

        y = mins
        while y < maxx:
            x_index = 0
            while x_index < len(rects):
                rect = rects[x_index]

                if rect.y_bottom > y or rect.y_top <= y:
                    x_index += 1
                    continue
                end_x = rect.x_right

                while x_index + 1 < len(rects) and rects[x_index + 1].x_left < end_x:
                    if rects[x_index + 1].y_bottom <= y and rects[x_index + 1].y_top > y:
                        end_x = max(rects[x_index + 1].x_right, end_x)
                    x_index += 1
                x_index += 1

                total_area += end_x - rect.x_left
            y += 1

        return total_area % (10**9 + 7)


if __name__ == "__main__":
    s = Solution()
    assert s.rectangleArea([[0, 0, 3, 3], [2, 0, 5, 3], [1, 1, 4, 4]]) == 18
    assert s.rectangleArea([[0, 0, 10, 10], [5, 5, 6, 6]]) == 100
    assert s.rectangleArea([[0, 0, 2, 2], [1, 0, 2, 3], [1, 0, 3, 1]]) == 6
    assert (
        s.rectangleArea(
            [
                [93516, 44895, 94753, 69358],
                [13141, 52454, 59740, 71232],
                [22877, 11159, 85255, 61703],
                [11917, 8218, 84490, 36637],
                [75914, 29447, 83941, 64384],
                [22490, 71433, 64258, 74059],
                [18433, 51177, 87595, 98688],
                [70854, 80720, 91838, 92304],
                [46522, 49839, 48550, 94096],
                [95435, 37993, 99139, 49382],
                [10618, 696, 33239, 45957],
                [18854, 2818, 57522, 78807],
                [61229, 36593, 76550, 41271],
                [99381, 90692, 99820, 95125],
            ]
        )
        == 971243962
    )
