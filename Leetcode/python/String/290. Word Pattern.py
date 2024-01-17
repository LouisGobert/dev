class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        char_to_word: dict[str, str] = {}

        words = s.split()
        word_used = set()
        if len(words) != len(pattern):
            return False
        for index, word in enumerate(words):
            char_pattern = pattern[index]
            if char_pattern in char_to_word:
                if char_to_word[char_pattern] != word:
                    return False

            else:
                if word in word_used:
                    return False
                char_to_word[char_pattern] = word
                word_used.add(word)
        return True


if __name__ == "__main__":
    s = Solution()
    assert s.wordPattern(pattern="abba", s="dog cat cat dog") == True
    assert s.wordPattern(pattern="aaaa", s="dog cat cat dog") == False
    assert s.wordPattern(pattern="abba", s="dog cat cat fish") == False
    assert s.wordPattern("abba", "dog dog dog dog") == False
