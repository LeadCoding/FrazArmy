void reverse(int l, int r, vector<int> &arr)
{
    // base condition
    if (l >= r)
        return;

    // do the small task
    swap(arr[l], arr[r]);
    
    // ask recursion to do the remaining task
    reverse(l + 1, r - 1, arr);
}
void reverseArray(vector<int> &arr, int m)
{
    // Write your code here.
    return reverse(m + 1, arr.size() - 1, arr);
}

/*
    time complexity : O(n)
    space complexity : O(n)
*/