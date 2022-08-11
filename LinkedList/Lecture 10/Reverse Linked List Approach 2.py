# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

"""
To reverse a LinkedList recursively, we need to design a Recursive function reverse(head) which takes the head of the Head of the intial LinkedList and returns the Head of the Reversed LinkedList
We will just reverse Two Nodes & ask recursion to do rest of the Task
We will just change Reverse Two Nodes: head and the Node next to head
To reverse, we will make head -> next -> next to point to head
After that, we will return the Reversed-Head given to us by LinkedList
We will stop when we are at the Last Node because a Single Node cannot be Reversed


"""
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        def reverse(head):
            # Base Condition
            if head.next == None:
                return head
            
            # Ask Recursion to return head
            reverseHead = reverse(head.next)
            # Reverse the Adjascent Nodes that is, Head & Head's next Node
            head.next.next = head
            head.next = None
            
            # Returns the Reversed Head at the end
            return reverseHead
        # If head is Equal to NULL, we don't have a LinkedList to reverse, so we directly return NULL
        if head == None:
            return None
        # Otherwise we return the Reversed-Head given to us by the Recursive function reverse()
        return reverse(head)
    
    
"""
Time Complexity:  O(N)
Space Complexity: O(N) { Auxillary Stack Space of Recursion }

"""        
