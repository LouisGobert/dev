using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode.Array
{
    class missing_number
    {

        public static int MissingNumber(int[] nums)
        {
            int total = 0, i, counted = 0, len = nums.Length;
            for (i = 0; i < len; i++)
            {
                counted += i+1;
                counted -= nums[i];
            }

            return counted;
        }
    }
}
