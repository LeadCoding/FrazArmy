"""
This question is exactly similar to Permutations - I 
Only difference being we have duplicate elements in nums[]. But we need to print Unique Permutations only
For that purpose, we have used a local unordered_set data structure which tells us if that particular element has been previosuly encountered or not
If we have taken / chosen the element before, we will not include it anymore. 
But if we haven't included the element, we will include it now
"""
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        def hashKey(arr):
            s = ""
            for i in arr:
                s += str(i)
            return s
            
        def helper(pos, n, key):
            
            #  Base Case executes when we have traversed the entire nums[]
            if pos >= n:
                ans.append(nums.copy())
                numsMap[key] = 1
                return
            
            #  The rest logic remains exactly the same
            
            for i in range(pos, n):
                
                # We simply use our swapping logic to create Permutations  
                
                nums[i], nums[pos] = nums[pos], nums[i]
                
                # hasing the nums arry to a string, to store in numsMap dictionary
                
                key = hashKey(nums)
                
                # And we ask Recursion to handle rest of the task
                # To ensure we're not storing any duplicate | we check if the hash(nums) is already not present in the numsMap
                if key not in numsMap:
                    helper(pos+1, n, key)
                
                # Backtrack and undo the change we have done 
                
                nums[i], nums[pos] = nums[pos], nums[i] 
            return
        
        ans = []
        
        # Dictionary to store each permutation of nums as key | before  storing it in key we need to convert nums [] to a String, as list are not hashable
        # Dictionary is used to optimise the Time complexit as search TC is O(1) 
        numsMap = {}
        
        helper(0, len(nums), hashKey(nums))
        
        return ans
            
"""
Time Complexity  : O(N * N!)
Space Complexity : O(N)
"""
