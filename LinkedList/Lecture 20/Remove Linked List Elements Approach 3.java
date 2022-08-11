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

 /* In Approach - 3, we will again use Recursion to remove the occurrences of val(key) from the given LinkedList.
All our logic remains the same, but our code becomes more compact and clean (3 - liner code)
*/

class Solution {
    public ListNode removeElements(ListNode head, int val) {
        // If head is null, wr directly return null
        
        if(head == null)
            return null ;
        
        // We ask recursion to do rest of the task
        
        head.next =  removeElements(head.next , val) ;
        
        // We make our code more compact using Ternary Operator 
        // The Logic still remains the same. Only difference is that we are not actually deleteing the Head Node if it's Value is equal to Val(Key)
        
        return head.val == val? head.next : head ;
        
    }
}

/*
Time Complexity:  O(N)
Space Complexity: O(N) { Auxillary Stack Space }
*/
