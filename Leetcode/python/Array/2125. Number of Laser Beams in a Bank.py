from typing import List


def count(string) -> int:
    cpt = 0
    for l in string:
        if l == "1":
            cpt += 1
    return cpt


class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        index = 0

        last_count = count(bank[0])
        total_count = 0
        for index in range(1, len(bank)):
            ...
            current_count = count(bank[index])
            if current_count > 0:
                total_count += last_count * current_count
                last_count = current_count
        return total_count


if __name__ == "__main__":
    s = Solution()
    assert s.numberOfBeams(["011001", "000000", "010100", "001000"]) == 8
