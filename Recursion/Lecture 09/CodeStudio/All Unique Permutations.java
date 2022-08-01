import java.util.*;
public class Solution 
{
    public static void helper(int pos , int n , ArrayList<Integer> nums , ArrayList<ArrayList<Integer>> ans)
    {
        // If we have reached the end of nums, we have found a Valid Permutations of nums

        if(pos >= n)
        {
            ans.add(new ArrayList(nums)) ;
            return ;
        }

        // Otherwise we iterate over all the other elements and try to generate Permutations by swapping element at pos with element at i

        // Hashset ensures we are not taking duplicates and thus not making Duplicate Permutation
        
        HashSet<Integer> set = new HashSet<>();
        
        for(int i = pos ; i < n ; i++)
        {
            // If we have encountered the element before, we will simply skip the rest of iterations
            
            if(set.contains( nums.get(i) ))
                continue;
            
             // We insert nums[i] so that we don't create Duplicate Permutations
            
            set.add(nums.get(i));
            
            // We create one Unique Permutation by swapping

            Collections.swap( nums, pos , i) ;

            // And we ask Recursion to handle rest of the task

            helper(pos + 1 , n , nums , ans) ;

            // But after we come back, we must backtrack and undo the changes we have done

            Collections.swap( nums, pos , i) ;
        }

        return ;
    }
        
    public static ArrayList<ArrayList< Integer >> uniquePermutations(ArrayList<Integer> arr, int n) 
    {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        
        helper(0 , arr.size() , arr , ans) ;

        return ans ;
    }
}

