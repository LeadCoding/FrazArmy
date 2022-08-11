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

/* Merging Two Sorted LinkedList, can be solved in 2 ways:
a) By re-arranging the same nodes present in List1 and Lsit2
b) By creating a 3rd LinkedList which contains the Elements of both List1 & List2 in Sorted Order

We will be using the Same Existing Nodes only to create the Merged LinkedList

In the iterative solution, we first check:
a) If l1 is NULL, we directly return l2
b) If l2 is NULL, we directly return l1

Otherwise both are Non-NULL. Firstly, we store the Head of our Sorted Merged LinkedList in ans pointer. This can be done simply by comparing the values of l1 and l2 and whichever is smaller we make ans pointer to it. We move l1 or l2 to it's Next Node depending on whose value is smaller.
We also require a tail pointer in order to make the Sorted LinkedList. Tail initally points to ans

We then use a While Loop which runs till both l1 & l2 don't become NULL
We compare the values pointed by l1 and l2. 
If l1's value is smaller, we make tail's Next point to l1, we move tail to l1 and l1 to its Next Node
Else l2's value is smaller than or equal to l1, so we make tail's Next point to l2, move tail to l2 and l2 to it's Next Node.

Since our Loop will terminate when either of l1 or l2 has become NULL. So we check if l1 has become NULL or Not. 
If true, we add the remaining values of l2 into our Sorted List by making tail's Next point to l2
If false, we add the remaining values of l1 into our Sorted List by making tail's Next point to l1

At the end, we return ans pointer containing the Head of our Sorted Merged LinkedList
*/

class Solution {    

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       
    // If l1 is NULL, we directly return l2
        
    if(l1 == NULL)
        return l2 ;
      
    // If l2 is NULL, we directly return l1
        
    if(l2 == NULL)
        return l1 ;
     
    // If both are Non-NULL, we need to prepare our Sorted Merged LinkedList
    // ans pointer keeps track of the Head of our Sorted Merged LinkedList
    // tail pointer is used to add rest of the values to our linkedList
        
    ListNode *ans  = NULL ;
    ListNode *tail = NULL ;

    if(l1 -> val < l2 -> val)
    {
        ans  = l1 ;
        
        tail = l1 ;
        
        l1 = l1 -> next ;
    }
        
    else
    {
        ans  = l2 ;
        
        tail = l2 ;
        
        l2 = l2 -> next ;
    }
        
    // While Loop runs till both l1 & l2 are Non-NULL
        
    while(l1 != NULL && l2 != NULL)
    {
        // If value pointed by l1 is smaller than l2's value
        
        if(l1 -> val < l2 -> val)
        {
            // We make Tail's Next point to l1
            
            tail -> next = l1 ;
            
            // We move tail to l1
            
            tail = l1 ;
            
            // l1  moves to it's Next Node
            
            l1 = l1 -> next ;
        }
        
        // Otherwise, value pointed by l2 is smaller than or equal to l1's value
        
        else
        {
            // We make Tail's Next point to l2
            
            tail -> next = l2 ;
            
            // We move tail to l2
            
            tail = l2 ;
            
            // l2 moves to it's Next Node
            
            l2 = l2 -> next ;
            
        }
    }
        
    // After the termination of our While Loop, we need to add the remaining values into our Sorted Merged LinkedList
        
    // If l1 has become NULL, we make Tail's Next point to l2
        
    if(l1 == NULL)
        tail -> next = l2 ;
        
    // Else we make Tail's Next point to l1
        
    else
        tail -> next = l1 ;
       
    // At the end, we return Ans pointer containg the Head of our Sorted Merged LinkedList 
        
    return ans ;
    
}
};

/* 
Time Complexity:  O(M + N) { M is the Number of Nodes in List1 , N is the Number of Nodes in List2 }
Space Complexity: O(1) 
*/
