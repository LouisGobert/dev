using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class partition_list
    {
        public ListNode Partition(ListNode head, int x)
        {

            if (head == null)
                return null;

            ListNode headTemp = head, nextTemp = head, previousCorrect;


            if (head.val >= x)
            {
                // Start --> find the first point less than x
                while (head.next != null && head.next.val >= x)
                    head = head.next;

                // If we are at end, no partition
                if (head.next == null)
                    return headTemp;

                // Set the first real head

                /*
                 
                4  -->  |3|  --> 2  -->  5  -->  2

                ==

                2  -->  4  --> 3  -->  5  -->  2
                 
                 */
                nextTemp = head.next;
                head.next = head.next.next;
                nextTemp.next = headTemp;

                headTemp = nextTemp;

            }

            head = headTemp;
            previousCorrect = head;
           // head = head.next;
            while (head != null && head.next != null)
            {
                if (head.next.val < x)
                {
                    if (head.val >= x)
                    {
                        nextTemp = head.next;
                        head.next = head.next.next;

                        ///ICCIICCI
                        nextTemp.next = previousCorrect.next;
                        previousCorrect.next = nextTemp;
                    } else
                    {
                        head = head.next;
                    }
  
                  
                    previousCorrect = previousCorrect.next;

                } else 
                {
                    head = head.next;
                }
            }
            return headTemp;
        }
    }
}
