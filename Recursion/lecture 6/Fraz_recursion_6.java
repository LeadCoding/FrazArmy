void reverseArrayHelper(int l,int r,ArrayList<Integer>arr)
{
    if(l>=r) return;
    int tmp=arr.get(l);
    arr.set(l,arr.get(r));
    arr.set(r,tmp);
    reverseArrayHelper(l+1,r-1,arr);
}

void reverseArray(ArrayList<Integer> arr,int m)
{
    reverseArrayHelper(m+1,arr.length()-1,arr);
}
