/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

 /* This question is exactly similar to the Linked List Cycle I. Only difference is that in this problem we need to find the Node from where the cycle begins.
But our apporach remains same. We will use 2 pointers - slow & fast where fast moves with a speed double the speed of slow.
If slow and fast meet, then the LinkedList definetly contains a Cycle.
To find the starting point of tat Cycle, we will use 2 pointers again- ptr1 & ptr2
Ptr1 will start from the Head of the LinkedList, while ptr2 will start from the Slow pointer
Both ptr1 & ptr2 will move at the same time. The point where ptr1 & ptr2 meets is the Required Node
*/

public class Solution {
    public ListNode detectCycle(ListNode head) {

        // Intially, Slow & Fast pointer both will start from Head of the LinkedList
        
        ListNode slow=head;
        ListNode fast=head;

        while(fast!=null && fast.next!=null){

            slow=slow.next;
            
            // Fast Pointer moves with a speed double that speed of Slow pointer

            fast=fast.next.next;

            // If Slow & Fast pointer meets, then there's a Cycle in the LinkedList

            if(slow==fast){
                break;
            }
        }
        
        // If our Fast becomes NULL or our Fast's Next Node is NULL, it means there's No Loop in the LinkedList

        if(fast==null || fast.next==null){
            return null;
        }

        // To find the starting point of the Loop, ptr1 starts from head while ptr2 starts from slow

        ListNode ptr1=head;
        ListNode ptr2=slow;
        
        while(ptr1!=ptr2){

            // Ptr1 & Ptr2 moves with the same speed

            ptr1=ptr1.next;

            ptr2=ptr2.next;

        }

        // At the end, both Ptr1 or Ptr2 will point to the starting Node of the LinkedList Cycle / Loop


        return ptr1;
    }

}

/*
Time Complexity:  O(N)
Space Complexity: O(1)
*/
