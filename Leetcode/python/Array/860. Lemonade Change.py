from collections import defaultdict
from email.policy import default
from typing import Dict, List


class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        counter: Dict[int, int] = defaultdict(int)
        for bill in bills:
            if bill == 5:
                counter[5] += 1
            elif bill == 10:
                if counter[5] == 0:
                    return False
                counter[5] -= 1
                counter[10] += 1
            elif bill == 20:
                if counter[5] >= 1 and counter[10] >= 1:
                    counter[5] -= 1
                    counter[10] -= 1
                elif counter[5] >= 3:
                    counter[5] -= 3
                else:
                    return False

        return True


if __name__ == "__main__":
    s = Solution()

    assert s.lemonadeChange([5, 5, 10, 10, 5, 20, 5, 10, 5, 5]) == True
    assert s.lemonadeChange([5, 5, 5, 10, 20]) == True
    assert s.lemonadeChange([5, 5, 10, 10, 20]) == False
    assert s.lemonadeChange([5, 5, 5, 5, 10, 5, 10, 10, 10, 20]) == True
