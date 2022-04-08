from typing import List

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)):

            guess = target - numbers[i]

            res = self.binarySearch(numbers[i+1:], guess)

            if res != None:
                return [i+1, res+i+2]


    def binarySearch(self, list, val):
        l = 0
        r = len(list) - 1
        midle = 0
        while l <= r:
            midle = (r + l) // 2

            if list[midle] == val:
                return midle
            else:
                if list[midle] < val:
                    l = midle + 1
                else:
                    r = midle - 1

        return None


    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        start = 0
        end = len(nums) - 1

        while start <= end:
            midle = start + ((end - start) // 2)
            if nums[midle] == target:
                return midle
            else:
                if nums[midle] < target:
                    if midle + 1 > end:
                        return midle + 1
                    elif nums[midle + 1] > target:
                        return midle + 1
                    start = midle + 1
                else:
                    if midle - 1 < start:
                        return midle
                    elif nums[midle - 1] < target:
                        return midle
                    end = midle - 1

        return midle
        