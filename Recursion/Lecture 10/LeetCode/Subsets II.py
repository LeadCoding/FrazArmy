class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:

        def helper(i, subset, nums, ans):
            
            #Base Case When we have reached the end of nums[] , we have generated a Valid Unique Subset for sure
            
            if i >= len(nums): #LVI
                ans.append(subset.copy())
                return
            
            subset.append(nums[i])
            
            # Ask Recursion to do rest of the task | Left Subtree
            
            helper(i+1, subset, nums, ans)
            
            # Backtrack and undo the change you have done
            
            subset.pop()
            
            # While using Don't Pick option, we must ensure we skip all the Duplicate Occurrences of nums[i]
            
            while i+1 < len(nums) and nums[i] == nums[i+1]:#Preventon step
                i += 1
                
            # Our i pointer will stop on the last Duplciate Occurencce of nums[i]
            # Don't Consider the Element and Ask Recursion to generate Unique Subsets | Right subtree
            
            helper(i+1, subset, nums, ans)
        
        # For our logic to work, we need to sort the given nums[] vector
        nums.sort()
        
        ans = []
        
        subset= []
        
        helper(0, subset, nums, ans)
        
        return ans
    
"""
Time Complexity  : O(2^N)
Space Complexity : O(N)
"""
