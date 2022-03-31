from typing import List

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        max_length = 0
        char_list = []

        for i, char in enumerate(s):

            if char in char_list:

                if max_length < len(char_list):
                    max_length = len(char_list)

                char_list = char_list[char_list.index(char)+1:]

            char_list.append(char)
        """
        louuis
        """

        if max_length < len(char_list):
            max_length = len(char_list)
        return max_length
