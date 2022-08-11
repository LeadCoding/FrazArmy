# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


"""
To detect LinkedList Cycle, we will use the concept of Slow and Fast pointer.
We will make our Fast Pointer move with a Speed twice to that of our Slow Pointer.
If there's a Cycle in the LinkedList, then eventually our Fast Pointer will catch our Slow pointer.
Otherwise, if there's no Cycle in the LinkedList, we come out of the While Loop and return false

"""

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # Initailly , both fast and slow pointer will point to head
        fast = head
        slow = head
        
        # While Loop runs till our fst pointer does nnot None or Our Fst pointer Does not point to last node if           linked list
        
        while fast != None and fast.next != None:
            # slow pointer will move by a single node everytime
            slow = slow.next
            
            # fast will move speed twicw that of slow pointer 
            fast = fast.next.next
            
            #  If there's a Cycle in the LinkedList, then Fast and Slow pointer will eventually meet
            
            if fast == slow:
                return True
        return False
    
    """
    Time Complexity:  O(N)
    Space Complexity: O(1)
    
    """
        
            
        
        
