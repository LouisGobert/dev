using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    public class check_If_all_1_s_are_at_least_length_k_places_away
    {
        public static bool KLengthApart(int[] nums, int k)
        {

            for (int i = 0, lenght = nums.Length, x; i < lenght; i++)
            {
                if (nums[i] == 1) {
                    for (x = i+1; x < i+k+1 && x < lenght; x++)
                    {
                        if (nums[x] == 1) return false;
                    }
                    i = x-1;
                }
            }

            return true;
        }
    }

}
