In this question, we have been given a Linked-List which has two pointers:
                    a) Next Pointer --> Pointing to the Next Node of the Linked-List
                    b) Random Pointer --> Points to any Random Node of the LinkedList, even NULL
                    
    We need to make a Deep Copy of LinkedList. Deep Copy refers that we need to actually copy the LinkedList
    We need to make the Deep Copy such that the Random Pointers of our new copied LinkedList should point to the Nodes where there copies were pointing initally. 
        For example - If A(Given Node) A'(New Copied Node) & A's Random pointed to B initally
                        A's random -> B
   
   In Approach - 2, we will not be using a extra Map to store the copy of every Node from the Original LinkedList. Instead, we will be modifying the existing connections only.
   For every original Node, we will make it's Next pointer point to it's Deep Copy.
   And it's Deep Copy Next pointer should point to Original Node's Next.
   For example - A(Original Node) , A'' (Deep Copy Of A) , A Next --> B
   After modification, the LinkedList will look like:
   A Next --> A'' ; 
   A'' Next -- B ; 
   To clarify further, please watch the YouTube Video. This modfications will help us to get the random pointers of every original node very easily.
/*

"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""



class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if head is None:
            return None
        #step:1- creating copies
        temp=head
        while temp is not None:
            q=temp.next
            new_node=ListNode(temp.val)
            temp.next=new_node
            new_node.next=q
            temp=q
        #step:2- setting up random pointers 
        temp=head
        while temp is not None:
            if temp.random is None:
                temp.next.random=None
            else:
                temp.next.random=temp.random.next
                
            temp=temp.next.next
        #step:3- separating original and copy linked list
        original=head
        copy=head.next
        new_head=copy
        while original!=None:
            original.next=original.next.next
            if copy.next is None:
                copy.next=copy.next
            else:
                copy.next=copy.next.next
            original=original.next
            copy=copy.next
        return new_head


"""
Time Complexity:  O(N)
Space Complexity: O(1)

"""    
