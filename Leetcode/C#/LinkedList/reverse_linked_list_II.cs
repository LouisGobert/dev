using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class reverse_linked_list_II
    {
        public ListNode ReverseBetween(ListNode head, int left, int right)
        {
            left--;

            if (left == 0)
            {
                return ListNode.ReverseXNode(head, right - left);
            }

            int pos = 1;
            ListNode headTemp = head, next;
            while (head != null && pos < left)
            {
                head = head.next;
                pos++;
            }

            next = head.next;
            head.next = null;

            head.next = ListNode.ReverseXNode(next, right - left);

            return headTemp;

        }
    }
}
