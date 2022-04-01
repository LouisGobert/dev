using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode.LinkedList
{
    class merge_in_between_linked_list
    {
        public ListNode MergeInBetween(ListNode headA, int a, int b, ListNode headB)
        {

            ListNode headTemp = headA, tempNextA;

            for (int i = 0; i < a-1; i++)
            {
                headA = headA.next;
            }

            tempNextA = headA.next;
            headA.next = headB;
            while (headB.next != null)
            {
                headB = headB.next;
            }

            for (int i = a; i < b+1; i++)
            {
                tempNextA = tempNextA.next;
            }

            headB.next = tempNextA;

            return headTemp;
            
        }

    }
}
