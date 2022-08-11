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
class Solution {

    public ListNode middleNode(ListNode head) {
        
        // Slow and Fast pointers both should be initialised with head

        ListNode slow = head;
        ListNode fast = head;

        // We will come out of the while loop whenever we our Fast pointer becomes null or our fast pointer is pointing to the last node

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        // At the end, our slow pointer will be pointing to the middle of the LinkedList

        return slow;
    }
}
/*
Time Complexity:  O(N) { Only a Single iteration is used }
Space Complexity: O(1)
*/
