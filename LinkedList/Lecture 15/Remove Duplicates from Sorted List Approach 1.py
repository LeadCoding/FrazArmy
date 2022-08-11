# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

"""
In Approach - 1, we will be discussing the Recursive Solution to remove Duplicates from Sorted LinkedList.
We will check for the values of pointed by Head and Head's Next pointer.
If their values match, then we don't need to include Head in our LinkedList
Otherwise, if the values don't match, then we make Head's Next point to the New-Head pointer given to us by Recursion.
If at any moment our Head has become NULL or our Head's Next is pointing to NULL, that is, we are standing on the Last Node, in that scenario, we will simoly return Head without moving further

"""
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        # if our head is None or Head's Next is poinitng to None,we then dierectly return Head
        if head == None or head.next == None:
            return head
        
        """ We ask Recursion to remove all duplicates starting from Head's next"""
        newHead = self.deleteDuplicates(head.next)
        # If the values pointed by Head and newHead(given to us by Recursion) are same, we don't need to add Head into our new Sorted LinkedList without any Duplicates, so we directly return newHead
        if head.val == newHead.val:
            return newHead
        else:   # Otherwise, their values don't match, so we need to include Head into our Linkedlist
            head.next = newHead
            return head
        
        """
        Time Complexity:  O(N) { N is the Number of Nodes present in Linkedlist }
        Space Complexity: O(N) { Auxillary Recursive Stack Space }

        
        """
        
        
        
