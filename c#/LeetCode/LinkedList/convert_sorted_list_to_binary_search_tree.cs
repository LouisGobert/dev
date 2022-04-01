using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode
{
    class convert_sorted_list_to_binary_search_tree
    {
        public TreeNode SortedListToBST(ListNode head)
        {

            if (head == null)
                return null;
            else if (head.next == null)
                return new TreeNode(head.val);
                
            int len = 0;
            ListNode headTemp = head;
            TreeNode root = new TreeNode(), rootTemp = root;

            while (head != null)
            {
                head = head.next;
                len++;
            }

            // Go to middle
            head = headTemp;

            ListNode reversed = head, temp;
            int i = 0;


            while (reversed != null && reversed.next != null && i < (len / 2)-1)
            {
                temp = reversed.next;

                if (reversed.next.next != null)
                    reversed.next = reversed.next.next;
                else
                    reversed.next = null;


                temp.next = head;
                head = temp;
                i++;
            }

            headTemp = head;
            reversed = reversed.next;
            root.val = reversed.val;

            // Put all to the right
            while (reversed.next != null)
            {
                reversed = reversed.next;
                root.right = new TreeNode(reversed.val);
                root = root.right;
             
            }

            // Put the left
            head = headTemp;
            root = rootTemp;
            while (head.val != rootTemp.val)
            {
                root.left = new TreeNode(head.val);
                root = root.left;
                head = head.next;
            }

            return rootTemp;
        }
    }
}
