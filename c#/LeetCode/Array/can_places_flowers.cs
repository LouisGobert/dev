using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class can_places_flowers
    {
        public static bool CanPlaceFlowers(int[] flowerbed, int n)
        {
            if (n == 0) return true;

            int flowrbedLen = flowerbed.Length;

            if ((flowrbedLen + 1) / 2 < n) return false;

            for (int i = 0; i < flowrbedLen; i++)
            {
                if (flowerbed[i] == 1) i++;
                else
                {
                    if ((i+1 < flowrbedLen && flowerbed[i+1] != 1) || (i+1 == flowrbedLen))
                    {
                        n--;
                        i++;
                    } 
                }

                if (n == 0) return true;
            }

            if (n == 0) return true;
            return false;
        }
    }
}
