class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        ...

        p1 = p2 = 0
        result = ""
        while p1 < len(word1) and p2 < len(word2):
            result += word1[p1] + word2[p2]
            p1 += 1
            p2 += 1

        while p1 < len(word1):
            result += word1[p1]
            p1 += 1
        while p2 < len(word2):
            result += word2[p2]
            p2 += 1

        return result


if __name__ == "__main__":
    s = Solution()

    assert s.mergeAlternately(word1="ab", word2="pqrs") == "apbqrs"
