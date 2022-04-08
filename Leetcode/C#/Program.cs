using System;
using System.Collections.Generic;


namespace LeetCode
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] t1 = { 2, 1, 1 };
            int[] t2 = { 2, 3, 1 };
            int[] t3 = { 3, 4, 1 };
            int[][] times = { t1, t2, t3 };

        
            Graph.find_center_of_star_graph.FindCenter(times);

        }
    }
}
