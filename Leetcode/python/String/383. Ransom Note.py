from collections import Counter


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        note_counter = Counter(ransomNote)
        magazine_counter = Counter(magazine)

        for letter in ransomNote:
            if letter not in magazine_counter or magazine_counter[letter] < note_counter[letter]:
                return False
        return True


if __name__ == "__main__":
    s = Solution()
    assert s.canConstruct("a", "b") == False
    assert s.canConstruct("a", "a") == True
