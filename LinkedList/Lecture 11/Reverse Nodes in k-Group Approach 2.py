# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

"""
In Approach - 2, we will NOT be using any extra Recursive Stack Space
To save space, we will use be using iterative approach to Reverse Nodes in Groups of K
Instead of using Start, here we will be using beforeStart which points to the Node before Start Pointer
We also need to store the End's Next in temp variable
After reversing, we just have to make:
a) beforeStart -> next = End
b) Start -> next = temp
Move beforeStart to Start & end to temp for next set of reversals

"""
class Solution:
    
    """
    reverse(start , end) takes two pointers - Start and End and reverses the LinkedList from Start till End
    reverse() function uses our iterative approach to Reverse the Linked List
    """
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        def reverse(s,e):
            
            """
            To reverse, we initalise 3 pointers:-
            a) Previous(p) points to NULL
            b) Current(c) points to Start
            c) Next(n) points to the Next Node of Start
    
            """
            p = None
            c = s
            n = s.next
            
            # WE will stop when our p equals to end
            
            while p != e:
                
                # We make currnet's next to previous pointer
                c.next = p
                
                # We make previous move to current and current move to next
                
                p = c
                c  = n
                
                # Next moves to it's next node unless it's pointing to NULL
                
                if n != None:
                    n = n.next
          
        #  If our head is equal NULL OR if our head is a Single Node or if K is equal to 1
        # In all the 3 cases, we don't need to reverse the LinkedList so we directly return head
     
        if head == None or head.next == None or k == 1:
            return head
        
        # Initally, we don't have any Node before head, so we create a Dummy Node and make beforeStart point to           it
        
        dummy = ListNode(-1)
        # We make Dummy's Next point to head, so that it becomes a part of the LinkedList
        dummy.next = head
        
        beforeStart = dummy
        
        # Our End Pointer will intially start from end
        
        e = head
        
        # i will keep traack of the number of Nodes we have Traversed
        
        i = 0
        
        while e != None:
            i+=1
            # If (i % k) is equal to 0, it means we have travesed an entire LinkedList of Length K
            
            if i%k == 0:
                # Our Start pointer will starrt from beforeStart's next
                s = beforeStart.next
                
                # We store the Next Node of End in temp pointer, so that connections can be made again
                
                temp = e.next
                reverse(s,e)
                
                #  After reversing is done, beforeStart's next should now point to End pointer
                
                beforeStart.next = e
                
                #  Start's next should point to temp(intial End's Next)
                s.next = temp
                
                # After tat, beforeStart should be moved to the place of Start Pointer 
                
                beforeStart = s
                e = temp
                
              # Else if we haven't covered the LinkedList of Length K, we make End move to it's Next Node
            else:
                e = e.next
                
        # At the end, we return Dummy's Next which will be our new head after reversing all the nodes in k group
        return dummy.next
    
"""
Time  Complexity: O(N)
Space Complexity: O(1) 

"""
        
        
              
            
            
        
