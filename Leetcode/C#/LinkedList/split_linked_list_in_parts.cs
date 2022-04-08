using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class split_linked_list_in_parts
    {
        public ListNode[] SplitListToParts(ListNode root, int k)
        {


            /// 
            ///   A FINIR
            ///   


            int len = 0;
            ListNode headTemp = root;
            while (root != null)
            {
                root = root.next;
                len++;
            }

            root = headTemp;
            ListNode[] lists = new ListNode[k];


            // len = 10
            // k = 3
            int baseLen = len / k;
            int lenUpper = len % k;
            int upperDo = 0;
            int i, y;
            for (i = 0; i < Math.Min(k, len); i++)
            {
                lists[i] = root;
                for (y = 0; y < baseLen + ((upperDo >= lenUpper) ? 0: 1) - 1; y++)
                {
                    if (root == null)
                    {
                        y = baseLen + 2;
                        i = k;
                    }

                    root = root.next;
                    
                }
                upperDo++;

                headTemp = root;
                root = root.next;
                headTemp.next = null;
            }


            return lists;

        }
    }
}
