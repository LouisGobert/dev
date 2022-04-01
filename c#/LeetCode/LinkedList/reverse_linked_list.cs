using System;
using System.Collections.Generic;
using System.Text;

namespace LeetCode.LinkedList
{
    class reverse_linked_list
    {
		public ListNode ReverseList(ListNode head)
		{
			ListNode reversed = head, temp;

			while (reversed != null && reversed.next != null)
            {
				temp = reversed.next;

				if (reversed.next.next != null)
					reversed.next = reversed.next.next;
				else
					reversed.next = null;


				temp.next = head;
				head = temp;
            }

			return head;
		}
	}
}
