from typing import List

class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:

        array = []
        word = ''

        end = len(text)
        actual_pos = 0
        third_is_first = False

        while actual_pos < end:

            if word != first:
                (word, actual_pos) = self.getNextWord(text, actual_pos)

            if word == first:
                (word, actual_pos) = self.getNextWord(text, actual_pos)
                if word == second:
                    (word, other) = self.getNextWord(text, actual_pos)

                    if len(word) != 0:
                        array.append(word)

        return array


    def getNextWord(self, sentence, start_pos) -> tuple:

        word = ''
        for i in range(start_pos, len(sentence)):
            if sentence[i] == ' ':
                if len(word) != 0:
                    return (word, i)
            else:
                word += sentence[i]

        return (word, len(sentence))

