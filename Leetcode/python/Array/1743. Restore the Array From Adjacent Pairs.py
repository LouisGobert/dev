from collections import defaultdict
from curses import beep
from time import time
from typing import List

from git import Tree


class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        result = []

        if len(adjacentPairs) == 0:
            return []

        adj_mapping: dict[int, int] = {}
        adj_mapping_second: dict[int, int] = {}
        for to_find, p2 in adjacentPairs:
            if to_find in adj_mapping:
                adj_mapping_second[to_find] = p2
            else:
                adj_mapping[to_find] = p2
            if p2 in adj_mapping:
                adj_mapping_second[p2] = to_find
            else:
                adj_mapping[p2] = to_find

        pos = list(set(adj_mapping) - set(adj_mapping_second))
        result = [pos.pop()]
        last_number = pos.pop()
        to_find = result[-1]
        while to_find != last_number:
            to_find = result[-1]

            maps = adj_mapping if to_find in adj_mapping else adj_mapping_second
            if to_find not in maps:
                break
            next_number = maps[to_find]
            result.append(next_number)
            del maps[to_find]

            if adj_mapping_second.get(next_number) == to_find:
                del adj_mapping_second[next_number]
            elif adj_mapping.get(next_number) == to_find:
                del adj_mapping[next_number]

            # for subpair_index in range(len(adjacentPairs)):
            #     x1, x2 = adjacentPairs[subpair_index]
            #     if x1 == to_find or x2 == to_find:
            #         if x1 == to_find:
            #             result.append(x2)
            #         elif x2 == to_find:
            #             result.append(x1)
            #         adjacentPairs.pop(subpair_index)
            #         break

            # index += 1

        return result


if __name__ == "__main__":
    s = Solution()
    time_before = time()
    print("Starting")
    # assert s.restoreArray([[100000, -100000]]) == [1, 2, 3, 4]
    # assert s.restoreArray([[2, 1], [3, 4], [3, 2]]) == [1, 2, 3, 4]
    assert s.restoreArray([[4, -2], [1, 4], [-3, 1]]) == [-3, 1, 4, -2]

    print(f"Time: {time() - time_before}")
