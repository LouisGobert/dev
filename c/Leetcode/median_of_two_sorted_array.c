#include "Header.h"

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    ///
    /// MERGE
    /// 
    
    int* mergeTab = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    int m1 = 0, m2 = 0, i = 0;

    while (m1 != nums1Size && m2 != nums2Size)
    {
        if (nums1[m1] > nums2[m2])
            mergeTab[i++] = nums2[m2++];
        else
            mergeTab[i++] = nums1[m1++];

    }

    while (m1 != nums1Size)
        mergeTab[i++] = nums1[m1++];

    while (m2 != nums2Size)
        mergeTab[i++] = nums2[m2++];



    printArray(mergeTab, nums1Size + nums2Size);


    /// 
    /// MEDIAN
    /// 


    if ((m1 + m2 + 1) % 2 == 0) {
        double t = mergeTab[((m1+m2+1)/2)-1];

        free(mergeTab);
        return t;
    }
    else {
        double t = (mergeTab[((m1 + m2) / 2) - 1] + mergeTab[(m1+m2)/2]);
        t /= 2;
        free(mergeTab);

        return t;
    }

}




//void main() {
//
//    int tab1[] = { 1, 3, 5 };
//    int tab2[] = {2, 4, 6};
//
//    double res = findMedianSortedArrays(tab1, 3, tab2, 3);
//
//}