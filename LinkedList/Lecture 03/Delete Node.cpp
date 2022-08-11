/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* In this problem, we are given the reference to the Node which is to be deleted
Since, we cannot go back to the previous Node in any way and it is guaranteed that the given Node will never be a Tail Node,
Thus, we store Node -> next in temp2 and we swap the data / val of given Node with next Node, and make Node -> next point to Node -> next -> next.
Lastly, we delete temp2
*/

class Solution {
public:
    void deleteNode(ListNode* node) {
       
    // Since it's given that Last Node will Never be Tail Node, so this condition will never be true
        
    if(node -> next == NULL)
        delete node ;
     
    // We swap the values of Node and Node's Next Node
        
    swap(node -> val , node -> next -> val) ;
    
    // We now need to delete Node's Next Node so we store that Node's address in temp2
        
    ListNode *temp2 = node -> next ;
     
    // Lastly, we need to point Node -> next with temp2 -> next(node -> next -> next)
        
    node -> next = node -> next -> next ;
        
    delete temp2 ;
    
}
};

/*
Time Complexity:  O(1)
Space Complexity: O(1)
*/
