from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1

        maxx = 0
        while left != right:
            current_volume = (right - left) * min(height[right], height[left])
            maxx = max(maxx, current_volume)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1

        return maxx


if __name__ == "__main__":
    s = Solution()
    assert s.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]) == 49
    assert s.maxArea([1]) == 1
