"""
The HashMap class will be designed in the exactly same manner as HashSet Class
The only difference here is that we need to store {key , value} pair in place of only key
Again, to avoid collisions we will be using the concept of Hashing.
Our vector will be of type <list<pair<int , int>> that is, a Doubly LinkedList which stores a pair of <int , int> in place of our normal int values

Our HashMap Class has the following functions:

a) void put(int key , int value) --> Inserts the key with value inside our HashMap
b) int get(int key) --> Returns the value which is associated with our key(if present) else returns -1
c) void remove(int key) --> Deletes the key along with the Value associated with the Key


"""


class MyHashMap:
    # We Use a list of lists to store all our {key,vvalue} pairs of Hash map Class
    def __init__(self):
        
        self.map = [[] for _ in range(2069)]
    
    
    # Our Hash Function Calculates the index by taking the modulo with size{2069}    
    def Hash(self,key):
        return key%2069
    
    
    # returns an index pointing to the key, else we return an iterator pointing to the End of the List
    def getIndex(self,key):
        # We first calculate the index using Hash(key) Function
        hashr = self.Hash(key)
        Maps = self.map[hashr]
        
        for i,(k,v) in enumerate(Maps):
            # If at any moment our var k == key we return it
            if k == key:
                return Maps,i
        return Maps,-1
    
        

     # Inserts the value with it's correspondinng key
    def put(self, key: int, value: int) -> None:
        Map,idx = self.getIndex(key)
        
        if idx<0:
            Map.append((key,value))
        else:
            Map[idx] = (key,value)
            

    # Get Function returns -1 if the key is not present 
    def get(self, key: int) -> int:
        # we
        Map,idx = self.getIndex(key)
        if idx<0: # here if idx  return to back of list it returns -1 and not found indication
            return -1
        else:
            return Map[idx][1]
        

    def remove(self, key: int) -> None:
        Map,idx = self.getIndex(key)
        # Before Rmoving the key we make sure wether it is present or not
        # in case it is not Found We return -1
        if idx<0:
            return 
        else:
            Map.remove(Map[idx])


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)


'''
Time Complexity:  O(N) --> In the worst case, we need to search the entire m[i] to check if key is present
Space Complexity: O(N) --> We use a List of Lists [[]] to store the {key , value} pairs
'''
