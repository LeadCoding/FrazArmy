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

In the Recursive Solution, We will do the small task and ask recursion to do rest of the task
This means, we will compare the values of both List1 & List2 and whichever value is smaller, we will take that Node as a part of our Sorted LinkedList
After that, we will ask Recursion to do rest of the task & the Sorted List returned by Recursion will be attached to our Selected Node's Next
*/

class Solution {    
private:
    
ListNode *merge(ListNode *l1 , ListNode *l2)
{
    // If List1 is empty, send back List2
    
    if(l1 == NULL)
        return l2 ;
    
    // If List2 is empty, send back List1
    
    if(l2 == NULL)
        return l1 ;
    
    // If both are Non-NULLS, we compare the value pointed at by l1 and l2
    // If l1's value is smaller, we will choose l2
    // Else we will choose l2
    // If the values are same, we can choose from either List1 or List2
    
    // If l1's value is smaller than l2
    
    if(l1 -> val < l2 -> val)
    {
        // We pick the node pointed by l1 and ask recursion to do rest of the task
        // We attach the sorted list to L1's Next and return l1
        
        l1 -> next = merge(l1 -> next , l2) ;
        
        return l1 ;
    }
    
    // Else l2's value is smaller than or equal to l1
    
    else
    {
        
        // We pick the node pointed by l2 and ask recursion to do rest of the task
        // We attach the sorted list to L2's Next and return l1
        
        l2 -> next = merge(l1 , l2 -> next) ;
        
        return l2 ;
    }
    
}
    

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
    return merge(list1 , list2) ;    
    
}
};

/* 
Time Complexity:  O(M + N) { M is the Number of Nodes in List1 , N is the Number of Nodes in List2 }
Space Complexity: O(M + N) { Auxillary Stack Space }
*/
