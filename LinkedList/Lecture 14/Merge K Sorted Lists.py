from queue import PriorityQueue
"""
In Python A library named Queue Provides already standard implemented Priority Queue under in PriorityQueue Module

The optimised approach of the problem - Merge K Sorted Lists, involves the usage of Min-Heap

At the begining, we will be storing only K Elements, into our Min-Heap.
We will also have a dummy Node to keep track of the Head of our Merged LinkedList. 
Tail pointer will intially point to dummy but keeps on Nodes in order to form the Merged K Sorted LinkedList
After adding first K Elements, we will use a While Loop which runs till our Priority-Queue has not become empty.
Everytime, we will pick the Top Element from the Priority-Queue(which will also be smallest among all K Nodes present). We will make Tail's Next point to that Top Node. Make Tail shift to that Node. And, also add it's Next Node(if it exists)
By repeating the process, we will have our Merged K Sorted LinkedList ready. The Head of that LinkedList will be pointed by Dummy's Next



"""
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        pq = PriorityQueue()
        
        for node in lists:
            if node:
                pq.put((node.val, id(node), node))
            
        """ Two Dummy nodes have been created """
        dummy = ListNode(val=-1)
        tail = dummy
        
        # Loop till Our Prorrity Queue is not Empty
        while not pq.empty():
            #Fetch the top most value of the Priority Queue
            val, _id, node = pq.get()
            tail.next = ListNode(val=val)
             # Now move tail tail->next
            tail = tail.next
            
            """  We enter Temp's Next Node into our Priority-Queue if it exists """
            if node.next:
                pq.put((node.next.val, id(node.next), node.next))
        
        #  At the End we return the dummy's next which contains the head address
        
        return dummy.next
"""
Time Complexity:  O(N*LogK)
Space Complexity: O(K)


"""
