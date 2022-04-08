using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode.String
{
    class delete_columns_to_make_sorted
    {
        public int MinDeletionSize(string[] strs)
        {
            int y;
            int toDelete = 0;
            for (int i = 0; i < strs[0].Length; i++)
            {
                for (y = 0; y < strs.Length-1; y++)
                {
                    if (strs[y][i] > strs[y+1][i])
                    {
                        toDelete++;
                        y = strs.Length;
                    }
                }
            }

            return toDelete;
        }
    }
}
