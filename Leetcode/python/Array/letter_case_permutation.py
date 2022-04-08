from typing import List

class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        perm_order = []
        to_perm = []
        perm_list = []

        for i, elt in enumerate(s):
            if elt.isalpha():
                to_perm.append(i)

        if not to_perm:
            to_perm.append(s)
            return to_perm

        for i in range(2**len(to_perm)):
            perm_order.append([])

        self.get_perm_order(perm_order, len(to_perm)-1)

        new_str_temp = list(s)

        for i in range(2**len(to_perm)):
            new_str = new_str_temp
            for x in range(len(to_perm)):
                if perm_order[i][x]:
                    new_str[to_perm[x]] = new_str[to_perm[x]].upper()
                else:
                    new_str[to_perm[x]] = new_str[to_perm[x]].lower()

            perm_list.append("".join(new_str))


        return perm_list


    def get_perm_order(self, perm_order: List, index):
        """
        3
        [0, 0, 0]
        [0, 0, 1]
        [0, 1, 0]
        [0, 1, 1]
        [1, 0, 0]
        [1, 0, 1]
        [1, 1, 0]
        [1, 1, 1]
        """

        length_split = (2**(index+1))//2
        number_split = (len(perm_order))//(length_split)

        addon = 0
        for b in range(number_split):
            for i in range(length_split):
                perm_order[i+addon].append(0 if b % 2 == 0 else 1)

            addon += length_split

        if index:
            self.get_perm_order(perm_order, index-1)
