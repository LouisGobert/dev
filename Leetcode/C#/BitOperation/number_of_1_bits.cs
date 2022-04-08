using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    public class solution
    {

        public static int HammingWeight(uint n)
        {
    
            int bitCount = 0;
        
            while (n != 0)
            {
                if ((n & 1) != 0) bitCount++;
                n >>= 1;
            }

            return bitCount;
        }
    }
}
