# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


"""
To check if the LinkedList is Palindrome or Not, firstly, we need to reach the Middle of the LinkedList using our Slow and Fast pointers approach.
After that, Slow pointer points to the Node just before the Middle of the Linked-List. 
We reverse the LinkedList from Middle of the Linkedlist. 
And then we have 2 pointers - Start & Mid. Mid points to Middle of the LinkedList(now reversed) & Start point to the Head of the LinkedList.
Before returning, we revert the same Linkedlist.

"""
class Solution:
    
    def reverse(self,head):
        if head  == None:
            return head
        
        # We need 3 pointers to reverse the LinkedList - Previous,Current and Next
        # Initailly , Previous points to None
        
        p = None
        
        # current points to head
        c = head
        
        # Next points to head->next
        
        n = head.next
        
        # We use the same logic to reverse the linked list as we did in lecture 10
        
        while c != None:
            c.next = p
            p = c
            c = n
            
            if n != None:
                n = n.next
                
        return p
    
    def Print(self,head):
        while head:
            print(head.val)
            head = head.next
            
        
        
        
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        
        slow = head
        fast = head
        
        """
         We need Slow to point to a Node just before the Middle-most Node of the LinkedList
        That's why we make Fast move to the Second Last Node of the LinkedList only
        
        """
        while fast.next != None and fast.next.next != None:
            slow = slow.next
            fast = fast.next.next
        
        """
        Slow pointer is now at the Node just before Middle Of the LinkedList
        We need to reverse the LinkedList from the Middle Of the LinkedList,that is, Slow's Next Node
         We need to attach the Reversed List into Slow's Next
        
        """    
        slow.next = self.reverse(slow.next)
        
        """
        After reversing, we will check if the LinkedList is Palindrome or not using 2 pointers - Start and Mid
        Start will begin from Head and Mid will start from Slow's Next
        If at any moment, there's value doesn't match, we can directly return false
        Otherwise, we will keep moving them. If at any moment, Mid becomes NULL, it means the LinkedList is Palindrome, so before moving, we again make the Original Connections and return true
        
        """
        start = head
        mid = slow.next
        
        while mid != None:
            
            # If the Value pointed by Mid and Start are not same, then the LinkedList is not Palindrome
            
            if mid.val != start.val:
                return False
            start = start.next
            mid = mid.next
        
        """
        Print() function will print the LinkedList (just for understanding purpose)
        print(head) ;
        
        If we have come out of the While Loop, it means the LinkedList is definetly Palindrome
        Before returing true, we make the Original LinkedList
        
        slow -> next = reverseList(slow -> next) ;
        
        """
        
        
        return True
    
"""
Time Complexity:  O(N)
Space Complexity: O(1)


"""    
            
        
        
