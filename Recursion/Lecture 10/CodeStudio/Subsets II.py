from typing import *

def uniqueSubsets(n :int,arr :List[int]) -> List[List[int]]:

    def helper(i, subset, arr, ans):
        
        #Base Case, When we have reached the end of nums[] , we have generated a Valid Unique Subset for sure
        
        if i >= len(arr):
            ans.append(subset.copy())
            return
        
        # pick the ith element
        subset.append(arr[i])
        
        #  picked ith element and recursion will find the remaining subsets with ith element | Left Subtree
        
        helper(i+1, subset, arr, ans)
        
        # firstly, we need to backtrack and undo the changes that we have made
        
        subset.pop()
        
        # ensure we don't pick any other occurrences ofi-th element in order to generate Unique Subsets
        
        while i+1 < len(arr) and arr[i] == arr[i+1]:#Preventon step
            i += 1
            
        # currentIndex will now point to the Last Occurrence of ith Element
        # we ignored ith element and now recursion will do find the remaining subsets without the ith element
        # skip the ith element
        
        helper(i+1, subset, arr, ans)
    
    # For our logic to work, we need to sort the given nums[] vector
    arr.sort()
    
    ans = []
    
    subset= []
    
    helper(0, subset, arr, ans)
    
    # this is specific to the given problem, they wanted each subset in sorted order
    ans.sort()
    return ans
    
"""
Time Complexity  : O(2^N)
Space Complexity : O(N)
"""
