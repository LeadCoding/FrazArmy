import java.util.*;
public class Solution 
{
    static void help(int i, int n, int k, ArrayList<Integer> subSet, ArrayList<ArrayList<Integer>> ans)
    {
        // If k is equal to 0, we have generated a Valid Subset of K length

        if (k == 0)
        {
            ans.add(new ArrayList(subSet));
            return;
        }

        // If we don't have enough elements to make our subset, we shouldn't proceed further

        if (k > n - i + 1)
            return;

        // If i becomes greater than N, we should stop going forward

        if (i > n)
            return;

        // Our logic remains exactly same as Generating Subsets

        // Pick i-th Element

        subSet.add(i);

        // Ask Recursion to do the Rest of the Task

        help(i + 1, n, k - 1, subSet, ans);

        // Backtrack and undo the change
        
        subSet.remove(subSet.size()-1);

        // Don't pick the i-th Element

        help(i + 1, n, k, subSet, ans);
    }
    public static ArrayList<ArrayList<Integer>> combinations(int n, int k) 
    {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>() ;
        ArrayList<Integer> subSet = new ArrayList<>() ;

        help(1 , n , k , subSet , ans) ;

        return ans ;
    }

}

/*
Time Complexity  : O(2^N)
Space Complexity : O(N)
*/
