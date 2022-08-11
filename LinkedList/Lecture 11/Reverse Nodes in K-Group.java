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

/* In Approach - 1, we will be using Extra Space of Recursive Stack to Reverse Nodes in Groups of K
In this solution, we will be Reversing Nodes in groups of K and ask our Recursive function to do rest of the Task.
Our Base Case will be when our head becomes NULL or our head is at the Last Node, in that case, we will simply return head without moving further
After Recursive function gives us our newHead, we will swap the Nodes from Start Pointer to End Pointer using our Iterative version of Reversing a Linked List
*/

class Solution {

    public ListNode reverseKGroup(ListNode head, int k) {
        // Our Base Cases will be if head is NULL OR if head is at the Last Node OR if K is equal to 1
        //In all 3 cases, we don't need to reverse the LinkedList, so we return head
        if (head == null || head.next == null || k == 1) {
            return head;
        }
        // Otherwise, we make our Start point to head
        ListNode start = head;

        // Our End also points to head initially
        ListNode end = head;

        // We need End point to (k - 1)th Node [we are considering 1-based indexing]
        int inc = k - 1;
        // Our While Loop runs till inc becomes equal to 0
        while (inc-- > 0) {
            // We make our End pointer move to the Next Node
            end = end.next;
            // If at any moment, our End pointer becomes equal to NULL, it indicates the part of the LinkedList we are reversing is less than K, so we don't need to Reverse it, thus we directly return head
            if (end == null) {
                return head;
            }
        }
        // We ask Recursion to reverse rest of the LinkedList in groups of K from End's next node
        ListNode newHead = reverseKGroup(end.next, k);
        // After recursion has done it's work, we reverse the LinkedList starting from Start till End
        reverse(start, end);
        // At the end, our Start pointer's next should point to our newHead given to us by Recursion
        start.next = newHead;
        // Our End pointer will be our New-Head so we return End pointer
        return end;
    }

    // reverse(start , end) takes two pointers - Start and End and reverses the LinkedList from Start till End
    // reverse() function uses our iterative approach to Reverse the Linked List

    public void reverse(ListNode start, ListNode end) {
        // To reverse, we initalise 3 pointers:-
        // a) Previous(p) points to NULL
        // b) Current(c) points to Start
        // c) Next(n) points to the Next Node of Start

        ListNode prev = null;
        ListNode curr = start;
        ListNode next = start.next;
        // We will stop when our Previous(p) pointer becomes equal to our End Pointer
        while (prev != end) {
            // We make Current's Next point to Previous
            curr.next = prev;
            // We make Previous move to Current and Current moves to Next
            prev = curr;
            curr = next;
            // Next moves to it's next node unless it's pointing to NULL
            if (next != null) {
                next = next.next;
            }
        }
    }
}
/*
Time  Complexity: O(N)
Space Complexity: O(N / K) { Recursive Stack Space }
*/
