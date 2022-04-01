using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode.LinkedList
{
    class intersection_of_two_linked_list
    {
        /**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
        public class Solution
        {
            public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
            {
                if (headA == null || headB == null)
                    return null;

                int lenA = 0, lenB = 0;
                ListNode tA = headA, tB = headB;

                while (headA.next != null)
                {
                    lenA++;
                    headA = headA.next;
                }

                while (headB.next != null)
                {
                    lenB++;
                    headB = headB.next;
                }

                headA = tA;
                headB = tB;

                if (lenA > lenB)
                {
                    for (int i = 0; i < lenA - lenB; i++)
                    {
                        headA = headA.next;
                    }
                }
                else 
                {
                    for (int i = 0; i < lenB - lenA; i++)
                    {
                        headB = headB.next;
                    }
                }

                while (headA != headB)
                {
                    headA = headA.next;
                    headB = headB.next;
                }

                return headA;
            }
        }
    }
}
