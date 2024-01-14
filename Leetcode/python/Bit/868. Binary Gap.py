class Solution:
    def binaryGap(self, n: int) -> int:
        index = 0
        last_seen_index = -1
        maxx = 0
        while n > 0:
            if n % 2 == 1:
                if last_seen_index != -1:
                    maxx = max(maxx, index - last_seen_index)
                last_seen_index = index
            n >>= 1
            index += 1

        return maxx


if __name__ == "__main__":
    s = Solution()
    assert s.binaryGap(22) == 2
    assert s.binaryGap(8) == 0
    assert s.binaryGap(5) == 2
