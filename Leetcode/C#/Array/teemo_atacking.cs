using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode.Array
{
    class teemo_atacking
    {
        public static int FindPoisonedDuration(int[] timeSeries, int duration)
        {
            int totalTime = 0;
            int len = timeSeries.Length;
            if (len == 0) return 0;

            for (int i = 0; i < len-1; i++)
            {
                if (timeSeries[i] + duration <= timeSeries[i + 1]) totalTime += duration;
                else totalTime += timeSeries[i + 1] - timeSeries[i];
            }

            totalTime += duration;

            return totalTime;
        }
    }
}
