def combSum(ARR, B):
        
    def helper(i, sumTillNow):
        
        # base condition
        # if sumTillNow == required sum (B) this means that we have reached a Valid Combination thus include it into the ans []
        
        if sumTillNow == B:
            ans.append(subSet.copy())
            return
        #  base condition
        # if sumTillNow > required sum (B) this means that we are exceeding the limit of required sum therefore simply return
        
        if sumTillNow > B:
            return
        
        # Base Case
        # if current Index (i) is exceeding the array size then return
        
        if i >= len(ARR):
            return
        
        # We skip the i-th element 
        
        helper(i+1, sumTillNow)
        
        # We pick the ith element
        
        sumTillNow += ARR[i]
        subSet.append(ARR[i])
        
        # We keep the i-th Element & ask recursion to do rest of the task
        
        helper(i, sumTillNow)
        
        # backtrack & undo the changes that were made while picking the ith element
        
        sumTillNow -= ARR[i]
        subSet.pop()
        
    # Global Scope reference variables 
    subSet = []
    ans = []
    sumTillNow = 0
    
    # This sorting ensures all the elements in each Subset are also in sorted order
    
    ARR.sort()
    
    helper(0, sumTillNow)
    
    return ans
    
"""
Time Complexity: O(Exponential) or O(n^2)

Explanation: : As it's very difficult to predict how many children one
particular node can have, evident from the Recursive Tree, as one
element can occur multiple times and also we won't be generating
all the subsets in one go. So, the Time Complexity can be said to be
Exponential only!!


Space Complexity: O(n+m) | n for stack memory and m = size of ans array

Explanation: Space Complexity will be equal to height of the recursive
tree, Which in the worst Case is equal to Target-Sum if we had 1 in
arr[] and we kept on picking only 1 till we reach Target-Sum. That's
why Time complexity is (Target-Sum)
"""
