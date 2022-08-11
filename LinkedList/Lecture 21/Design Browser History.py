"""
We will use Doubly Linked List (history) to move forward and backward while designing our browser history.
To solve the question, we need to store all the Pages / URLs (strings) which we have visited till now.
This can easily be acheived by storing all the Pages / URls (strings) we have visited in a Doubly Linked List.
To iterate over the Doubly Linked List, we require an iterator (it) which initally points to the head of the LinkedList.


We need to implement the following functions:
a) BrowserHistory(string homepage) --> Insert homepage into our Doubly LinkedList and make iterator it point to it

b) void visit(string url) --> It establishes a new link between the current Page(URL) and the given URL and deletes all the previous connections of Current Page

c) string back(int steps) --> Returns the page we visited after moving back 'n steps' from Current Page

d) string forward(int steps) -->Returns the page we visited after moving forward 'n steps' from Current Page

"""

# Firstly we have cretaed a doublyLinked list using class  

class DoublyLinkedList:
    def __init__(self, url: str, prev_page=None, next_page=None):
        self.page = url           # page as similar as to node.val
        self.prev_page = prev_page # This prev_page refrence variable is as similar as to the  list->prev
        self.next_page = next_page  # similarly this next_page is similar to node->next
        
class BrowserHistory:

    # Doubly LinkedList History keep track of the URLs(strings) we have visited till now
    
    def __init__(self, homepage: str):
      # Doubly LinkedList History keep track of the URLs(strings) we have visited till now
 
        self.history = DoublyLinkedList(homepage)

    def visit(self, url: str) -> None:
        place = DoublyLinkedList(url, self.history)
        self.history.next_page = place
        self.history = self.history.next_page
        

    def back(self, steps: int) -> str:
        """
         We need to go back to the Page by moving the given number of steps back
        /But we need to make sure we don't go beyond the First Node (pointed by history.prev
        
        """
        
        while steps > 0 and   self.history.prev_page is not None:
            steps -= 1
            self.history = self.history.prev_page
         
        #  After we have moved the given number of steps backward, we return the string by de-referencing It

        return self.history.page

    def forward(self, steps: int) -> str:
        """
        We need to go back to the Page by moving the given number of steps forward
        But we need to make sure we don't go beyond the Last Node 
         --history points to the Last Node of our Doubly LinkedList
        
        """
        
        while steps > 0 and self.history.prev_page is not None:
            steps -= 1
            self.history = self,history.next_page
            
        return self.history.page
    
    
    
    
    
    
"""
Time Complexity:  O(N)
Space Complexity: O(1)

"""    
