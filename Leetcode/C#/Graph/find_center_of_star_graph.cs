using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace LeetCode.Graph
{
    class find_center_of_star_graph
    {

        public static int FindCenter(int[][] edges)
        {

            int[] edge0 = edges[0];
            int[] edge1 = edges[1];

            if (edge0[0] == edge1[0] || edge0[0] == edge1[1])
                return edge0[0];
            return edge0[1];

            Dictionary<int, int> count = new Dictionary<int, int>();
                     key  cpt

            for (int i = 0; i < edges.Length; i++)
            {
                if (count.ContainsKey(edges[i][0]))
                    count[edges[i][0]]++;
                else
                    count.Add(edges[i][0], 1);

                if (count.ContainsKey(edges[i][1]))
                    count[edges[i][1]]++;
                else
                    count.Add(edges[i][1], 1);
            }

            // find max
            int max = 0;
            int max_key = 0;

            IDictionaryEnumerator enumerator = count.GetEnumerator();
            while (enumerator.MoveNext())
            {
                if (max < (int)enumerator.Value)
                {
                    max = (int)enumerator.Value;
                    max_key = (int)enumerator.Key;
                }

            }
            return max_key;
        }
    }
}
