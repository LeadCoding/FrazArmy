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
    public boolean isPalindrome(ListNode head) {
        ListNode slow=head;
        ListNode fast=head;

        // We need Slow to point to a Node just before the Middle-most Node of the LinkedList
        // That's why we make Fast move to the Second Last Node of the LinkedList only

        while(fast.next!=null && fast.next.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }

        // Slow pointer is now at the Node just before Middle Of the LinkedList
        // We need to reverse the LinkedList from the Middle Of the LinkedList,that is, Slow's Next Node
        // We need to attach the Reversed List into Slow's Next

        slow.next=reverseList(slow.next);

        // After reversing, we will check if the LinkedList is Palindrome or not using 2 pointers - Start and Mid
        // Start will begin from Head and Mid will start from Slow's Next
        // If at any moment, there's value doesn't match, we can directly return false
        // Otherwise, we will keep moving them. If at any moment, Mid becomes null, it means the LinkedList is Palindrome, so before moving, we again make the Original Connections and return true

        ListNode start=head;
        ListNode mid=slow.next;

        while(mid!=null){

            // If the Value pointed by Mid and Start are not same, then the LinkedList is not Palindrome


            if(mid.val!=start.val){
                return false;
            }
            start=start.next;
            mid=mid.next;
        }

        // If we have come out of the While Loop, it means the LinkedList is definetly Palindrome
        // Before returing true, we make the Original LinkedList
        slow.next=reverseList(slow.next);
        return true;

        
    }
    private ListNode reverseList(ListNode head){
        if(head == null)
        return null ;
    
        // We need 3 pointers to Reverse the LinkedList - Previous , Current & Next
        
        // Initally, Previous points to null
        
        ListNode p = null ;
        
        // Current points to Head
        
        ListNode c = head ;
        
        // Next point to Head's Next Node
        
        ListNode n = head.next ;
        
        // We use the same logic to reverse the linked list as we did in lecture 10
        
        while(c != null)
        {
            c.next = p ;
            
            p = c ;
            c = n ;
            
            if(n != null)
                n = n.next ;
        }
        
        return p ;

    }
}

/*
Time Complexity:  O(N)
Space Complexity: O(1)
*/
