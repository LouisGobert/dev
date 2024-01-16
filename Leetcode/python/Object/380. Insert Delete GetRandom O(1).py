import random
from typing import List, Set


class RandomizedSet:
    sets: List[int]

    def __init__(self):
        self.sets = []

    def insert(self, val: int) -> bool:
        if val in self.sets:
            return False
        self.sets.append(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.sets:
            return False
        self.sets.remove(val)
        return True

    def getRandom(self) -> int:
        index = random.randrange(0, len(self.sets))
        return self.sets[index]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
