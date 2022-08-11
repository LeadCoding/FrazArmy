# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


"""
To get the Intersection of Two LinkedLists, we will use Two pointers A & B which will initallly point to HeadA & HeadB respetively
To get the intersection point, we will simply run a While Loop. The While Loop runs A is not equal to B.
And at any moment, if A becomes NULL, we make A point to HeadB
Similarly, at any moment, if B becomes NULL, we make B point to HeadA
In this way, we can get the Intersection point of Two LinkedLists

"""
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        
        # intially, both A & B points to HeadA & HeadB respectively
        
        a = headA
        b = headB
        
        while a != b:
            
            # if A has became None, we assign it to HeadB
            
            if a == None:
                a = headB
            
            # Else we move to it's Next Node
            else:
                a = a.next
            # Similarly , if B has became None , we assign it to HeadA
            
            if b == None:
                b = headA
            # Else we move B to it's Next Node
            
            else:
                b = b.next
            
            '''
            
            At the end, A will point to NULL, if the LinkedList's don't have an Intersection Point
            Otherwise, it will point to the Intersecting Node of the LinkedList
            
            '''
        return a
"""
Time Complexity:  O(M + N)
Space Complexity: O(1)

"""    
                 
            
        
