#include "Header.h"



int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i, index = 0, t;
    for (i = 0; i < numsSize; i++) {
        t = abs(nums[i]) - 1;
        nums[t] = abs(nums[t]) * -1;
    }
    printArray(nums, numsSize);


    t = 0;
    for (i = 0; i < numsSize; i++)
        if (nums[i] > 0)
            nums[t++] = i+1;

    *returnSize = t;
    return nums;
         
}

///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
//    int* newTab = calloc(numsSize, sizeof(int));
//    int i, index = 0;
//    for (i = 0; i < numsSize; i++)
//        newTab[nums[i] - 1]++;
//
//    for (i = 0; i < numsSize; i++)
//        if (newTab[i] == 0)
//            newTab[index++] = i + 1;
//    *returnSize = index;
//    return newTab;
//}

//void main() {
//    int test[] = { 4, 3, 2, 7, 8, 2, 3, 1 };
//    int r = 0;
//    int res = findDisappearedNumbers(test, 8, &r);
//    printArray(test, r);
//}