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

        // N will store the number of Nodes present in the LinkedList

        int n=0;

        // We always use a temp pointer so that our head pointer doesn't get lost

        ListNode temp=head;

        // In the first iteration, we count the Number of Nodes present inside the LinkedList

        while(temp!=null){

            n++;

            temp=temp.next;

        }
        // We re-assign temp to head for second iteration

        temp=head;

         // We calculate half which is N / 2

        int half=n/2;

        // Second While Loop runs till half is greater than 0

        while(half-->0){

            temp=temp.next;

        }
         // At the end our temp Node will be pointing to the middle of the Linked List

        return temp;
        
    }
}


/*
Time Complexity:  O(N) { Two iterations are used }
Space Complexity: O(1)
*/
