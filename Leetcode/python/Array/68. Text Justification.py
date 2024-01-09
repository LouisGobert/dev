from typing import List


def justify(array: list[list[str]], width: int) -> list[str]:
    justified: list[str] = []
    for index, line in enumerate(array):
        if len(line) == 1:
            justified.append(f"{line[0]}{' ' * (width - len(line[0])  )}")
            continue
        if index + 1 == len(array):
            full_strings = " ".join(line)
            justified.append(f"{full_strings}{ ' ' * (width - len(full_strings))}")
            continue

        normal_space = len(line) - 1
        all_word_len = 0
        for word in line:
            all_word_len += len(word)

        extra_space = width - (all_word_len + normal_space)
        line_strings = (" " * ((extra_space // (len(line) - 1)) + 1)).join(line)
        if extra_space % normal_space != 0:
            ...
            new_string = ""
            extra_to_add = extra_space % normal_space
            for index, letter in enumerate(line_strings):
                if extra_to_add != 0 and letter == " ":
                    new_string += " "
                    extra_to_add -= 1
                new_string += letter
            line_strings = new_string
        # line_strings += f"{word} "
        justified.append(line_strings)

    return justified


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        array: list[list] = []

        line = []
        cur_lenght = 0
        for word in words:
            if cur_lenght + len(word) > maxWidth:
                array.append(line)
                line = []
                cur_lenght = 0

            cur_lenght += len(word) + 1
            line.append(word)
        array.append(line)

        return justify(array, maxWidth)


if __name__ == "__main__":
    s = Solution()
    assert s.fullJustify(["This", "is", "an", "example", "of", "text", "justification."], 16) == [
        "This    is    an",
        "example  of text",
        "justification.  ",
    ]

    assert s.fullJustify(
        [
            "Science",
            "is",
            "what",
            "we",
            "understand",
            "well",
            "enough",
            "to",
            "explain",
            "to",
            "a",
            "computer.",
            "Art",
            "is",
            "everything",
            "else",
            "we",
            "do",
        ],
        20,
    ) == [
        "Science  is  what we",
        "understand      well",
        "enough to explain to",
        "a  computer.  Art is",
        "everything  else  we",
        "do                  ",
    ]
