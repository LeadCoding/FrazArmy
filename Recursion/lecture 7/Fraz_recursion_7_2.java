import java.util.ArrayList;
public class Solution {
       static ArrayList<ArrayList<Integer>> ans=new ArrayList<>();
       static ArrayList<Integer> subSet=new ArrayList<Integer>();
    
    public static void helper(ArrayList<Integer> v, int i, ArrayList<Integer> subSet, ArrayList<ArrayList<Integer>> ans)
    {
        if (i == v.size())
        {
            ans.add(new ArrayList<Integer>(subSet));
            return;
        }
        // include the ith element
        subSet.add(v.get(i));
        helper(v, i + 1, subSet, ans);
        // not including the ith element
        subSet.remove(subSet.size() - 1);
        helper(v, i + 1, subSet, ans);
}
    
	public static ArrayList<ArrayList<Integer>> pwset(ArrayList<Integer> v) {
		// WRITE YOUR CODE HERE
     
        helper(v, 0, subSet, ans);
        return ans;
	}
}

