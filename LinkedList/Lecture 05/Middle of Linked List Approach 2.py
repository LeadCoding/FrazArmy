# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

''' 
In 2nd Approach, we don't need to count the Number of Nodes present inside the LinkedList
We will use Two Pointers - Slow and Fast
Slow will move with a Single Node every time
Fast will move with a speed double that of Slow, that is, by Moving Two Nodes everytime
When our Fast will be NULL or our Fast will be at the Last Node, then our Slow pointer will
'''
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow = head
        fast = head
        #  We will come out of the While Loop whenever we our Fast pointer becomes NULL or our Fast pointer is pointing to the Last Node
        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next
            
            # At the end, our Slow pointer will be pointing to the Middle of the LinkedList
        return slow

'''
Time Complexity:  O(N) { Only a Single iteration is used }
Space Complexity: O(1)
'''    
        
        
        
