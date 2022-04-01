using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class average_of_levels_in_binary_tree
    {
        public IList<double> AverageOfLevels(TreeNode root)
        {
            if (root == null)
                return null;

            List<double> value = new List<double>();
            List<int> nbChild = new List<int>();

            value.Add(root.val);
            nbChild.Add(1);
            explore(root, value, nbChild, 0);

            // On fais la moyenne
            for (int i = 1; i < value.Count; i++)
            {
                value[i] /= nbChild[i];
            }

            return value;
        }


        // return la moyenne de ces enfant
        private static void explore(TreeNode root, IList<double> val, IList<int> nbChild, int level)
        {
            if (root.left != null)
            {
                if (nbChild.Count > level+1)
                {
                    val[level + 1] += root.left.val;
                    nbChild[level + 1]++;
                } else
                {

                    val.Add(root.left.val);
                    nbChild.Add(1);
                }

                explore(root.left, val, nbChild, level + 1);
            }

            if (root.right != null)
            {
                if (nbChild.Count > level + 1)
                {
                    val[level + 1] += root.right.val;
                    nbChild[level + 1]++;
                }
                else
                {
                    val.Add(root.right.val);
                    nbChild.Add(1);
                }

                explore(root.right, val, nbChild, level + 1);
            }

            return;
        } 
    }
}
