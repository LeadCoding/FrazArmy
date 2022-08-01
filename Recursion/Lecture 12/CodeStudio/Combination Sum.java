import java.util.*;
public class Solution 
{
    static void help(int i, ArrayList<Integer> arr, int B, int sumTillNow, ArrayList<Integer> subSet, ArrayList<ArrayList<Integer>> ans) 
        {

        // If our sumTillNow is equal to B(Target), we have reached a Valid Combination

        if(sumTillNow == B) 
        {
            ans.add(new ArrayList(subSet));
            return;
        }

        // If our sumTillNow exceeds B(Target), there's no point in proceeding further

        if(sumTillNow > B) return;

        // If we have reached the end of arr, we cannot go further as we don't have anymore elements

        if(i >= arr.size()) return;

        // We skip the i-th element 

        help(i + 1, arr, B, sumTillNow, subSet, ans);

        // We include the i-th into our sumTillNow 

        sumTillNow += arr.get(i);

        // We push the i-th Element into our subSet

        subSet.add(arr.get(i));

        // We keep on the i-th Element & ask recursion to do rest of the task

        help(i, arr, B, sumTillNow, subSet, ans);

        // When we come back, we need to backtrack & undo the change

        sumTillNow -= arr.get(i);

        subSet.remove(subSet.size()-1);
    }    
	public static ArrayList<ArrayList<Integer>> combSum(ArrayList<Integer> arr, int b) 
    {
        ArrayList<Integer> subSet = new ArrayList<>();
        
        int sumTillNow = 0;

        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        // This sorting ensures all the elements in each Subset are also in sorted order

        Collections.sort(arr);

        help(0, arr, b, sumTillNow, subSet, ans);

        return ans;
	}
}

/* 
Time Complexity: O(Expoential) or O(2^n)
Space Complexity: O(n+m) n for stack memory and m = size of ans array 
*/
