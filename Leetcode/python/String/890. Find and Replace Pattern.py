from typing import List


class Solution:
    def is_pattern(self, word: str, pattern: str) -> bool:
        if len(word) != len(pattern):
            return False

        pattern_match: dict[str, str] = {}
        reversed_match: dict[str, str] = {}

        for index, word_letter in enumerate(word):
            pattern_letter = pattern[index]

            if pattern_letter not in pattern_match:
                pattern_match[pattern_letter] = word_letter

            if word_letter not in reversed_match:
                reversed_match[word_letter] = pattern_letter

            if pattern_match[pattern_letter] != word_letter or reversed_match[word_letter] != pattern_letter:
                return False

        return True

    def stupid(self, word: str, pattern: str) -> bool:
        replaced_letter = {}

        for index in range(len(word)):
            if word[index] != None:
                ...

    def findAndReplacePattern(self, words: List[str], pattern: str) -> List[str]:
        result = []
        for word in words:
            if self.is_pattern(word, pattern):
                print(f"{word} respect pattern")
                result.append(word)

        return result


if __name__ == "__main__":
    s = Solution()
    assert s.findAndReplacePattern(["abc", "deq", "mee", "aqq", "dkd", "ccc"], pattern="abb") == ["mee", "aqq"]
