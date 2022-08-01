/* At any stage of our Recursion, we will have 2 choices only -
a) Pick the i-th Element
b) Don't Pick the i-th Elemenent
As all our elements are Unique, our Subsets generated will be Unique as well
*/

class Solution 
{
    public List<List<Integer>> subsets(int[] nums) 
    {
        List<List<Integer>> ans = new ArrayList<>();
        helper(nums , 0, new ArrayList<Integer>() , ans);
        return ans;
    }
    void helper(int nums[],int ci,List<Integer> subset,List<List<Integer>> ans)
    {
        // Our base case will hit when our i pointer reaches the end of given array nums[]
        
        if(ci==nums.length)
        {
            ans.add(new ArrayList<>(subset));
            return ;
        }
        
        // We pick i-th Element
        
        subset.add(nums[ci]);
        
        // We ask recursion to do rest of the task
        
        helper(nums, ci + 1, subset, ans);
        
        // Backtrack and Undo the change we have done
        
        subset.remove(subset.size() - 1);
        
        // We don't pick the i-th element 
        
        helper(nums, ci + 1, subset, ans);
        return ;
    }
}

/* 
Time Complexity : O(2^N)
Space Complexity : O(N)
*/
