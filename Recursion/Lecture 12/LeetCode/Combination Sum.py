"""
The idea of this question is to return all such combinations whose individual sum is equal to Target
We use the same logic as generating Combinations - only difference is that we calculate the sum of each subset every time.
We can use an element as many times as we want
Our given vector arr[] contains only Unique Subsets that's for sure

"""
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        def helper(i, sumTillNow):
            
            #  If our sumTillNow is equal to Target, we have reached a Valid Combination
            
            if sumTillNow == target:
                ans.append(subSet.copy())
                return
            
            # If our sumTillNow exceeds Target, there's no point in proceeding further
            
            if sumTillNow > target:
                return
            
            #  If we have reached the end of arr[], we cannot go further as we don't have anymore elements
            
            if i >= len(candidates):
                return
            
            # We skip the i-th element 
            
            helper(i+1, sumTillNow)
            
            # We include the i-th into our sumTillNow
            
            sumTillNow += candidates[i]
            
            # We push the i-th Element into our subSet
            
            subSet.append(candidates[i])
            
            # We keep on the i-th Element & ask recursion to do rest of the task
            
            helper(i, sumTillNow)
            
            # When we come back, we need to backtrack & undo the change
            
            sumTillNow -= candidates[i]
            
            subSet.pop()
            
        # Global Scope reference variables 
        subSet = []
        ans = []
        sumTillNow = 0
        
        # This sorting ensures all the elements in each Subset are also in sorted order
        
        candidates.sort()
        
        helper(0, sumTillNow)
        
        return ans
    
"""
Time Complexity: O(Exponential) or O(n^2)

Explanation: : As it's very difficult to predict how many children one
particular node can have, evident from the Recursive Tree, as one
element can occur multiple times and also we won't be generating
all the subsets in one go. So, the Time Complexity can be said to be
Exponential only!!


Space Complexity: O(n+m) | n for satck memory and m = size of ans array

Explanation: Space Complexity will be equal to height of the recursive
tree, Which in the worst Case is equal to Target-Sum if we had 1 in
arr[] and we kept on picking only 1 till we reach Target-Sum. That's
why Time complexity is (Target-Sum)
"""
