# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

"""
n Approach - 1, we will be using Extra Space of Recursive Stack to Reverse Nodes in Groups of K
In this solution, we will be Reversing Nodes in groups of K and ask our Recursive function to do rest of the Task.
Our Base Case will be when our head becomes NULL or our head is at the Last Node, in that case, we will simply return head without moving further
After Recursive function gives us our newHead, we will swap the Nodes from Start Pointer to End Pointer using our Iterative version of Reversing a Linked List


"""
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        
        def reverse(start, end):
            
            prev = None
            cur = start
            
            while prev != end:
                nextNode = cur.next # saved
                # break cur's next pointer
                cur.next = prev
                # update the prev pointer
                prev = cur
                # update the cur pointer
                cur = nextNode
         
        # Check if the head is None or it's next is None in that case we had to return Head
        if not head or k == 1 or not head.next:
            return head
        
        # Else crete two Dummy nodes , both of them will point to head
        start, end = head, head
        
        # here inc is the loop control variable which will keep hold on the loop termination condition
        inc = k-1
        
        while inc > 0:
            # point end Node to it's next
            end = end.next
            # decrement the inc to 1
            inc -= 1
            # check Wether the end node is None , if it is then return head
            if not end:
                return head
        
        
        # Again Call the main ReversekGroup Function with valu of end->next
        node = self.reverseKGroup(end.next, k)
        # call the reverse node function
        reverse(start, end)
        # Make start->next = node
        start.next = node
        
        return end
        
        
        
"""
Hypothesis of reverseKGroup:
return ll with reverse k grp

reverse() -> API DONE

Base case:
if if k* itr.next == None:     |   len(rem_ll) < k
    return head 

Induction:
each time reverse k grps, inc by k times

Time  Complexity: O(N)
Space Complexity: O(N / K) { Recursive Stack Space }

"""
            
        
