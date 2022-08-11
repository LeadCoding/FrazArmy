/* In this question, we are asked to design LRU (Least Recently Used) data structure. 
To solve the question, we will require Two Unordered Maps:
        a) One will store all the Key Value pairs
        b) One will store the iterators corresponding to all the Keys stored in First Map
        
We need to know always which data is recently used or not. For that purpose, we will use Doubly LinkedLists, that is, Lists in C++ STL .

Our LRU-Cache will have the following functions:
a) LRUCache(int capacity) --> Constructor to initialise the Max Capacity of our Cache
b) int get(int key) --> Returns the value assoicated with the key, if present, else returns -1
c) void put(int key , int value) --> Update the value associated with the key, if present. Otherwise, make the new entry. And if Capacity exceeds then delete the Least Recently Used(Last Node) and then add the key-value pair
*/


class LRUCache {
public:
    
    // Map M will store all the Key-Value Pairs 
    
    unordered_map<int , int> m ;
    
    // Map Address will help us to get the iterator(pointer) of a particular Node present in our Doubly Linked List
    
    unordered_map<int , list<int> :: iterator> address ;
    
    // Doubly LinkedList L will help us to keep track of the recently used data and also to delete as well as make new entiries in our Map M
    
    list<int> l ;
    
    // Cap will store the maximum Capacity of our LRU Data Structure
    
    int cap ;
    
    // Siz will store the Current Size of our LRU Data Structure
    
    int siz  ;
    
    // Initally, Cap is intialised with Capacity(given by the user) and Siz as 0
    
    LRUCache(int capacity) 
    {
        cap = capacity ;
        
        siz = 0 ;
    }
    
    // This function will return the value associated with a particular Key and make the Key move to the front of our Doubly LinkedList
    
    int get(int key) 
    {
        // If the Key is not present, simply return -1
        
        if(m.find(key) == m.end() )
            return -1 ;
        
        // Store the Address of the Key using Address Map
        
        list<int> :: iterator it = address[key] ;
        
        // Erase the Key from the List and the Address Map
        
        l.erase(it) ;
        address.erase(key) ;
        
        // Put the Key again at the Front of our Doubly LinkedList & insert in the Address Map again
        
        l.push_front(key) ;
        address[key] = l.begin() ;
        
        // Return the value associated with the Key using Map M
        
        return m[key] ;
        
    }
    
    // This function inserts the Key-Value pair if not present. Otherwise update the Key-Value pair with the new Value
    
    void put(int key, int value) 
    {
        // If Key is already present in Map M, delete it & decrement Siz by 1
        
        if(m.find(key) != m.end() )
        {
            l.erase(address[key]) ;
            
            address.erase(key) ;
            
            m.erase(key) ;
            
            siz-- ;
        }
        
        // If Siz is equal to Cap, that is, Capacity is full, we need to delete the Last Node from our Doubly LinkedList
        
        if(siz == cap)
        {
            // Store the Last Node's Value in variable K
            
            int k = l.back() ;
            
            // Delete the Node from Doubly LinkedList 
            
            l.pop_back() ;
            
            // Remove K from Address Map & M Map as well
            
            address.erase(k) ;
            m.erase(k) ;
            
            // Decrement Siz by 1
            
            siz-- ;
        }
        
        // Now, we can insert the Key-Value Pair into our Map M as well as our List L
        
        siz++ ;
        
        // Make the Key as the First Node of our Doubly LinkedList L
        
        l.push_front(key) ;
        
        // Store the iterator / pointer of Key into Address Map
        
        address[key] = l.begin() ;
        
        // Store the Key Value pair in Map M
        
        m[key] = value ;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/*
Time Complexity:  O(1) {Average Case Time Complexity}
Space Complexity: O(N)
*/
