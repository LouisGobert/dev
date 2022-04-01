using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class coin_change
    {
        public int CoinChange(int[] coins, int amount)
        {
            if (amount == 0)
                return 0;


            ArrayUtils.MergeSort(coins, 0, coins.Length-1);


            int minCount = Int32.MaxValue;
            int count = 0;


            FindThatCoins(coins, amount, count, ref minCount);

            if (minCount == Int32.MaxValue)
                return -1;
            return minCount;
        }


        private static void FindThatCoins(int[] coins, int amount, int count, ref int minCount)
        {
            if (count+1 > minCount)
                return;


            for (int i = coins.Length-1; i >= 0; i--) { 
            
                if (amount - coins[i] == 0)
                {
                    
                    if (minCount > count+1)
                        minCount = count+1;

                    return;
                }
                else if (amount - coins[i] > 0)
                {
                    Console.WriteLine($"Count : {count} --> amount = {amount}");
                    FindThatCoins(coins, amount - coins[i], count + 1, ref minCount);

                    
                }

                if (count + 2 >= minCount)
                    return;
            }
        }
    }
}
