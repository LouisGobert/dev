VOWELS = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]


class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        mid_pos = len(s) // 2

        cpt = 0
        last_index = len(s) - 1
        for index in range(mid_pos):
            if s[index] in VOWELS:
                cpt += 1
            if s[last_index - index] in VOWELS:
                cpt -= 1

        return cpt == 0
