/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/* To reverse a LinkedList iteratively, we require 3 pointers - Previous(p) , Current(c) and Next(n)
Previous pointer will be initially pointing to NULL
Current pointer will be  intially pointing  to head
Next pointer will be initally pointing to head -> next
Our While Loop runs till our Current Pointer becomes NULL
Everytime we will make Current Pointer's next point to Previous Pointer
And then move Previous to Current , Current to Next and Next to it's Next Node(if it exists)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    
    // If head is Equal to NULL, we don't have a LinkedList to reverse, so we directly return NULL
        
    if(head == NULL)
    	return NULL ;
        
    // Previous pointer(p) initially points to NULL
        
    ListNode *p = NULL ;
        
    // Current pointer(c) initially points to head
        
    ListNode *c = head ;
    
    // Next pointer(n) initally points to head -> next
        
    ListNode *n = head -> next ;
       
    // Our Loop runs till Current Pointer becomes Not Equal to NULL
        
    while(c != NULL)
    {
        // We reverse the Nodes by making Current's next point to Previous
        
        c -> next = p ;
        
        // We move Previous to Current Pointer
        
        p = c ;
        
        // Current moves to Next Pointer
        
        c = n ; 
        
        // Next Pointer to it's Next Node(if it exists)
        
        if(n != NULL)
        n = n -> next ;
        
    }
      
    // At the end, our Previous Pointer will be the Head of the Reversed LinkedList
        
    return p ;    
}
};

/*
Time Complexity:  O(N)
Space Complexity: O(1)
*/
