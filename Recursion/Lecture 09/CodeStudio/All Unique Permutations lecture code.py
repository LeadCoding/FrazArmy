def uniquePermutations(arr, n):                
    def helper(pos, n):
        
        #  Base Case executes when we have traversed the entire nums[]
        if pos >= n:
            ans.append(arr.copy())
            return
        
        #  The rest logic remains exactly the same
        
        for i in range(pos, n):
            
            # We simply use our swapping logic to create Permutations  
            
            arr[i], arr[pos] = arr[pos], arr[i]
            
            # And we ask Recursion to handle rest of the task
            # To ensure we're not storing any duplicate | we check if the hash(nums) is already not present in the numsMap
            if arr not in ans:
                helper(pos+1, n)
            
            # Backtrack and undo the change we have done 
            
            arr[i], arr[pos] = arr[pos], arr[i] 
        return
    
    ans = []
    
    # Dictionary to store each permutation of nums as key | before  storing it in key we need to convert nums [] to a String, as list are not hashable
    
    helper(0, len(arr))
    
    return ans

        
"""
Time Complexity  : O(N * N!)
Space Complexity : O(N)
"""
