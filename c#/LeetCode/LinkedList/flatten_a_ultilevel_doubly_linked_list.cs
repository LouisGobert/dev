using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class flatten_a_ultilevel_doubly_linked_list
    {

       
        public Node Flatten(Node head)
        {
            if (head == null)
                return null;

            explore(head);
            return head;
            
        }

        private static Node explore(Node head)
        {
            Node tempNext;
            while (head.next != null)
            {
                if (head.child != null)
                {
                    tempNext = head.next;

                    head.next = head.child;
                    head.next.prev = head;
                    head.child = null;

                    head = explore(head.next);

                    head.next = tempNext;
                    tempNext.prev = head;

                }


                if (head.child != null)
                {

                    head.next = head.child;
                    head.next.prev = head;
                    head.child = null;

                    head = explore(head.next);

                }

                head = head.next;
            }

            return head;
        }
        
    }

    // Definition for a Node.
    public class Node
    {
        public int val;
        public Node prev;
        public Node next;
        public Node child;
    }
}
