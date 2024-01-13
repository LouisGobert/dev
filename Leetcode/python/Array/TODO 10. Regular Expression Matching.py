from typing import Optional

ANY_CHAR = "."
LAST_ELEM_ZERO_OR_MORE = "*"


def zero_or_more(string: str, s_index: int, last_regex_char: str, next_regex_value: Optional[str]) -> int:
    while (
        s_index < len(string)
        and (string[s_index] == last_regex_char or last_regex_char == ANY_CHAR)
        and string[s_index] != next_regex_value
    ):
        s_index += 1

    return s_index


class Solution:
    def isMatch(self, s: str, pattern: str) -> bool:
        index = 0
        regex_index = 0
        while index < len(s):
            if regex_index >= len(pattern):
                return False

            regex_char = pattern[regex_index]
            s_char = s[index]
            if s_char == regex_char:
                index += 1
                regex_index += 1
                continue
            if regex_char == LAST_ELEM_ZERO_OR_MORE:
                last_regex_value = pattern[regex_index - 1]
                next_regex_value = None
                if regex_index + 1 != len(pattern):
                    next_regex_value = pattern[regex_index + 1]

                new_index = index
                while new_index < len(s):
                    new_index = zero_or_more(s, new_index, last_regex_value, next_regex_value)
                    splited_string = s[new_index:]
                    splited_pattern = pattern[regex_index + 1 :]
                    print(f"String '{splited_string}' with pattern '{splited_pattern}' NOT MATCHED")
                    if self.isMatch(splited_string, splited_pattern):
                        print(f"String '{splited_string}' with pattern '{splited_pattern}' MATCHED")
                        return True
                    print(f"String '{splited_string}' with pattern '{splited_pattern}' NOT MATCHED")
                    new_index += 1
                regex_index += 1
                continue
            if regex_char == ANY_CHAR:
                index += 1
                regex_index += 1
                continue
            regex_index += 1
            # return False

        return True


if __name__ == "__main__":
    s = Solution()
    assert s.isMatch(s="ippi", pattern="p*.") == False
    assert s.isMatch(s="issippi", pattern="is*p*.") == False
    assert s.isMatch(s="mississippi", pattern="mis*is*p*.") == False

    """
    ab cdcd = cd
    abcd cd = cd
    """

    assert s.isMatch(s="abcdcd", pattern=".*cd") == True

    assert s.isMatch(s="aab", pattern="c*a*b") == True
    assert s.isMatch(s="ab", pattern=".*") == True
    assert s.isMatch(s="abcd", pattern=".*cd") == True
    assert s.isMatch(s="aa", pattern="a") is False
    assert s.isMatch("aa", pattern="a*") is True
