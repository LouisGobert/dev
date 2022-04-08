using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class merge_k_sorted_list
    {
        public static ListNode MergeKLists(ListNode[] lists)
        {
            bool allNull = false;
            int listLen = lists.Length, i, minIndex;

            ListNode head = null, realHead = null;

            while (!allNull)
            {
                allNull = true;

                minIndex = -1;
                for (i = 0; i < listLen; i++)
                {


                    // Si une ll existe
                    if (lists[i] != null && (minIndex == -1 || lists[i].val < lists[minIndex].val))
                    {
                        allNull = false;

                        minIndex = i;
                        if (head != null && lists[minIndex].val == head.val)
                            i = listLen;

                    }
                }

                if (allNull)  return realHead;

                // On a donc la casse avec la valeur minimum
                if (head == null)
                {
                    head = lists[minIndex];
                    realHead = head;
                    lists[minIndex] = lists[minIndex].next;
                    head.next = null;
                } else
                {
                    head.next = lists[minIndex];
                    lists[minIndex] = lists[minIndex].next;
                    head = head.next;
                    head.next = null;
                }
                
            }

            return realHead;
        }
    }
}
