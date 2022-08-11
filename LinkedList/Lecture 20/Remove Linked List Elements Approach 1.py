# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
"""
In Approach - 1, we will use iteration to remove the occurrences of val(key) from the given LinkedList
We will create a Dummy Node to keep track of our new LinkedList after removing all occurrences from the given Linkedlist.
We require another point Tail to traverse the LinkedList. Tail initally points to Dummy
We move Tail till Tail is not Equal to NULL OR Tail's Next is Not Equal to NULL.
If Tail's Value is equal to Tail's Next Node's Value, we perform Deletion
Otherwise, we keep moving Tail to Next Node

"""


class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        
        # if head is None , then we dierectly Return it
        if head == None:
            return head
        # We create Dummy to keep track of the Linkedlist after removing all occurrences of Val
        
        dummy = ListNode(-1)
        dummy.next = head
        
        # Tail initially points to head
        tail  = dummy
        
        while tail != None and tail.next != None:
            
            # if Tail's Next is Equal to Val(key)
            
            if tail.next.val == val:
                
                # We make temp to tail's next node
                temp = tail.next
                tail.next = temp.next
                # And then delete temp 
                del temp
            # Else  the values are not equal , so we make tail move to tail's next node
            
            else:
                tail = tail.next
        # At the end, we return Dummy's Next which points to  LinkedList after removing all occurrences of Val(key)
        return dummy.next
    
"""
Time Complexity:  O(N)
Space Complexity: O(1)

"""    
            
                
                
        
        
