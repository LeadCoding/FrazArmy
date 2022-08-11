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
/* In Approach - 1, we will be discussing the Recursive Solution to remove Duplicates from Sorted LinkedList.
We will check for the values of pointed by Head and Head's Next pointer.
If their values match, then we don't need to include Head in our LinkedList
Otherwise, if the values don't match, then we make Head's Next point to the New-Head pointer given to us by Recursion.
If at any moment our Head has become NULL or our Head's Next is pointing to NULL, that is, we are standing on the Last Node, in that scenario, we will simoly return Head without moving further
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
    // If our Head is NULL , OR , Head's Next is pointing to NULL, we then directly return Head
        
    if(head == NULL || head -> next == NULL)
       return head ;
      
    // We ask Recursion to remove all Duplicates starting from Head's Next
        
    ListNode *newHead = deleteDuplicates(head -> next) ;
     
    // If the values pointed by Head and newHead(given to us by Recursion) are same, we don't need to add Head into our new Sorted LinkedList without any Duplicates, so we directly return newHead
        
    if(head -> val == newHead -> val)
        return newHead ;
     
    // Otherwise, their values don't match, so we need to include Head into our Linkedlist. So we make Head's Next point oto newHead and we return head 
        
    else
    {
        head -> next = newHead ;
        
        return head ;
    }
    
}
};

/*
Time Complexity:  O(N) { N is the Number of Nodes present in Linkedlist }
Space Complexity: O(N) { Auxillary Recursive Stack Space }
*/
