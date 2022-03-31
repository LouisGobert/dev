#include "Header.h"
//void merg(int[], int , int , int );
//void merg_s(int arr[], int l, int r)
//{
//    if (l < r)
//    {
//        int m = l + (r - l) / 2;
//
//        merg_s(arr, l, m);
//        merg_s(arr, m + 1, r);
//
//        merg(arr, l, m, r);
//    }
//}
//
//
//
//void merg(int arr[], int l, int m, int r)
//{
//    // l    -> start tab 1
//    // m    -> end tab 1 => start tab 2 + 1
//    // r    -> end tab 2
//    // pos  -> index de position dans le tableau posTab
//    int taille = r - l + 1, temp_m = m + 1, temp_r = r + 1, pos = 0, temp_l = l;
//    int* posTab = malloc(sizeof(int) * (taille));
//
//    // On incrémente m pour l'utiliser comme index de pourcour du tab 2
//    m++;
//
//    while (l != temp_m && m != temp_r)
//    {
//        if (arr[l] > arr[m]) {
//            posTab[pos] = arr[m];
//            m++;
//        }
//        else {
//            posTab[pos] = arr[l];
//            l++;
//        }
//        pos++;
//    }
//
//
//    while (l != temp_m)
//    {
//        posTab[pos] = arr[l];
//        l++;
//        pos++;
//    }
//    while (m != temp_r)
//    {
//        posTab[pos] = arr[m];
//        m++;
//        pos++;
//    }
//
//    // Change le tab en fonction de posTab
//    for (pos = 0; pos < taille; pos++)
//        arr[temp_l + pos] = posTab[pos];
//
//
//    // On désalloc le tableau
//    free(posTab);
//
//}

//int heightChecker(int* heights, int heightsSize) {
//	int* newTab = malloc(sizeof(int) * heightsSize);
//    memcpy(newTab, heights, sizeof(int) * heightsSize);
//    printArray(newTab, heightsSize);
//    merg_s(newTab, 0, heightsSize - 1);
//
//    printArray(newTab, heightsSize);
//
//    int dif = 0;
//    for (int i = 0; i < heightsSize; i++) {
//        if (newTab[i] != heights[i])
//            dif++;
//    }
//    return dif;
//}


//void main() {
//
//    int test[] = { 1, 1, 4, 2, 1, 3 };
//    int res = heightChecker(test, 6);
//}