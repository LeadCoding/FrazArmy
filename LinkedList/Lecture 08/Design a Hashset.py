'''
We need to design a HashSet Class which contains only Unique Values like any HashSet Class.
Our HashSet class contains the following operations:
a) void add(int key) --> Adds an element into the HashSet
b) void remove(int key) --> Removes the key element from the HashSet
c) bool contains(int key) --> Returns true if key is present in our HashSet else returns false

Instead of using unneccessary space, we can use limited space by using the concept of Hashing & Chaining
We require chaining to prevent collisions in our HashSet

'''


class MyHashSet:
    # We Use a list to store all our elements of Hashset Class

    def __init__(self):
        self.L = []
        

    def add(self, key: int) -> None:
        # add() function adds the given Key into our Hash List at the index specified by our hash() function
        # If the key is already present, we don't need to add it again
        if key in self.L:
            pass
        # Otherwise, we will find the index i where we need to add our key using hash() function
        else:
            #  We add the key at the end in O(1) Time Complexity so we appended it to list
            self.L.append(key)
        
    # remove() function deletes the given Key from our List L
    def remove(self, key: int) -> None:
        # Firstly, we need to check whether our key is present inside our List. If the key is not present, we cannot delete it, thus we directly return
        try:
            self.L.remove(key)
        except:
            pass
        
        
    # contains() function returns true if the key is present else returns false
    def contains(self, key: int) -> bool:
        return key in self.L
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
""""
Time Complexity:  O(N) --> In the worst case, we need to search the entire m[i] to check if key is present
Space Complexity: O(N) --> We use a vector<list<int>> to store all the Unique Keys 

"""
