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

        // If Head is null , OR , Head's Next is null , that is, we have only One Node, in that case, we directly return Head

        if(head==null || head.next==null){
            return head;
        }

        // Otherwise, we store Head into our Temp Node

        ListNode temp=head;

        // Our While Loop runs till Temp's Next doesn't become NULL

        while(temp.next!=null){

            // If the value of Two Adjacent Nodes are same, we simply Delete Temp's Next Node

            if(temp.val==temp.next.val){

                // We store Temp's Next Node into a Del reference
                ListNode del=temp.next;

                // We make Temp's Next point to Del's Next

                temp.next=del.next;
                
                // But our Temp Pointer moves only when values pointed by Temp & Temp's Next are different

            }else{
                temp=temp.next;
            }
        }

        // At the end, we return Head pointing to the Head of the LinkedList


        return head;
        
    }
}

/*
Time Complexity:  O(N) { N is the Number of Nodes present in Linkedlist }
Space Complexity: O(1) 
*/
