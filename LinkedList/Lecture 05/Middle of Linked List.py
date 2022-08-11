# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
''' In 1st Approach, we will count the Number of Nodes present inside the Linked-List.
Lastly, we will use another While Loop which will run till (N / 2) times. 
And the Node where it will stop will be our Middle of LinkedList

'''
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # N will store the number of Nodes present in the Linked List
        n = 0
        # We always use a temp pointer so that our head pointer doesn't get lost
        temp = head
        while temp != None:
            n+=1
            temp = temp.next
        # Again we Assign head to temp for thr second iteration
        temp = head
        half = n//2
        # Second While Loop runs till half is greater than 0
        while half:
            temp = temp.next
            half-=1
        #  At the end our temp Node will be pointing to the middle of the Linked List
        return temp
'''
Time Complexity:  O(N) { Two iterations are used }
Space Complexity: O(1)
'''    
            
        
