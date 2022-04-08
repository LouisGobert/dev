using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode.LinkedList
{
    class rotate_list
    {
        public ListNode RotateRight(ListNode head, int k)
        {
            if (head == null)
                return null;
            ListNode left, right, tempHead = head, newHead;

            int len = 0;
            while (head != null)
            {
                head = head.next;
                len++;
            }
            head = tempHead;

            k %= len;
            if (k == 0)
                return head;

            for (int i = 0; i < len-k; i++)
            {
                head = head.next;
            }

            newHead = head;
            while (head.next != null)
                head = head.next;

            head.next = tempHead;
            for (int i = 0; i < len - k; i++)
            {
                head = head.next;
            }
            head.next = null;


            return newHead;

        }
    }
}
