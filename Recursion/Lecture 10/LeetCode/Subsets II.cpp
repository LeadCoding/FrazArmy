/* This Question is exactly similar to Subsets - I.
Instead of All Unique Elements we have given an array nums[] containing Dupicate Elements
Our Logic remains the same. We will generate Subsets by using - Pick & Don't Pick condition only
Only difference is that, while we are not picking any element, we must skip all it's Duplicate occrurrences in nums[] .
This can be acheived by using a While Loop. Also we need to sort nums[] as the array might be given as unsorted
*/

class Solution {
private :
    
void helper(int i , vector<int> &subset , vector<int> &nums , vector<vector<int>> &ans)
{
    // When we have reached the end of nums[] , we have generated a Valid Unique Subset for sure
    
    if(i >= nums.size() )
    {
        ans.push_back(subset) ;
        return ;
    }
    
    // Otherwise we will use our Pick & Don't Pick Logic
    
    // Consider the Element
    
    subset.push_back(nums[i]) ;
    
    // Ask Recursion to do rest of the task
    
    helper(i + 1 , subset , nums , ans) ;
    
    // Backtrack and undo the change you have done
    
    subset.pop_back() ;
    
    // While using Don't Pick option, we must ensure we skip all the Duplicate Occurrences of nums[i]
    
    while(i < nums.size() - 1 && (nums[i] == nums[i + 1] ) )
    {
        i++ ;
    }
    
    // Our i pointer will stop on the last Duplciate Occurencce of nums[i]
    
    // Don't Consider the Element and Ask Recursion to generate Unique Subsets
    
    helper(i + 1 , subset , nums , ans) ;
    
    return ;
}
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     
    // For our logic to work, we need to sort the given nums[] vector
        
    sort(nums.begin() , nums.end() ) ;
        
    vector<int>subset ;
        
    vector<vector<int> > ans ;
        
    // Call the helper() function to generate all Unique Subsets
        
    helper(0 , subset , nums , ans) ;
        
    return ans ;
}
};

/*
Time Complexity  : O(2^N)
Space Complexity : O(N)
*/
