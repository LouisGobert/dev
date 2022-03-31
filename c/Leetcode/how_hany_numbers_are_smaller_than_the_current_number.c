#include "Header.h"




int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* tab = malloc(sizeof(int) * numsSize);
    int* countNumber = calloc(101, sizeof(int));
    int i;

    for (i = 0; i < numsSize; i++)
        countNumber[nums[i]]++;
    
    for (i = 1; i < 101; i++)
        countNumber[i] += countNumber[i - 1];
    


    for (i = 0; i < numsSize; i++)
        tab[i] = (nums[i] -1 < 0) ? 0 :  countNumber[nums[i]-1];


    return tab;
}

//
//void main() {
//
//    int test[] = { 5,0,10,0,10,6 };
//    int a = 0;
//    int* res = smallerNumbersThanCurrent(test, 6, &a);
//    printArray(res, a);
//
//}