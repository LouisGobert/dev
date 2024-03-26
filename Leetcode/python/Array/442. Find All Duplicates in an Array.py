from typing import List

EMPTY = -2
SEEN_ONCE = -1
SEEN_TWICE = 0


# class Solution:
#     def findDuplicates(self, nums: List[int]) -> List[int]:
#         index = 0
#         next_index = 0
#         while index < len(nums):
#             next_val = nums[next_index]
#             if next_val >= 1:
#                 nums[next_index] = EMPTY
#             elif next_index == SEEN_ONCE:
#                 nums[next_index] = SEEN_TWICE

#             next_index = nums[next_val - 1] - 1
#             if next_index < 1 or next_val < 1:
#                 index += 1
#                 next_index = index

#         return list(filter(lambda x: x == 0, nums))


def rec(array: List[int], pos) -> None:
    next_val = array[pos]
    if next_val >= 1:
        array[pos] = EMPTY
        return rec(array, next_val - 1)
    if next_val == EMPTY:
        array[pos] = SEEN_ONCE
    elif next_val == SEEN_ONCE:
        array[pos] = SEEN_TWICE


# class Solution:
#     def findDuplicates(self, nums: List[int]) -> List[int]:
#         index = nums[0] - 1
#         nums[0] = EMPTY
#         while index < len(nums):
#             save_index = index
#             value = nums[index]
#             if value >= 1:
#                 nums[index] = SEEN_ONCE
#                 while value >= 1:
#                     new_value = nums[value - 1]
#                     nums[value - 1] = SEEN_ONCE
#                     index = new_value - 1
#                     if nums[new_value - 1] == SEEN_ONCE:
#                         nums[new_value - 1] = SEEN_TWICE
#                     value = nums[new_value - 1]

#             else:
#                 if value == EMPTY:
#                     nums[value - 1] = SEEN_ONCE
#                 elif value == SEEN_ONCE:
#                     nums[value - 1] = SEEN_TWICE
#             index = save_index + 1


#         return list(filter(lambda x: x == 0, nums))
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        for index, number in enumerate(nums):
            if number < 1:
                continue
            nums[index] = EMPTY

            while number >= 1:
                # next_number = nums[number - 1]
                next_number = nums[number - 1]
                if nums[number - 1] == SEEN_ONCE:
                    nums[number - 1] = SEEN_TWICE
                else:
                    nums[number - 1] = SEEN_ONCE
                number = next_number

        seen_count = 0
        for index, number in enumerate(nums, 1):
            if number == SEEN_TWICE:
                nums[seen_count] = index
                seen_count += 1

        return nums[:seen_count]


if __name__ == "__main__":
    s = Solution()
    assert s.findDuplicates([4, 3, 2, 7, 8, 2, 3, 1]) == [2, 3]
    """

        - On obtient 4, on reset à 0 si >= 1, sinon, on incremente et fin
        - - 
          - Enregistrement de 4
          - Suppresion de la valeur de la colonne à l'index 0
            - Enregistrement de 7
            - Changement idnex valeur 4 en -1
                - Enregistrement de 3
                - Changement idnex valeur 7 en -1
                
                
        On stock le prochain index, et on continuie
        
        4, 3, 2, 7, 8, 2, 3, 1
       -2, 3, 2, 7, 8, 2, 3, 1
       -2, 3, 2, -1, 8, 2, 3, 1
       -2, 3, 2, -1, 8, 2, -1, 1
       -2, 3, -1, -1, 8, 2, -1, 1
       -2, -1, 0, -1, 8, 2, -1, 1
       -2, -1, 0, -1, -2, 2, -1, -1
       -2, 0, 0, -1, -2, -2, -1, -1
        
    
    """
