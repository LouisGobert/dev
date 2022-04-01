using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode.Other
{
    class network_delay_time
    {

        public static int NetworkDelayTime(int[][] times, int n, int k)
        {
            // K = starting node
            // N = number of node
            //Dictionary<int, Tuple<int, int>> graph = new Dictionary<int, Tuple<int, int>>();
            /*
             * 1 : from
             * 2 : to
             * 3 : time
             */
            /*foreach (int[] time in times)
            {
                graph.Add(time[0], Tuple.Create(time[1], time[2]));

            }*/

            //Dictionary<int, int> dist = new Dictionary<int, int>();
            int[] short_dist = new int[n];
            bool[] seen = new bool[n];
            for (int i = 0; i < n; i++)
            {
                //dist.Add(i, Int32.MaxValue);
                short_dist[i] = Int16.MaxValue;
            }
            short_dist[k-1] = 0;

            while (true)
            {
                int smal_node = -1;
                int smal_val = Int32.MaxValue, i;
                for (i = 0; i < n ; i++) {
                    if (!seen[i] && short_dist[i] < smal_val)
                    {
                        smal_node = i;
                        smal_val = short_dist[i];
                    }
                }


                if (smal_node < 0) break;

                // On a trouvé le candidat avec les moins de time
                seen[smal_node] = true;

                // On met a jour les distances
                for (i = 0; i < times.Length; i++)
                {
                    if (times[i][0]-1 == smal_node)
                        short_dist[times[i][1]-1] = Math.Min(short_dist[times[i][1]-1], short_dist[smal_node] + times[i][2]);
                }


            }

            int max =  Int32.MinValue;
            for (int i = 0; i < n; i++)
                max = Math.Max(max, short_dist[i]);

            return (max < Int16.MaxValue) ? max : -1;

        }
    }
}
