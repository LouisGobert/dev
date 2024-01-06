from collections import Counter


class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        counter = Counter(s)
        r = "1" * (counter["1"] - 1) + "0" * (counter["0"]) + "1"
        return r


if __name__ == "__main__":
    s = Solution()
    assert s.maximumOddBinaryNumber("0101") == "1001"
    # 2 2 2 2 2
