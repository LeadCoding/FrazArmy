class MyHashMap {
    // We use the Linked list data structure to store all our{key,value} pairs of HashMap Class
    LinkedList<Pair>[] bucket;
    final int SIZE = 1009; // assigning it to larger prime number

    //Pair class
    class Pair {
        int key;
        int val;

        public Pair(int key, int val) {
            this.key = key;
            this.val = val;
        }
    }

    public MyHashMap() {
        bucket = new LinkedList[SIZE];
        for (int i = 0; i < bucket.length; i++) 
            // initialising the array with empty linked list of pair
            bucket[i] = new LinkedList<Pair>();
            
    }

    /** value will always be non-negative. */
    public void put(int key, int value) {
        int index = getHash(key); // identify the bucket
        LinkedList<Pair> PairLink = bucket[index];
        if (get(key) != -1) remove(key); // if the key is available then remove it // same as update
        Pair Pair = new Pair(key, value); //otherwise
        PairLink.add(Pair);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        int index = getHash(key);
        LinkedList<Pair> PairLink = bucket[index];
        Iterator<Pair> it = PairLink.iterator();
        while (it.hasNext()) {
            Pair pair = it.next();
            if (pair.key == key) return pair.val;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        int index = getHash(key);
        LinkedList<Pair> PairLink = bucket[index];
        Iterator<Pair> it = PairLink.iterator();
        while (it.hasNext()) {
            Pair pair = it.next();
            if (pair.key == key) it.remove();
        }
    }

    // getHash function will calculates the index by taking the modulo with the SIZE
    public int getHash(int key) {
        return key % SIZE;
    }
}

/* 
Time Complexity:  O(N) --> In the worst case, we need to search the entire bucket[i] to check if key is present
Space Complexity: O(N) --> We use a LinkedList<Pair>[] bucket to store the {key , value} pairs
*/

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */

