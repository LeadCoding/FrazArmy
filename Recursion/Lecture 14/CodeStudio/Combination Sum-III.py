"""
This question is exactly similar to Combination Sum -I. 
The only difference is that we have duplicates inside the given vector arr[]
We need to skip the duplicate elements. Else they would generate Duplicate Combinations which we don't want
To skip the Duplicate Elements, we will sort arr[] and use a While Loop to skip all the Duplicate Elements

NOTE:
As we haev to pass subset [] and ans [] by it's reference I haven't incuded it in heper() parameter
"""
def combinationSum3(K: int, N: int) -> [[]]:
        
    def helper(i, k, sumTillNow , n):
        
        # If the Sum-Till-Now becomes greater than n, we don't need to proceed further
        
        if sumTillNow > n:
            return
        
        # If k becomes equal to zero(0) , we need to check if the Sum-Till-Now is equal to n or not
        
        if k == 0:
            
            # If the Sum-Till-Now is equal to n, we include the Subset into our ans[][]
        
            if sumTillNow == n:
                ans.append(subset.copy())
            
            # else we simply return without including the Subset
            
            return
        
        # If i becomes equal to 10, we don't need to proceed any further
        
        if i == 10:
            return
        
        # We include the i-th Number into our Sum-Till-Now & also into our Subset[]
        
        sumTillNow += i
        subset.append(i)
        
        #  Ask Recursion to do the rest of the task
        
        helper(i+1, k-1, sumTillNow, n)
        
        # Backtrack and undo the change we have done
        
        subset.pop()
        sumTillNow -= i            

        # We don't include the i-th Number and ask recursion to do the rest of the Combinations
        helper(i+1, k, sumTillNow, n)
            
    subset = []
        
    ans = []

    helper(1, K, 0, N)
        
    return ans
    
"""
Time Complexity: O(2^N)
Space Complexity: O(K)
"""
