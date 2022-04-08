using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode.Set
{
    class set_mismatch
    {        
        public static int[] FindErrorNums(int[] nums)
        {
            int len = nums.Length;
            int[] set = new int[len];
            int[] returnTab = new int[2];
            int i;
            for (i = 0; i < len; i++)
            {
                
                if (++set[nums[i] -1] == 2)
                {
                    returnTab[0] = nums[i];
                }
            }

            for (i = 0; i < len; i++)
            {
                if (set[i] == 0)
                {
                    returnTab[1] = i + 1;
                    return returnTab;
                }
            }

            return returnTab;
        }
    }
}
