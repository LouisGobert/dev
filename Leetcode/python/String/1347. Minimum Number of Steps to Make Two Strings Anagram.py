from collections import Counter


class Solution:
    def minSteps(self, s: str, t: str) -> int:
        counter_s = Counter(s)
        counter_t = Counter(t)

        res = 0
        for key, count in counter_s.items():
            if key not in counter_t:
                res += count
            elif counter_t[key] != count:
                diff = count - counter_t[key]
                if diff > 0:
                    res += diff
        return res


if __name__ == "__main__":
    s = Solution()

    assert s.minSteps(s="leetcode", t="practice") == 5
    assert s.minSteps("bab", t="aba") == 1
    assert s.minSteps("anagram", t="mangaar") == 0
