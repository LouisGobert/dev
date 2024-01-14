from collections import Counter


class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        counter_1 = Counter(word1)
        counter_2 = Counter(word2)

        mc_1 = counter_1.most_common()
        mc_2 = counter_2.most_common()

        if len(mc_1) != len(mc_2):
            return False

        distinct_1 = set(sorted(counter_1)).difference(sorted(counter_2))
        if len(distinct_1) != 0:
            return False

        for t1, t2 in zip(mc_1, mc_2):
            if t1[1] != t2[1]:
                return False

        return True


if __name__ == "__main__":
    s = Solution()
    assert s.closeStrings("abc", word2="bca") == True
    assert s.closeStrings("a", word2="aa") == False
    assert s.closeStrings(word1="cabbba", word2="abbccc") == True
    assert s.closeStrings("uau", "ssx") == False
