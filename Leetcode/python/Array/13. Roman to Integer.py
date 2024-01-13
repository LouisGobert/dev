SYMBOL_VALUE = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}

"""
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
"""


class Solution:
    def romanToInt(self, s: str) -> int:
        index = 0
        sums = 0
        while index < len(s):
            symbol = s[index]
            if index + 1 >= len(s):
                sums += SYMBOL_VALUE[symbol]
                index += 1
                continue

            next_symbol = s[index + 1]
            if symbol == "I":
                if next_symbol == "V":
                    sums += 4
                    index += 2
                    continue
                if next_symbol == "X":
                    sums += 9
                    index += 2
                    continue
            if symbol == "X":
                if next_symbol == "L":
                    sums += 40
                    index += 2
                    continue
                if next_symbol == "C":
                    sums += 90
                    index += 2
                    continue
            if symbol == "C":
                if next_symbol == "D":
                    sums += 400
                    index += 2
                    continue
                if next_symbol == "M":
                    sums += 900
                    index += 2
                    continue

            # Count occurence of next symbol
            cur_sum = SYMBOL_VALUE[symbol]
            sums += cur_sum
            index += 1

        return sums


if __name__ == "__main__":
    s = Solution()
    assert s.romanToInt("III") == 3
    assert s.romanToInt("LVIII") == 58
    assert s.romanToInt("MCMXCIV") == 1994
