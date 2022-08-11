/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

 /* To reverse a LinkedList iteratively, we require 3 pointers - Previous(p) , Current(c) and Next(n)
Previous pointer will be initially pointing to null
Current pointer will be  intially pointing  to head
Next pointer will be initally pointing to head.next
Our while loop runs till our Current Pointer becomes NULL
Everytime we will make Current Pointer's next point to Previous Pointer
And then move Previous to Current , Current to Next and Next to it's Next Node(if it exists)
*/

class Solution {

    public ListNode reverseList(ListNode head) {

        // If head is Equal to null, we don't have a LinkedList to reverse, so we directly return null

        if (head == null) {
            return null;
        }
        // Previous pointer(p) initially points to null

        ListNode p = null;

        // Current pointer(c) initially points to head

        ListNode c = head;

        // Next pointer(n) initally points to head.next

        ListNode n = head.next;

        // Our loop runs till Current Pointer becomes not equal to null

        while (c != null) {

            // We reverse the Nodes by making Current's next pointer to Previous

            c.next = p;
            // We move Previous to Current Pointer

            p = c;
            // Current moves to Next Pointer

            c = n;
            // Next Pointer to it's Next Node(if it exists)

            if (n != null) {
                n = n.next;
            }
        }
        // At the end, our Previous Pointer will be the Head of the Reversed LinkedList

        return p;
    }
}
/*
Time Complexity:  O(N)
Space Complexity: O(1)
*/
