# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

"""
 This question is exactly similar to the Linked List Cycle I. Only difference is that in this problem we need to find the Node from where the cycle begins.
But our apporach remains same. We will use 2 pointers - slow & fast where fast moves with a speed double the speed of slow.
If slow and fast meet, then the LinkedList definetly contains a Cycle.
To find the starting point of tat Cycle, we will use 2 pointers again- ptr1 & ptr2
Ptr1 will start from the Head of the LinkedList, while ptr2 will start from the Slow pointer
Both ptr1 & ptr2 will move at the same time. The point where ptr1 & ptr2 meets is the Required Node

"""


class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        # Intially, Slow & Fast pointer both will start from Head of the LinkedList
        slow = head
        fast = head
        
        # Loop till Fast or Fast's next not None
        while fast != None and fast.next != None:
            slow = slow.next
            
            # Fast pointer moves with  speed double that of slow pointer 
            fast = fast.next.next
            
            # if slow and Fast pointer meets, then there's a Cycle in the LinkedList
            
            if slow == fast:
                break
           
        # If our Fast becomes NULL or our Fast's Next Node is NULL, it means there's No Loop in the LinkedList
        if fast == None or fast.next == None:
            return None
        # To find the starting point of the Loop, ptr1 starts from head while ptr2 starts from slow
        ptr1 = head
        ptr2 = slow
        
        while ptr1 != ptr2:
            
            # ptr1 and ptr2 moves with same speed
            ptr1 = ptr1.next
            ptr2 = ptr2.next
            
       #  At the end, both Ptr1 or Ptr2 will point to the starting Node of the LinkedList Cycle / Loop
        return ptr1
    
"""
Time Complexity:  O(N)
Space Complexity: O(1)

"""    
           
