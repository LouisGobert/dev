class Solution:
    def reverseWords(self, words: str) -> str:
        words_r = words.split()[::-1]
        words_r = [r.strip() for r in words_r if r.strip() != ""]
        return " ".join(words_r)
        # word = ""
        # reversed = ""
        # for letter in words[::-1]:
        #     if letter == " ":
        #         if len(word)
        #         reversed += word[::-1] + " "
        #         word = ""
        #     else:
        #         word += letter

        # reversed += word[::-1]
        # return reversed


if __name__ == "__main__":
    s = Solution()
    assert s.reverseWords("the sky is blue") == "blue is sky the"
    assert s.reverseWords("  hello  world  ") == "world hello"
