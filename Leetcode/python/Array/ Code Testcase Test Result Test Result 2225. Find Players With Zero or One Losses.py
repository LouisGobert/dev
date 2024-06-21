from typing import Dict, List


class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        defeat: Dict[int, int] = {}
        for winner, loser in matches:
            if winner not in defeat:
                defeat[winner] = 0
            if loser not in defeat:
                defeat[loser] = 0

            defeat[loser] += 1

        no_loses = []
        on_lose = []
        for user, count in defeat.items():
            if count == 0:
                no_loses.append(user)
            elif count == 1:
                on_lose.append(user)

        no_loses.sort()
        on_lose.sort()
        return [no_loses, on_lose]


if __name__ == "__main__":
    s = Solution()
    assert s.findWinners([[1, 3], [2, 3], [3, 6], [5, 6], [5, 7], [4, 5], [4, 8], [4, 9], [10, 4], [10, 9]]) == [
        [1, 2, 10],
        [4, 5, 7, 8],
    ]
