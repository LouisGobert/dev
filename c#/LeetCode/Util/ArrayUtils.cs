using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    public class ArrayUtils
    {

        public static void MergeSort(int[] arr, int l, int r)
        {
            if (l < r)
            {
                int m = l + (r - l) / 2;

                MergeSort(arr, l, m);
                MergeSort(arr, m + 1, r);

                MergeSortUtil(arr, l, m, r);
            }
        }

        private static void MergeSortUtil(int[] arr, int l, int m, int r)
        {
            int taille = r - l + 1;
            int temp_m = m + 1;
            int temp_r = r + 1;
            int temp_l = l;

            List<int> posTab = new List<int>();

            m++;

            while (l != temp_m && m != temp_r)
            {
                if (arr[l] > arr[m])
                    posTab.Add(arr[m++]);
                else
                    posTab.Add(arr[l++]);
            }

            while (l != temp_m)
                posTab.Add(arr[l++]);

            while (m != temp_r)
                posTab.Add(arr[m++]);

            for (int i = 0; i < taille; i++)
            {
                arr[temp_l + i] = posTab[i];
            }
           
        }
    }
}
