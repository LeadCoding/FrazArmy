class Node:
    # key, val, next, prev 
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = self.prev = None

class LRUCache:
    
    # create hasmap and it's capacity, doubly with lru == head, mru == tail
    def __init__(self, capacity: int):
        # key = key, val = Node.obj
        self.cacheMap = {}
        self.capacity = capacity
        # Dll creation | head, tail
        self.lru = Node(0, 0)
        self.mru = Node(0, 0)
        # assigning pointers
        self.lru.next = self.mru
        self.mru.prev = self.lru

    # removes the node
    def remove(self, node):
        nextNode , prevNode = node.next , node.prev
        # breaking link with Node's left and right node and linking left and right node of Node with each-other
        nextNode.prev, prevNode.next = prevNode, nextNode
        
    # insert at MRU
    def insert(self, node):
        # nextNode, prevNode = self.mru , self.mru.prev
        # nextNode.prev = prevNode.next = node
        # node.next, node.prev = nextNode, prevNode
        prev = self.mru.prev;
        self.mru.prev = node;
        node.next = self.mru;
        node.prev = prev;
        prev.next = node;
        
    # return the cache's val withh the key | Updates the order of cache -> removes the node and link it to MRU 
    def get(self, key: int) -> int:
        if key in self.cacheMap:
            self.remove(self.cacheMap[key])
            self.insert(self.cacheMap[key])
            return self.cacheMap[key].val
        return -1
        
    def put(self, key: int, value: int) -> None:
        if key in self.cacheMap:
            self.remove(self.cacheMap[key])
            del self.cacheMap[key]
        # storing new node to the cacheMap
        self.cacheMap[key] = Node(key, value)
        # link to the DLL
        self.insert(self.cacheMap[key])
        
        # if insertion excedes the capacity then update the DLL
        # node = Node(key, value)
        # self.cacheMap[key] = node

        if len(self.cacheMap) > self.capacity:
            lruNode = self.lru.next 
            self.remove(lruNode)
            del self.cacheMap[lruNode.key]

"""
Tc : O(1)
Sc : O(capacity)
"""

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
