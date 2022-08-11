/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */


//  In this problem, we are given the reference to the Node which is to be deleted
// Since, we cannot go back to the previous Node in any way and it is guaranteed that the given Node will never be a Tail Node

class Solution {

    public void deleteNode(ListNode node) {

        // we copy the value of next node to the current node which is to be deleted.

        node.val=node.next.val;

        // After copying the value , we make the current node next to next of next of current node 
        // Suppose Linked list is 1 2 3 4 , 2 is to be delete 
        // First we will copy the 3 to 2 i.e new list will be 1 3 3 4 
        // now the first 3's  next will be 4 , here we can observe that 2 is deleted.

        node.next=node.next.next;
        
    }

}
/*
Time Complexity:  O(1)
Space Complexity: O(1)
*/