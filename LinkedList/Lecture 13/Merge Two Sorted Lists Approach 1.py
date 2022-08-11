# Aprroach - 1
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

"""
Merging Two Sorted LinkedList, can be solved in 2 ways:
a) By re-arranging the same nodes present in List1 and Lsit2
b) By creating a 3rd LinkedList which contains the Elements of both List1 & List2 in Sorted Order

We will be using the Same Existing Nodes only to create the Merged LinkedList

In the Recursive Solution, We will do the small task and ask recursion to do rest of the task
This means, we will compare the values of both List1 & List2 and whichever value is smaller, we will take that Node as a part of our Sorted LinkedList
After that, we will ask Recursion to do rest of the task & the Sorted List returned by Recursion will be attached to our Selected Node's Next



"""

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        
        # if list 1 is not there, then simply return list 2
        if not list1:
            return list2
        
        # if list2 is not there then return list1
        if not list2:
            return list1
        """
             If both are Non-NULLS, we compare the value pointed at by l1 and l2
             If l1's value is smaller, we will choose l2
             Else we will choose l2
             If the values are same, we can choose from either List1 or List2
    
             If l1's value is smaller than l2
            """
        if list1.val < list2.val:
            list1.next = self.mergeTwoLists(list1.next,list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1,list2.next)
            return list2
        '''
                 We pick the node pointed by l1 and ask recursion to do rest of the task
                 We attach the sorted list to L1's Next and return l1
                '''
                
        '''
                We pick the node pointed by l2 and ask recursion to do rest of the task
                We attach the sorted list to L2's Next and return l1
                '''
                
        '''
        Time Complexity:  O(M + N) { M is the Number of Nodes in List1 , N is the Number of Nodes in List2 }
        
        Space Complexity: O(M + N) { Auxillary Stack Space }
        '''
                
        
        
