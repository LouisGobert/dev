#include "array.h"


#include <stdio.h>



void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
   
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        
        merge(arr, l, m, r);
        //printf("\Merge result : ");
        //print_array(arr, r+1);
        
    }
}



void merge(int arr[], int l, int m, int r)
{
    // l    -> start tab 1
    // m    -> end tab 1 => start tab 2 + 1
    // r    -> end tab 2
    // pos  -> index de position dans le tableau posTab
    int taille = r - l + 1, temp_m = m + 1, temp_r = r + 1, pos = 0, temp_l = l;
    int *posTab = malloc(sizeof(int) * (taille) );

    // On incrémente m pour l'utiliser comme index de pourcour du tab 2
    m++;

    while (l != temp_m && m != temp_r)
    {
        if (arr[l] > arr[m]) {
            posTab[pos] = arr[m];
            m++;
        }
        else {
            posTab[pos] = arr[l];
            l++;
        }
        pos++;
    }
    

    while (l != temp_m)
    {
        posTab[pos] = arr[l];
        l++;
        pos++;
    }
    while (m != temp_r)
    {
        posTab[pos] = arr[m];
        m++;
        pos++;
    }

    // Change le tab en fonction de posTab
    for (pos = 0; pos < taille; pos++)
        arr[temp_l + pos] = posTab[pos];

  
    // On désalloc le tableau
    free(posTab);

}


void printArray(const int* arr, int dim) {
    for (int n = 0; n < dim; n++) 
        printf("%d ", arr[n]);   
    printf("\n");
}

void printArray2D(const int* arr, int x, int y) {
    for (int n = 0, i; n < x; n++) {
        for (i = 0; i < y; i++)
            printf("%2d ", arr[(n *y) + i]);
    printf("\n");
    }
    printf("\n");
}



   