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

/* In 1st Approach, we will count the Number of Nodes present inside the Linked-List.
Lastly, we will use another While Loop which will run till (N / 2) times. 
And the Node where it will stop will be our Middle of LinkedList
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
     
    // N will store the number of Nodes present in the LinkedList
        
    int n = 0 ;
        
    // We always use a temp pointer so that our head pointer doesn't get lost
        
    ListNode *temp = head ;
        
    // In the first iteration, we count the Number of Nodes present inside the LinkedList
        
    while(temp != NULL)
    {
        n++ ;
        
        temp = temp -> next ;
        
    }
        
    // We re-assign temp to head for second iteration
        
    temp = head ;
     
    // We calculate half which is N / 2
        
    int half = n / 2 ;
        
    // Second While Loop runs till half is greater than 0
        
    while(half--)
    {
        temp = temp -> next ;
        
    }
        
    // At the end our temp Node will be pointing to the middle of the Linked List
    
    return temp ;
}
};

/*
Time Complexity:  O(N) { Two iterations are used }
Space Complexity: O(1)
*/
