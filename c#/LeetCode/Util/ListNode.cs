using System;
using System.Collections.Generic;
using System.Text;


/*
 
            // ListNode l4 = new ListNode(8, null);
            ListNode l3 = new ListNode(2, null);
            ListNode l2 = new ListNode(1, l3);
            ListNode l1 = new ListNode(1, l2);


           // ListNode i4 = new ListNode(7, null);
            ListNode i3 = new ListNode(2, null);
            ListNode i2 = new ListNode(2, i3);
            ListNode i1 = new ListNode(1, i2);

            ListNode[] lists = { i1, l1};


            merge_k_sorted_list.MergeKLists(lists);
 
 
 */

namespace LeetCode
{
    public class ListNode
    {
        public int val;
        public ListNode next;

        public ListNode(int x = 0, ListNode nextt = null) 
        { 
            val = x;
            next = nextt;
        }


        public static int GetLenght(ListNode head)
        {
            int len = 0;
            while (head != null)
            {
                head = head.next;
                len++;
            }
            return len;
        }

        public static ListNode ReverseXNode(ListNode head, int x)
        {
            ListNode reversed = head, temp;
            int x_i = 0;

            while (reversed != null && reversed.next != null && x > x_i)
            {
                temp = reversed.next;

                if (reversed.next.next != null)
                    reversed.next = reversed.next.next;
                else
                    reversed.next = null;


                temp.next = head;
                head = temp;
                x_i++;
            }

            return head;
        }
    }


}
