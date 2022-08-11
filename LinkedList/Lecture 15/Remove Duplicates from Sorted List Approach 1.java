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
    public ListNode deleteDuplicates(ListNode head) {

        // If our Head is null , OR , Head's Next is pointing to NULL, we then directly return Head

        if(head==null || head.next==null){
            return head;
        }

        // We ask Recursion to remove all Duplicates starting from Head's Next

        ListNode newHead=deleteDuplicates(head.next);

         // If the values pointed by Head and newHead(given to us by Recursion) are same, we don't need to add Head into our new Sorted LinkedList without any Duplicates, so we directly return newHead

        if(head.val==newHead.val){

            return newHead;
        }

        // Otherwise, their values don't match, so we need to include Head into our Linkedlist. So we make Head's Next point oto newHead and we return head 


        else{

            head.next=newHead;

            return head;
        }
        
    }
}

/*
Time Complexity:  O(N) { N is the Number of Nodes present in Linkedlist }
Space Complexity: O(N) { Auxillary Recursive Stack Space }
*/
