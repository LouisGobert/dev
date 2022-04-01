using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class reverse_nodes_in_k_group
    {

        public ListNode ReverseKGroup(ListNode head, int k)
        {
            int len = 1;
            ListNode headTemp = head, next = null, secondNext;
            ListNode returnHead = head;

            while (head.next != null) { 
                head = head.next;
                len++;
            }

            int nbReverse = len / k;
            head = headTemp;
            
            // First reverse
            if (nbReverse-- >= 1)
            {
                
                returnHead = ListNode.ReverseXNode(head, k-1);

                next = head.next;
                if (nbReverse != 0)
                    head.next = null;
            }

            for (int i = 0; i < nbReverse; i++)
            {
                head.next = ListNode.ReverseXNode(next, k-1);
                head = next;
                next = next.next;


            }

            return returnHead;
        }
    }
}
