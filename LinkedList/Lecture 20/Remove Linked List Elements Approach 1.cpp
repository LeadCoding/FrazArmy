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
/* In Approach - 1, we will use iteration to remove the occurrences of val(key) from the given LinkedList
We will create a Dummy Node to keep track of our new LinkedList after removing all occurrences from the given Linkedlist.
We require another point Tail to traverse the LinkedList. Tail initally points to Dummy
We move Tail till Tail is not Equal to NULL OR Tail's Next is Not Equal to NULL.
If Tail's Value is equal to Tail's Next Node's Value, we perform Deletion
Otherwise, we keep moving Tail to Next Node
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        // If head is NULL, we directly return NULL
        
        if(head == NULL)
            return NULL ;
        
        // We create Dummy to keep track of the Linkedlist after removing all occurrences of Val
        
        ListNode *dummy = new ListNode(-1) ;
        
        dummy -> next = head ;
        
        // Tail initally points to Dummy
        
        ListNode *tail = dummy ;
        
        while(tail != NULL && tail -> next != NULL)
        {
            // If Tail's Next is equal to Val(key)
            
            if(tail -> next -> val == val)
            {
                // We make Temp point to Tail's Next Node
                
                ListNode *temp = tail -> next ;
                
                tail -> next = temp -> next ;
                
                // And then delete temp
                
                delete temp ;
            }
            
            // Else the values are not equal, so we make Tail move to Tail's Next Node
            
            else
            {
                tail = tail -> next ;
            }
        }
        
        // At the end, we return Dummy's Next which points to  LinkedList after removing all occurrences of Val(key)
        
        return dummy -> next ; 
    }
};

/*
Time Complexity:  O(N)
Space Complexity: O(1)
*/
