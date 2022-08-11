/* We need to design a HashSet Class which contains only Unique Values like any HashSet Class.
Our HashSet class contains the following operations:
a) void add(int key) --> Adds an element into the HashSet
b) void remove(int key) --> Removes the key element from the HashSet
c) bool contains(int key) --> Returns true if key is present in our HashSet else returns false

Instead of using unneccessary space, we can use limited space by using the concept of Hashing & Chaining
We require chaining to prevent collisions in our HashSet
*/

class MyHashSet {
 
// We use a vector of type doubly linked list to store all our elements of HashSet Class
    
vector<list<int> > m ;
int siz ;
    
public:
    // Inside the constructor we initialise our siz variable with 100(or any number of our wish) and resize our vector<list<int>> m according to our siz 
    
    MyHashSet() 
    {
        siz = 100 ;
        
        m.resize(siz) ;
    }
    
    // Our hash function simply returns the index by taking modulo with siz variable
    
    int hash(int key)
    {
        return (key % siz) ;
    }
    
    // Search() functions returns us an iterator indicating the position where the Key is present
    
    list<int> :: iterator search(int key)
    {
        int i = hash(key) ;
        
        // m[i] gives us the entire Doubly LinkedList present at i-th Index
        // find() function is a STL function which needs 3 variables to search for a key:
        // a) Staring iterator:- m[i].begin()
        // b) Ending  iterator:- m[i].end() 
        // c) Key to be searched: key
        
        return find(m[i].begin() , m[i].end() , key) ;
    }
    
    // add() function adds the given Key into our vector<list<int>> m at the index specified by our hash() function
    
    void add(int key) 
    {
        // If the key is already present, we don't need to add it again
        
        if(contains(key) )
            return ;
        
        // Otherwise, we will find the index i where we need to add our key using hash() function
        
        int i = hash(key) ;
        
        // We add the key at the end in O(1) Time Complexity
        
        m[i].push_back(key) ;
        
    }
    
      // remove() function deletes the given Key from our vector<list<int>> m
    
    void remove(int key) 
    {
        // Firstly, we need to check whether our key is present inside our vector<lis<int>>. If the key is not present, we cannot delete it, thus we directly return
        
        if(!contains(key) )
            return ;
        
        // We find the index i using our hash() function
        
        int i = hash(key) ;
        
        // m[i] is the total Linked-list in which our key is present
        // search(key) returns us the iterator denoting the position where our key is present in that List
        // erase() function deletes that key from the List
        
        m[i].erase(search(key) ) ;
        
    }
    
    // contains() function returns true if the key is present else returns false
    
    bool contains(int key) 
    {
        // We first calculate the index i where our key might be present using hash() function
        
        int i = hash(key) ;
        
        // Since search(key) returns us an iterator. If that iterator is not equal to m[i].end() , it indicates that the element is present, thus we return true
        
        if(search(key) != m[i].end() )
            return true ;
        
        // Else the element is not present, thus we return false
        
        else
            return false ;
    }
};

/* 
Time Complexity:  O(N) --> In the worst case, we need to search the entire m[i] to check if key is present
Space Complexity: O(N) --> We use a vector<list<int>> to store all the Unique Keys 
*/

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
