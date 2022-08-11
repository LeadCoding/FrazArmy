# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

'''In this problem, we are given the reference to the Node which is to be deleted
Since, we cannot go back to the previous Node in any way and it is guaranteed that the given Node will never be a Tail Node,
Thus, we store Node -> next in temp2 and we swap the data / val of given Node with next Node, and make Node -> next point to Node -> next -> next.
Lastly, we delete temp2
'''

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        while node.next: #checking whether next node is None or not
            # if it is not None then make its value  copy to current Node
            # In this Approach We are not using any temporary Node to copy the data 
            node.val = node.next.val 
            if node.next.next == None:
                node.next = None
                break
            node = node.next # shift the node pointing to current to current->next in each iteration  
        
    
'''
Time Complexity:  O(1)
Space Complexity: O(1)

'''        
        
