import java.util.*;
public class Solution 
{
    static void helper(ArrayList<Integer> v, int i, ArrayList<Integer> subSet, ArrayList<ArrayList<Integer>> ans)
    {
        // base condition
      
        if (i == v.size())
        {
            ans.add(new ArrayList(subSet));
            return;
        }

        // pick the ith element
      
        subSet.add(v.get(i));
        helper(v, i + 1, subSet, ans);

        // backtrack & undo the changes that were made
      
        subSet.remove(subSet.size()-1);

        // skip the ith element
      
        helper(v, i + 1, subSet, ans);
    }
	public static ArrayList<ArrayList<Integer>> pwset(ArrayList<Integer> arr)
    {
	    ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> subSet = new ArrayList<>();
        helper(arr, 0, subSet, ans);
        return ans;
	}
}

/*
    time complexity : O(2^n)
    space complexity : O(n)
*/
