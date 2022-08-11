/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
class Solution {
    public Node copyRandomList(Node head) {

        Node temp=head;

        // We store the Nodes And their Deep Copies inside m M
        HashMap<Node,Node> m=new HashMap<>();

        // In 1st iteration, we create copies and store the Nodes and their Copies as Key-Value pair inside our Map M

       
        while(temp!=null)
        {
            // We create a Copy of the Given Node using Temp's Value
            m.put(temp,new Node(temp.val));
            temp=temp.next;
        }

        // We again reinitialise Temp to Head to iterate again 

        temp=head;

        // In 2nd iteration, we will make connections of the copies stored in Map M

        while(temp!=null)
        {
            // Writing in the form of array for better understandability
            // M[Temp] will give us the Copy Node of Temp
            // M[Temp -> Next] will give us th Copy Node of Temp's Next
            // Copied Node's Next should point to the Copied Node of Temp's Next
             // check out the syntax below 

            m.get(temp).next=m.get(temp.next);

            // Similarly, M[Temp -> Random] will give us the Copy Node of Temp's Random

            m.get(temp).random=m.get(temp.random);

            temp=temp.next;
        }

        // At the end, we return M[head] which is actually Head of our Copied LinkedList

        return m.get(head);
    }
}

/* 
Time Complexity:  O(N)
Space Complexity: O(N)
*/
