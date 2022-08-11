/* In this question, we have been given a Linked-List which has two pointers:
                    a) Next Pointer --> Pointing to the Next Node of the Linked-List
                    b) Random Pointer --> Points to any Random Node of the LinkedList, even NULL
                    
    We need to make a Deep Copy of LinkedList. Deep Copy refers that we need to actually copy the LinkedList
    We need to make the Deep Copy such that the Random Pointers of our new copied LinkedList should point to the Nodes where there copies were pointing initally. 
        For example - If A(Given Node) A''(New Copied Node) & A Random Pointer pointed to B initally
                        A''s random -> B
                        
    To make such connection possible, we will use an Unordered-Map which maps A with A' , B with B' and so on.
/*

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        // We store the Nodes And their Deep Copies inside Map M
        
        map<Node * , Node *> m ;
        
        // Temp is used to iterate over the given LinkedList
        
        Node *temp = head ;
        
        // In 1st iteration, we create copies and store the Nodes and their Copies as Key-Value pair inside our Map M
        
        while(temp != NULL)
        {
            // We create a Copy of the Given Node using Temp's Value
            
            Node *copy = new Node(temp -> val) ;
            
            // We store the Node as well it's copy inside our Map M
            
            m[temp] = copy ;
            
            temp = temp -> next ;
        }
        
        // We again reinitialise Temp to Head to iterate again 
        
        temp = head ;
        
        // In 2nd iteration, we will make connections of the copies stored in Map M
        
        while(temp != NULL)
        {
            // M[Temp] will give us the Copy Node of Temp
            // M[Temp -> Next] will give us th Copy Node of Temp's Next
            // Copied Node's Next should point to the Copied Node of Temp's Next
            
            m[temp] -> next = m[temp -> next] ;
            
            // Similarly, M[Temp -> Random] will give us the Copy Node of Temp's Random
            
            m[temp] -> random = m[temp -> random] ;
            
            temp = temp -> next ;
        }
        
        // At the end, we return M[head] which is actually Head of our Copied LinkedList
        
        return m[head] ;
    
    }
};

/* 
Time Complexity:  O(N)
Space Complexity: O(N)
*/
