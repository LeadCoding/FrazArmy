/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

 /* The optimised approach of the problem - Merge K Sorted Lists, involves the usage of Min-Heap
In Java, Min-Heap is implemented with the help of Priority-Queue
At the begining, we will be storing only K Elements, into our Min-Heap.
We will also have a dummy Node to keep track of the Head of our Merged LinkedList. 
Tail pointer will intially point to dummy but keeps on Nodes in order to form the Merged K Sorted LinkedList
After adding first K Elements, we will use a While Loop which runs till our Priority-Queue has not become empty.
Everytime, we will pick the Top Element from the Priority-Queue(which will also be smallest among all K Nodes present). We will make Tail's Next point to that Top Node. Make Tail shift to that Node. And, also add it's Next Node(if it exists)
By repeating the process, we will have our Merged K Sorted LinkedList ready. The Head of that LinkedList will be pointed by Dummy's Next
*/

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {

        // Our Priority Queue q will always store the K Smallest Elements from the K Sorted Lists

        // implementing min heap based on the value of list 
        
        PriorityQueue<ListNode> pq = new PriorityQueue<>((ListNode l1 ,ListNode l2)->l1.val-l2.val);
        
        // Firstly, we enter all the K Nodes into our Min-Heap

        for(ListNode list : lists){
            if(list!=null){
                pq.add(list);
            }
        }
        
        // Dummy Pointer's Nexy will point to the Head of our K Merged Sorted Linkedlist

        ListNode dummy = new ListNode(-1);

        // Tail pointer will help us to add Nodes into our K Merged Sorted LinkedList

        ListNode tail = dummy;

        // While Loop will run till our the size of our Priority-Queue not becomes 0(zero)

        while(!pq.isEmpty()){

            // We pop the Topmost Element from our Priority-Queue and store it in Temp pointer

            tail.next=pq.poll();

            // Tail will one step further 

            tail=tail.next;
            
            if(tail.next!=null){
                pq.add(tail.next);
            }
        }

            // At the end, we return Dummy's Next which contains the Head of our Merged K Sorted LinkedList

        return dummy.next;
    }
}

/*
Time Complexity:  O(N*LogK)
Space Complexity: O(K)
*/
