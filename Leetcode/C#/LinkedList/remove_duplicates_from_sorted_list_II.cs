using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class remove_duplicates_from_sorted_list_II
    {
        public ListNode DeleteDuplicates(ListNode head)
        {
            if (head == null)
                return null;

            ListNode lowPointer = new ListNode(), returnHead = lowPointer;

            /*
             
             
             1 -> 1 -> 1 -> 2 -> 3

             2 -> 3 
             
             */

            int actualValue;
            while (head != null)
            {
                actualValue = head.val;
                if (head.next != null && actualValue == head.next.val)
                {
                    while (head != null && head.val == actualValue)
                        head = head.next;

                } else
                {
                    lowPointer.next = head;
                    lowPointer = lowPointer.next;
                    head = head.next;
                }

            }

            lowPointer.next = null;

            return returnHead.next;
        }
    }
}
