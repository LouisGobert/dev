class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        start = 0
        end = len(nums) -1


        while start <= end:
            midle = start + ((end - start) // 2)
            if nums[midle] == target:
                return midle
            else:
                if nums[midle] < target:
                    if midle+1 > end:
                        return midle+1
                    elif nums[midle+1] > target:
                        return midle+1
                    start = midle+1
                else:
                    if midle-1 < start:
                        return midle
                    elif nums[midle-1] < target:
                        return midle
                    end = midle -1

        return midle
