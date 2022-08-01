def reverseArray(arr, m):
    
    # Function to reverse the required position of array
    def helper(l, r):
        
        # base case
        if l >= r:
            return arr
        
        #swapping the indices of the arr
        arr[l], arr[r] = arr[r], arr[l]
        
        # recursive call
        return helper(l+1, r-1)
    
    return helper(m+1, len(arr)-1)
"""
Algorithm 
TC : O(m/2)
Sc : O(1) || O(m/2) i.e stack memory for recursive call

NOTE 
considering 0 based indexing so the subarray {5, 6} will be reversed and our output array will be {1, 2, 3, 4, 6, 5} """
