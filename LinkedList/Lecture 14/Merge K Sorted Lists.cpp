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

/* The optimised approach of the problem - Merge K Sorted Lists, involves the usage of Min-Heap
In c++, Min-Heap is implemented with the help of Priority-Queue
At the begining, we will be storing only K Elements, into our Min-Heap.
We will also have a dummy Node to keep track of the Head of our Merged LinkedList. 
Tail pointer will intially point to dummy but keeps on Nodes in order to form the Merged K Sorted LinkedList
After adding first K Elements, we will use a While Loop which runs till our Priority-Queue has not become empty.
Everytime, we will pick the Top Element from the Priority-Queue(which will also be smallest among all K Nodes present). We will make Tail's Next point to that Top Node. Make Tail shift to that Node. And, also add it's Next Node(if it exists)
By repeating the process, we will have our Merged K Sorted LinkedList ready. The Head of that LinkedList will be pointed by Dummy's Next
*/


// Class cmp uses Function Overloading to compare Two Nodes - A and B. It returns true if A's Value is smaller than B's Value. Else it returns false
// This cmp class is essential to make our Min-Heap using Priority-Queue in C++

class cmp
{
    public :
    
    bool operator() (ListNode *a , ListNode *b)
    {
        return a -> val > b -> val ;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
     
    // Our Priority Queue q will always store the K Smallest Elements from the K Sorted Lists
        
    priority_queue<ListNode* , vector<ListNode*> , cmp> q ;
      
    // Firstly, we enter all the K Nodes into our Min-Heap
        
    for(int i = 0 ; i < lists.size() ; i++)
    {
        if(lists[i] != NULL)
            q.push(lists[i]) ;
    }
       
    // Dummy Pointer's Nexy will point to the Head of our K Merged Sorted Linkedlist
        
    ListNode *dummy = new ListNode(-1) ;
    
    // Tail pointer will help us to add Nodes into our K Merged Sorted LinkedList
        
    ListNode *tail = dummy ;
      
    // While Loop will run till our the size of our Priority-Queue not becomes 0(zero)
        
    while(q.size() )
    {
        // We pop the Topmost Element from our Priority-Queue and store it in Temp pointer
        
        ListNode *temp = q.top() ;
        q.pop() ;
        
        // Tail's Next points to Temp
        
        tail -> next = temp ;
        
        // After that, Tail Pointer is moved to Temp
        
        tail = temp ;
        
        // We enter Temp's Next Node into our Priority-Queue if it exists
        
        if(temp -> next != NULL)
            q.push(temp -> next) ;
    }
        
    // At the end, we return Dummy's Next which contains the Head of our Merged K Sorted LinkedList
        
    return dummy -> next ;
}
};

/*
Time Complexity:  O(N*LogK)
Space Complexity: O(K)
*/
