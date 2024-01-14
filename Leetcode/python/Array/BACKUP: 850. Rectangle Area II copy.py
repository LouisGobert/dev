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


def compute_area(rect: Rectangle) -> int:
    if rect.x_left == rect.x_right or rect.y_bottom == rect.y_top:
        return 0
    lenght = abs(rect.x_left - rect.x_right)
    height = abs(rect.y_top - rect.y_bottom)
    return lenght * height


def compute_same_area(rect_a: Rectangle, rect_b: Rectangle) -> Tuple[int, Optional[Rectangle]]:
    x_right_max = min(rect_a.x_right, rect_b.x_right)
    x_left_max = max(rect_b.x_left, rect_a.x_left)
    y_top_max = min(rect_a.y_top, rect_b.y_top)
    y_bottom_max = max(rect_b.y_bottom, rect_a.y_bottom)

    if x_right_max <= x_left_max or y_bottom_max >= y_top_max:
        return (0, None)
    lenght = abs(x_right_max - x_left_max)
    h = abs(y_top_max - y_bottom_max)

    rect = Rectangle(x_left_max, x_right_max, y_top_max, y_bottom_max)
    rect.sort()
    area = compute_area(rect)
    return (area, rect)


def gen_rect(rectangles: List[List[int]]) -> List[Rectangle]:
    res = []
    for raw in rectangles:
        r = Rectangle(raw[0], raw[2], raw[1], raw[3])
        r.sort()
        res.append(r)
    return res


def distinct_area(rects: List[Rectangle]):
    total_area = 0
    for rect in rects:
        total_area += compute_area(rect)

    total_same_area = 0
    for index, rect in enumerate(rects[:-1]):
        for other_rect in rects[index + 1 :]:
            ar, n = compute_same_area(rect, other_rect)
            total_same_area += ar

    return total_area - total_same_area
    # Remo


class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        intersection_rectangle: List[Rectangle] = []

        rects: List[Rectangle] = gen_rect(rectangles)
        rects = sorted(rects, key=lambda t: t.x_left)
        draw_rectangle([r.as_list for r in rects])

        total_area = compute_area(rects[0])
        for index, rect in enumerate(rects[1:]):
            index += 1
            rect_area = compute_area(rect)
            print((f"Rect area: {rect_area}"))

            removed_area: List[Rectangle] = []
            for next_index, next_rect in enumerate(rects[:index]):
                if next_index == index:
                    continue
                same_area, int_rect = compute_same_area(rect, next_rect)
                if int_rect is None:
                    continue

                # Check if int_rect not already in removed_area
                removed_area.append(int_rect)
                # if len(removed_area) == 0:
                #     rect_area -= same_area
                #     continue

            rect_area -= distinct_area(removed_area)
            total_area += rect_area

        return total_area % (10**9 + 7)


if __name__ == "__main__":
    s = Solution()
    assert s.rectangleArea([[0, 0, 10, 10], [5, 5, 6, 6]]) == 100
    assert s.rectangleArea([[0, 0, 2, 2], [1, 0, 2, 3], [1, 0, 3, 1]]) == 6
    assert s.rectangleArea([[0, 0, 3, 3], [2, 0, 5, 3], [1, 1, 4, 4]]) == 18
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
