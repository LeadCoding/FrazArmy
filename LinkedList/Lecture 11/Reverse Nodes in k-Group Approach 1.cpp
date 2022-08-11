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

/* In Approach - 1, we will be using Extra Space of Recursive Stack to Reverse Nodes in Groups of K
In this solution, we will be Reversing Nodes in groups of K and ask our Recursive function to do rest of the Task.
Our Base Case will be when our head becomes NULL or our head is at the Last Node, in that case, we will simply return head without moving further
After Recursive function gives us our newHead, we will swap the Nodes from Start Pointer to End Pointer using our Iterative version of Reversing a Linked List
*/

class Solution {
private :

// reverse(start , end) takes two pointers - Start and End and reverses the LinkedList from Start till End
// reverse() function uses our iterative approach to Reverse the Linked List
    
void reverse(ListNode *s , ListNode *e)
{
    // To reverse, we initalise 3 pointers:-
    // a) Previous(p) points to NULL
    // b) Current(c) points to Start
    // c) Next(n) points to the Next Node of Start
    
    ListNode *p = NULL ;
    ListNode *c = s ;
    ListNode *n = s -> next ;
    
    // We will stop when our Previous(p) pointer becomes equal to our End Pointer
    
    while(p != e)
    {
        // We make Current's Next point to Previous 
        
        c -> next = p ;
        
        // We make Previous move to Current and Current moves to Next
        
        p = c ;
        c = n ;
        
        // Next moves to it's next node unless it's pointing to NULL
        if(n != NULL)
            n = n -> next ;
    }
    
}
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    
    // Our Base Cases will be if head is NULL OR if head is at the Last Node OR if K is equal to 1
    // In all 3 cases, we don't need to reverse the LinkedList, so we return head
        
    if(head == NULL || head -> next == NULL || k == 1)
        return head ;
    
    // Otherwise, we make our Start point to head
    ListNode *s = head ;
    
    // Our End also points to head initially
        
    ListNode *e = head ;
     
    // We need End point to (k - 1)th Node [we are considering 1-based indexing]
        
    int inc = k - 1 ;
    
    // Our While Loop runs till inc becomes equal to 0
        
    while(inc--)
    {
        // We make our End pointer move to the Next Node
        
        e = e -> next ;
        
        // If at any moment, our End pointer becomes equal to NULL, it indicates the part of the LinkedList we are reversing is less than K, so we don't need to Reverse it, thus we directly return head
        
        if(e == NULL)
            return head ;
    }
        
    // We ask Recursion to reverse rest of the LinkedList in groups of K from End's next node
        
    ListNode *newHead = reverseKGroup(e -> next , k) ;
    
    // After recursion has done it's work, we reverse the LinkedList starting from Start till End
        
    reverse(s , e) ;
     
    // At the end, our Start pointer's next should point to our newHead given to us by Recursion
        
    s -> next = newHead ;
      
    // Our End pointer will be our New-Head so we return End pointer
        
    return e ;
    
}
};

/*
Time  Complexity: O(N)
Space Complexity: O(N / K) { Recursive Stack Space }
*/
