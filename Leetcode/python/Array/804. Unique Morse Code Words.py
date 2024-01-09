from typing import List, Set

MORSE = [
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",
]


def get_str_as_morse(string: str) -> str:
    new_string = ""
    for letter in string:
        new_string += MORSE[ord(letter) - 97]
    return new_string


class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        uniqe_morse: Set[str] = set()
        for word in words:
            uniqe_morse.add(get_str_as_morse(word))

        return len(uniqe_morse)


if __name__ == "__main__":
    s = Solution()
    assert s.uniqueMorseRepresentations(["gin", "zen", "gig", "msg"]) == 2
