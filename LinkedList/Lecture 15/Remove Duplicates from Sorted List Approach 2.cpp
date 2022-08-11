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
/* In Approach - 2, we will be discussing the Iterative Solution to remove Duplicates from Sorted LinkedList.
In the iterative solution, we will using Temp pointer to iterate over the entire LinkedList. And we will stop whenever our Temp's Next become NULL, that is, we are standing at the Last Node of the LinkedList

We will check if the values of adjacent nodes , that is , value pointed by Temp & value pointed by Temp's Next are same or not.
If they are same, we will store Temp's Next Node in a Del pointer. And we make Temp's Next point to Del's Next. (If you have any issue understanding this part, please refer to the Lecture's Video or Article)
And we will delete the Del Node.
If the values are not same, in that part, we just need to move Temp to Temp's Next
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    
    // If Head is NULL , OR , Head's Next is NULL , that is, we have only One Node, in that case, we directly return Head
        
    if(head == NULL || head -> next == NULL)
        return head ;
     
    // Otherwise, we store Head into our Temp Node
        
    ListNode *temp = head ;
     
    // Our While Loop runs till Temp's Next doesn't become NULL
        
    while(temp -> next != NULL)
    {
        // If the value of Two Adjacent Nodes are same, we simply Delete Temp's Next Node
        
        if(temp -> val == temp -> next -> val)
        {
            // We store Temp's Next Node into a Del pointer
            
            ListNode *del = temp -> next ;
            
            // We make Temp's Next point to Del's Next
            
            temp -> next = del -> next ;
            
            // We simply delete Del Node
            
            delete del ;
        }
        
        // But our Temp Pointer moves only when values pointed by Temp & Temp's Next are different
        
        else
            temp = temp -> next ;
        
    }
      
    // At the end, we return Head pointing to the Head of the LinkedList
        
    return head ;
    
}
};

/*
Time Complexity:  O(N) { N is the Number of Nodes present in Linkedlist }
Space Complexity: O(1) 
*/
