"""
Generating Combinations is exactly similar to generating Subsets.
At every stage we will - a) Pick i-th Element  
                         b) Don't Pick i-th Element
Instead of giving us an array or vector, we are asked to generate all Combinations from 1 to N (both inclsive) and length of each Subset should be exactly K
We use the same Pick & Don't Pick Logic to solve the Question
We should always remember - Relative order matters in Combination just like Subsets


"""

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        
        def helper(i, n, k):
            
            # base case | If k is equal to 0, we have generated a Valid Subset of K length
            if k == 0:
                ans.append(subSet.copy())
                return
            
            # If we don't have enough elements to make our subset, we shouldn't proceed further
            if k > n-i+1:
                return 
            
            # If i becomes greater than N, we should stop going forward
            if i > n:
                return
            
            # Our logic remains exactly same as Generating Subsets
    
            # Pick i-th Element

            subSet.append(i)
            
            # Ask Recursion to do the Rest of the Task

            helper(i + 1, n, k - 1)

            # Backtrack and undo the change
            subSet.pop()

            # Don't pick the i-th Element

            helper(i + 1, n, k)
        
        """
        Note : we've to pass ans, subSet array by their references so we've not included it on the helper function's parameter
        """
        ans = []
        subSet = []
        
        helper(1, n, k)
        return ans
    
"""
Time Complexity  : O(2^N)
Space Complexity : O(N)

"""
