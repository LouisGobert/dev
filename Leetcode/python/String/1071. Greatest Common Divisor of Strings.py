class Solution:
    def is_gcd(self, max_str: str, min_str: str) -> bool:
        left_max = left_min = 0

        while left_max < len(max_str):
            if left_min == len(min_str):
                left_min = 0

            if max_str[left_max] != min_str[left_min]:
                return False

            left_max += 1
            left_min += 1

        if left_min != len(min_str):
            return False
        return True

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if len(str1) > len(str2):
            max_str = str1
            min_str = str2
        else:
            max_str = str2
            min_str = str1

        for substring_index in range(len(min_str), 0, -1):
            dividor = min_str[:substring_index]
            if self.is_gcd(max_str, dividor) and self.is_gcd(min_str, dividor):
                return dividor

        return ""


if __name__ == "__main__":
    s = Solution()
    assert s.gcdOfStrings(str1="ABCABC", str2="ABC") == "ABC"
    assert s.gcdOfStrings("ABABAB", str2="ABAB") == "AB"
    assert s.gcdOfStrings(str1="LEET", str2="CODE") == ""
    assert (
        s.gcdOfStrings(str1="TAUXXTAUXXTAUXXTAUXXTAUXX", str2="TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX")
        == "TAUXX"
    )
