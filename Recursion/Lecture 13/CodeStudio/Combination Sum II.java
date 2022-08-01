import java.util.ArrayList;
import java.util.*;
public class Solution 
{
    static void help(int i, ArrayList<Integer> arr, int n, ArrayList<Integer> subSet, ArrayList<ArrayList<Integer>> powerSet, int sum, int target) 
    {
    
        // If sum is equal to target, we have reached a Valid Combination

        if(sum == target) 
        {
            powerSet.add(new ArrayList(subSet)) ;
            return;
        }

        // If at any moment, sum becomes greater than target, we don't need to proceed further

        if(sum > target) return ;

        // If we reach the end of arr, we cannot go any further so we return back

        if(i == n) return;

        // Include the i-th Element into our Subset & Sum

        subSet.add(arr.get(i)) ;
        sum += arr.get(i) ;

        // Ask recursion to do rest of the task
        help(i + 1, arr, n, subSet, powerSet, sum, target) ;

        // Backtrack and undo the change we have done

        subSet.remove(subSet.size()-1);
        sum -= arr.get(i);

        // Use the While Loop to skip all the duplicate occurrences of i-th Element

        while(i + 1 < arr.size() && arr.get(i) == arr.get(i+1)) i++ ;

        // Don't pick the i-th Element and ask recursion to do rest of the task

        help(i + 1, arr, n, subSet, powerSet, sum, target) ;
    }
    public static ArrayList<ArrayList<Integer>> combinationSum2(ArrayList<Integer> arr, int n, int target)
    {
        ArrayList<Integer> subSet = new ArrayList<>() ;
        ArrayList<ArrayList<Integer>> powerSet = new ArrayList<>() ;
        int sum = 0;
        Collections.sort(arr) ;

        help(0, arr, n, subSet, powerSet, sum, target) ;

        return powerSet ;
    }
}

/* 
Time Complexity: O(2^N)
Space Complexity: O(N)
*/
