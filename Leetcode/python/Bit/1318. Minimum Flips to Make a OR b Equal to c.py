class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        # a_or_b = bin(a | b)[2:]
        a_bits = bin(a)[2:]
        b_bits = bin(b)[2:]
        c_bits = bin(c)[2:]

        max_lenght = max(len(a_bits), len(c_bits), len(b_bits))
        a_bits = a_bits.zfill(max_lenght)
        b_bits = b_bits.zfill(max_lenght)
        c_bits = c_bits.zfill(max_lenght)

        ops = 0
        for a_bit, b_bit, c_bit in zip(a_bits, b_bits, c_bits):
            if c_bit == "1":
                if a_bit == "1" or b_bit == "1":
                    continue
                ops += 1
            else:
                if a_bit == "1":
                    ops += 1
                if b_bit == "1":
                    ops += 1
        return ops


if __name__ == "__main__":
    s = Solution()
    assert s.minFlips(2, 6, 5) == 3
    assert s.minFlips(4, 2, 7) == 1
    assert s.minFlips(8, 3, 5) == 3

    # 2 : 0 0 1 0
    # 5 : 0 1 0 1
    # 3 : 0 0 1 0

    # 4 : 0 1 0 0
    # 2 : 0 0 1 0
    # 7 : 0 1 1 1
