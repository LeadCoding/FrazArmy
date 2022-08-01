"""
At any stage of our Recursion, we will have 2 choices only -
a) Pick the i-th Element
b) Don't Pick the i-th Elemenent
As all our elements are Unique, our Subsets generated will be Unique as well
"""
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        def helper(i, subSet, nums, ans):
            
            # Our base case will hit when our i pointer reaches the end of given array nums[]
            if i == len(nums):
                ans.append(subSet.copy())
                return
            
            # we pick ith Element
            subSet.append(nums[i])
            
            # We ask recursion to do rest of the task
            helper(i+1, subSet, nums, ans)
            
            # Backtrack and Undo the change we have done
            subSet.pop()
            
            # We don't pick the ith element
            helper(i+1, subSet, nums, ans)
            
            return
        
        # Global Variables for helper functions
        ans = []
        subSet = []
        # Helper will store the ans in ans list        
        helper(0, subSet, nums, ans)
        
        return ans
            
"""
Time Complexity : O(2^N)
Space Complexity : O(N)
"""
