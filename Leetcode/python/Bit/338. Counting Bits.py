from typing import List


class Solution:
    def countBits(self, n: int) -> List[int]:
        bit_count = 0
        res = []
        next_multiplicator = 2
        last_mul = 2
        for i in range(n + 1):
            if i == 0:
                res.append(0)
                continue
            if i == next_multiplicator:
                extra = 1
                res.append(1)
                last_mul = next_multiplicator
                next_multiplicator *= 2
                continue
            if i == 1:
                extra = 1
                res.append(1)
                continue

            res.append(res[i - last_mul] + 1)

        return res


if __name__ == "__main__":
    s = Solution()
    """
    0000 0    0
    0001 1    1
    0010 1    2  =
    0011 2    3
    0100 1    4  = 
    0101 2    5
    0110 2    6 
    0111 3    7
    1000 1    8  =
    1001 2    9
    1010 2    10
    1011 3    11
    1100 2    12
    1101 3    13
    1110 3    14
    1111 4    15
   10000 1    16 =
    """
    assert s.countBits(5) == [0, 1, 1, 2, 1, 2]
    assert s.countBits(2) == [0, 1, 1]
