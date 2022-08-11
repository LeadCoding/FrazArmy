# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

'''
 We are standing at the Head of the Linked-List consisting of only 0 and 1. We need to return the corresponding decimal number after converting the Binary Linked-List to Decimal
We can do this in a single traversal only. 
Everytime we stand at a Node, we assume that it is the Last Node and we add it's value to our ans varible
Again, when we encounter another Node, we increment all the powers of the previous Nodes by 1, that is, multiplying our ans by 2

'''
class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        # ans will store our final decimal number after traversing the given LinkedList
        
        ans = 0
        temp = head
        while temp != None:
            # Everytime we encourage a Node, we multiply ans by 2 to increment the power of all 
            ans*=2
            
            # we add the data presentin temp Node to our ans variable
            ans+=(temp.val)
            temp = temp.next
        return ans
'''
Time Complexity:  O(N)
Space Complexity: O(1)

'''
            
        
        
        
