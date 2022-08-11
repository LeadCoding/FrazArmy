# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

'''
To reverse a LinkedList iteratively, we require 3 pointers - Previous(p) , Current(c) and Next(n)
Previous pointer will be initially pointing to NULL
Current pointer will be  intially pointing  to head
Next pointer will be initally pointing to head -> next
Our While Loop runs till our Current Pointer becomes NULL
Everytime we will make Current Pointer's next point to Previous Pointer
And then move Previous to Current , Current to Next and Next to it's Next Node(if it exists)

'''
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        #  If head is Equal to None, we don't have a LinkedList to reverse, so we directly return None
        if head == None:
            return None
        # Previous variable(p) initially points to None
        p = None
        # Current variable(c) initially points to head
        c  = head
        
        # Next refrence variable(n) initally points to head -> next
        
        n = head.next
        
        #Our Loop runs till Current  becomes Not Equal to None
        while c is not  None:
            c.next = p
            # We move Previous to Current 
            p = c
            # Current moves to Next 
            c = n
            # Next refrence variable to it's next node
            if n != None:
                n = n.next
                
                
        
        return p

"""
Time Complexity:  O(N)
Space Complexity: O(1)
"""    
        
