import math
from typing import List


class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        max_altitude = 0
        current_altitude = 0
        for g in gain:
            current_altitude += g
            max_altitude = max(max_altitude, current_altitude)

        return max_altitude


if __name__ == "__main__":
    s = Solution()
    assert s.largestAltitude([-5, 1, 5, 0, -7]) == 1
    assert s.largestAltitude([-4, -3, -2, -1, 4, 3, 2]) == 0
