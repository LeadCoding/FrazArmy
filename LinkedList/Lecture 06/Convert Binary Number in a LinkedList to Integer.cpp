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

/* We are standing at the Head of the Linked-List consisting of only 0 and 1. We need to return the corresponding decimal number after converting the Binary Linked-List to Decimal
We can do this in a single traversal only. 
Everytime we stand at a Node, we assume that it is the Last Node and we add it's value to our ans varible
Again, when we encounter another Node, we increment all the powers of the previous Nodes by 1, that is, multiplying our ans by 2
*/

class Solution {
    
public:
    int getDecimalValue(ListNode* head) {
     
    // ans will store our Final Decimal Number after traversing the given LinkedList
        
    int ans = 0 ;
        
    // We move with temp so that it doesn't get lost
        
    ListNode *temp = head ;
        
    while(temp != NULL)
    {
        // Everytime we encounter a Node, we multiply ans by 2 to increment the power of all the previously encountered Nodes by 1
        
        ans *= 2 ;
        
        // We add the data present in temp Node to our ans variable
        
        ans += (temp -> val) ;
        
        // We move temp to the Next Node
        
        temp = temp -> next ;
    }
       
    // At the end, we return ans which contains our Decimal Number
        
    return ans ;
}
};

/*
Time Complexity:  O(N)
Space Complexity: O(1)
*/
