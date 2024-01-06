# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:


NUMBER = 5000000

IS_SUCCESS = 0
IS_BIGGER = -1
IS_LOWER = 1


def guess(num: int) -> int:
    if num == NUMBER:
        return 0
    if num > NUMBER:
        return -1
    return 1


class Solution:
    def guessNumber(self, n: int) -> int:
        lower_limit = 1
        max_limit = n

        while True:
            number = ((max_limit - lower_limit) // 2) + lower_limit
            result = guess(number)
            if result == IS_SUCCESS:
                return number

            if result == IS_BIGGER:
                max_limit = number - 1
            else:
                lower_limit = number + 1


if __name__ == "__main__":
    s = Solution()

    assert s.guessNumber(10**50) == 5000000

    NUMBER = 2
    assert s.guessNumber(2) == 2
