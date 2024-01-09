class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        ...
        map_one = {}
        maps_two = {}

        for index, letter in enumerate(s):
            t_letter = t[index]
            if letter not in map_one:
                if t_letter in maps_two:
                    return False
                map_one[letter] = t_letter
            if t_letter not in maps_two:
                # if letter in map_one:
                if map_one[letter] != t_letter:
                    return False
                maps_two[t_letter] = letter

            if map_one[letter] != t_letter or letter != maps_two[t_letter]:
                return False

        return True


if __name__ == "__main__":
    s = Solution()
    assert s.isIsomorphic("abb", "cff") == True
    assert s.isIsomorphic("abb", "cfh") == False
