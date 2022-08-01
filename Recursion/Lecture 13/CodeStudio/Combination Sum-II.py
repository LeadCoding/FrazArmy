"""
This question is exactly similar to Combination Sum -I. 
The only difference is that we have duplicates inside the given arr[].
We need to skip the duplicate elements. Else they would generate Duplicate Combinations which we don't want.
To skip the Duplicate Elements, we will sort candidates [] and use a While Loop to skip all the Duplicate Elements.

In python we need to pass candidates [], powerSet [] to pass by reference so we are'nt including those in the helper() parameter.

Note : 
Please reffer this article befoe solving the problem to understand the naming convention.
"""
# link - https://leetcode.com/discuss/interview-question/2357412/Subarray-vs-Subsequence-vs-Subset-vs-Powerset

def combinationSum2(arr, n, target):
    
    def helper(i, n, subsetSum):
        
        # BASE CONDITIONS
        # If sum is equal to target, we have reached a Valid Combination
        
        if subsetSum == target:
            powerSet.append(subset.copy())
            return
        
        # If at any moment, sum becomes greater than target, we don't need to proceed further
        
        if subsetSum > target:
            return
        # If we reach the end of arr[], we cannot go any further so we return back
        
        if i == n:
            return
        
        # include the i-th element into our subseq & subseqSum
        
        subset.append(arr[i])
        subsetSum += arr[i]
        
        # Ask recursion to do rest of the task
        
        helper(i+1, n, subsetSum)
        
        # Backtrack and undo the change we have done
        
        subset.pop()
        subsetSum -= arr[i]
        
        # use the While Loop to skip all the duplicate occurrences of i-th Element
        
        while i+1 < len(arr) and arr[i] == arr[i+1]:
            i += 1
        # Don't pick the i-th Element and ask recursion to do rest of the task
        
        helper(i+1, n, subsetSum)
        
    subset = []
    powerSet = []
    subsetSum = 0
    
    arr.sort()
    
    helper(0, n, subsetSum)
    
    return powerSet
    
"""
Time Complexity: O(2^N)
Space Complexity: O(N)
"""
