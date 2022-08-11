# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

"""
In Approach - 2, we will be discussing the Iterative Solution to remove Duplicates from Sorted LinkedList.
In the iterative solution, we will using Temp pointer to iterate over the entire LinkedList. And we will stop whenever our Temp's Next become NULL, that is, we are standing at the Last Node of the LinkedList

We will check if the values of adjacent nodes , that is , value pointed by Temp & value pointed by Temp's Next are same or not.
If they are same, we will store Temp's Next Node in a Del pointer. And we make Temp's Next point to Del's Next. (If you have any issue understanding this part, please refer to the Lecture's Video or Article)
And we will delete the Del Node.
If the values are not same, in that part, we just need to move Temp to Temp's Next

"""
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        # if head is None or Head's next is Noneso in that case return head
        if head == None or head.next == None:
            return head
        # Otherwise store Head into our temp Node
        temp = head
        # Our while Loop runs till Temp's next node does not became None
        
        while temp.next != None:
            # If the value of Two Adjacent Nodes are same, we simply Delete Temp's Next Node
            if temp.val == temp.next.val:
                # WE store temp's next Node into a del variable
                Del = temp.next
                # we make temp's next point Del's next
                temp.next = Del.next
                # we simply delete Del Node
                del Del
                
                # But our Temp Pointer moves only when values pointed by Temp & Temp's Next are different
            else:
                temp = temp.next
                # at the end we return head of the linked list
                
        return head
    
    """
    Time Complexity:  O(N) { N is the Number of Nodes present in Linkedlist }
    Space Complexity: O(1) 

    """
