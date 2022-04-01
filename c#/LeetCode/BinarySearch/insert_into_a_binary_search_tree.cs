using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    public class Solution
    {
        public TreeNode InsertIntoBST(TreeNode root, int val)
        {
            if (root == null)
                return new TreeNode(val);

            recursiveInsert(root, val);
            return root;
        }

        private static void recursiveInsert(TreeNode root, int val)
        {
            if (root.val > val)
            {
                if (root.left != null)
                    recursiveInsert(root.left, val);
                else
                    root.left = new TreeNode(val);
            }
            else {
                if (root.right != null)
                    recursiveInsert(root.right, val);
                else
                    root.right = new TreeNode(val);
            }
        }
    }
}
