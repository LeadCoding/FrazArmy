/* The idea is to generate all Possible Permutations by swapping the nums[currentIndex] with nums[i]
As all the characters are Unique, the Permutations generated will also be Unique
We make neccessary changes in nums[] vector only. We don't use any other data structure
For Permutations, order doesn't matter

NOTE : In java there are no swap function so we need to create our own swap function

NOTE : The array must be converted into List before storing it in answer
*/


class Solution 
{
    public void helper(int pos , int n , int[] nums , List<List<Integer>> ans)
    {
        // If we have reached the end of nums, we have found a Valid Permutations of nums

        if(pos >= n)
        {
            List<Integer> permutation = ConverttoArray(nums);
            ans.add(new ArrayList(permutation)) ;
            return ;
        }

        // Otherwise we iterate over all the other elements and try to generate Permutations by swapping element at pos with element at i

        // Hashset ensures we are not taking duplicates and thus not making Duplicate Permutation
        
        HashSet<Integer> set = new HashSet<>();
        
        for(int i = pos ; i < n ; i++)
        {
            // If we have encountered the element before, we will simply skip the rest of iterations
            
            if(set.contains( nums[i] ))
                continue;
            
             // We insert nums[i] so that we don't create Duplicate Permutations
            
            set.add(nums[i]);
            
            // We create one Unique Permutation by swapping

            swap(pos , i, nums) ;

            // And we ask Recursion to handle rest of the task

            helper(pos + 1 , n , nums , ans) ;

            // But after we come back, we must backtrack and undo the changes we have done

            swap(pos , i, nums) ;
        }

        return ;
    }
    
    public void swap (int i, int j, int[] nums)
    {
        // Swaping the elements
        
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    public List<Integer> ConverttoArray(int[] nums)
    {
        // Converting the array into List
        
        List<Integer> ans = new ArrayList<>();
        for(int ele : nums)
            ans.add(ele);
        return ans;
    }
    
    public List<List<Integer>> permuteUnique(int[] nums) 
    {
        List<List<Integer>> ans = new ArrayList<>();

        helper(0 , nums.length , nums , ans) ;

        return ans ;
    }
}

/*
Time Complexity  : O(N * N!)
Space Complexity : O(N)
*/
