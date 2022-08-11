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


 /* Merging Two Sorted LinkedList, can be solved in 2 ways:
a) By re-arranging the same nodes present in List1 and Lsit2
b) By creating a 3rd LinkedList which contains the Elements of both List1 & List2 in Sorted Order

We will be using the Same Existing Nodes only to create the Merged LinkedList

In the iterative solution, we first check:
a) If l1 is NULL, we directly return l2
b) If l2 is NULL, we directly return l1

Otherwise both are Non-NULL. Firstly, we store the Head of our Sorted Merged LinkedList in ans pointer. This can be done simply by comparing the values of l1 and l2 and whichever is smaller we make ans pointer to it. We move l1 or l2 to it's Next Node depending on whose value is smaller.
We also require a tail pointer in order to make the Sorted LinkedList. Tail initally points to ans

We then use a While Loop which runs till both l1 & l2 don't become NULL
We compare the values pointed by l1 and l2. 
If l1's value is smaller, we make tail's Next point to l1, we move tail to l1 and l1 to its Next Node
Else l2's value is smaller than or equal to l1, so we make tail's Next point to l2, move tail to l2 and l2 to it's Next Node.

Since our Loop will terminate when either of l1 or l2 has become NULL. So we check if l1 has become NULL or Not. 
If true, we add the remaining values of l2 into our Sorted List by making tail's Next point to l2
If false, we add the remaining values of l1 into our Sorted List by making tail's Next point to l1

At the end, we return ans pointer containing the Head of our Sorted Merged LinkedList
*/


class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

         // if both list is null returning null

         if(l1 == null && l2 == null) return null;

        // If l1 is NULL, we directly return l2

         else if(l1 ==null && l2 !=null) return l2;

        // If l2 is NULL, we directly return l1

         else  if(l2 ==null && l1 !=null) return l1;


        // If both are Non-NULL, we need to prepare our Sorted Merged LinkedList
        // ans pointer keeps track of the Head of our Sorted Merged LinkedList
        // tail pointer is used to add rest of the values to our linkedList

         ListNode ans = new ListNode(-1);
         ListNode tail = ans;
         while(l1 != null && l2 != null) {          

            // If value pointed by l1 is smaller than l2's value

             if(l1.val <= l2.val){

                 // We make Tail's Next point to l1

                 tail.next = l1;

                // We move tail to l1

                 tail = l1;
                 // l1  moves to it's Next Node

                 l1 = l1.next;
             }
            // Otherwise, value pointed by l2 is smaller than or equal to l1's value

              else  if(l2.val < l1.val){

                // We make Tail's Next point to l2

                 tail.next = l2;

                // We move tail to l2

                 tail = l2;

                // l2 moves to it's Next Node

                 l2 = l2.next;                
             }
         }

        // If l1 has not become NULL, we make Tail's Next point to l1

         if(l1 != null)
             tail.next = l1;

        // Else we make Tail's Next point to l2

         else if(l2 != null)
             tail.next = l2;

        // At the end, we return Ans pointer containg the Head of our Sorted Merged LinkedList 
         
         return ans.next;
         
     }
 }

 /* 
Time Complexity:  O(M + N) { M is the Number of Nodes in List1 , N is the Number of Nodes in List2 }
Space Complexity: O(1) 
*/