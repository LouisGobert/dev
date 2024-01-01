class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        char_index: dict[str, int] = {}
        max_distance = -1
        for index, char in enumerate(s):
            if char in char_index:
                distance = index - char_index[char] - 1
                max_distance = max(max_distance, distance)
            else:
                char_index[char] = index

        return max_distance


if __name__ == "__main__":
    s = Solution()

    r = s.maxLengthBetweenEqualCharacters("afgea")
    assert r == 3

    assert s.maxLengthBetweenEqualCharacters("aa") == 0
    assert s.maxLengthBetweenEqualCharacters("djhukyer") == -1
    assert s.maxLengthBetweenEqualCharacters("mgntdygtxrvxjnwksqhxuxtrv") == 18
