# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

"""
In Approach - 2, we will use Recursion to remove the occurrences of val(key) from the given LinkedList
Unlike in iteration, we will ask Recursion to do most of the Task. We will only do a small Task
We will ask recursion to remove all occurrences of Val from LinkedList starting from Head's Next Node and return the newHead
After that we will check if Head's Val is equal to newHead or Not.
If true, we shouldn't add Head into our LinkedList so we return newHead
Else, Value is not equal to Val(Key), so we add Head's Next to newHead and return head

"""

class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        # if head is None then dierectly return it
        
        if head == None:
            return head
        
        # Otherwise , we ask Recursion to do the task and remove all the occurences of Val(Key) starting from Head's Next Node
        head.next = self.removeElements(head.next,val)
        
        # if Head's Value is equal to Val(key)
        
        if head.val == val:
            # we store head's next in ans pointer
            ans = head.next
            
            # we delete head
            
            del head
            
            # we return Ans
            return ans
        else:
            return head
        
"""
Time Complexity:  O(N)
Space Complexity: O(N) { Auxillary Stack Space }

"""        
            
        
      
        
        
