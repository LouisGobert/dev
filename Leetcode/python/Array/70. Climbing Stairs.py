class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        if n == 2:
            return 2

        stair = [1, 2]
        ways = 0
        for step in range(n - 2):
            stair.append(stair[-1] + stair[-2])

        return stair[-1]


if __name__ == "__main__":
    s = Solution()

    assert s.climbStairs(1) == 1
    assert s.climbStairs(2) == 2
    assert s.climbStairs(3) == 3
    assert s.climbStairs(4) == 5
