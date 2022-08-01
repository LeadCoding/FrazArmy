"""
* The idea is to generate all Possible Permutations by swapping the nums[currentIndex] with nums[i]
* As all the characters are Unique, the Permutations generated will also be Unique
* We make neccessary changes in nums[] vector only. We don't use any other data structure
* For Permutations, order doesn't matter
"""
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        # makes swaps in nums array
        def swap(i, j):
            nums[i], nums[j] = nums[j], nums[i]
            return
        
        def helper(pos, n, nums, ans):
            
            # If we have reached the end of nums[], we have found a Valid Permutations of nums[]
            if pos >= n:
                # appending a copy of nums, else it wold be passed by referemced, 
                # any change to nums will change the appended ans. Don't worry about the extra space, Garbage 
                # collector will handel the extra space
                ans.append(nums.copy())
                return
            
            # Otherwise we iterate over all the other elements and try to generate Permutations by swapping nums[pos] with nums[i]
            
            for i in range(pos, n):
                
                # We create one Unique Permutation by swapping nums[i] with nums[pos]
                
                swap(i, pos)
                
                # And we ask Recursion to handle rest of the task
                
                helper(pos+1, n, nums, ans)
                
                # But after we come back, we must backtrack and undo the changes we have done
                
                swap(i, pos)
        
        ans = []
        
        helper(0, len(nums), nums, ans)
        
        return ans
            
"""
Time Complexity  : O(N * N!)
Space Complexity : O(N)
"""
                
