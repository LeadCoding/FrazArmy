/*
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

 /* In Approach - 2, we will use Recursion to remove the occurrences of val(key) from the given LinkedList
Unlike in iteration, we will ask Recursion to do most of the Task. We will only do a small Task
We will ask recursion to remove all occurrences of Val from LinkedList starting from Head's Next Node and return the newHead
After that we will check if Head's Val is equal to newHead or Not.
If true, we shouldn't add Head into our LinkedList so we return newHead
Else, Value is not equal to Val(Key), so we add Head's Next to newHead and return head
*/

class Solution {
    public ListNode removeElements(ListNode head, int val) {
         // If head is null, wr directly return null
        
         if(head == null)
         return null ;
     
            // Otherwise, we ask Recursion to do rest of the task and remove all the occurrences of Val(Key) starting from Head's Next Node
            
            head.next = removeElements(head.next , val) ;
            
            // If Head' Value is equal to Val(Key)
            
            if(head.val == val)
            {
                // We store Head's Next in Ans pointer
                
                ListNode ans = head.next ;                
                // We return Ans
                
                return ans ;
            }
            
            // Else, Head will be a part our LinkedList, so we return Head
            
            else
            {   
                return head ;
            }
        
    }
}
/*
Time Complexity:  O(N)
Space Complexity: O(N) { Auxillary Stack Space }
*/
