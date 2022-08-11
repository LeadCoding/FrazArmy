import java.util.ArrayList;
public class Solution
{
    static void help(int i, int k, int sumTillNow, int n, ArrayList<Integer> subSet, ArrayList<ArrayList<Integer>> ans) 
    {
        // If the Sum-Till-Now becomes greater than n, we don't need to proceed further

        if(sumTillNow > n) 
            return ;

        // If k becomes equal to zero(0) , we need to check if the Sum-Till-Now is equal to n or not

        if(k == 0) 
        {
            // If the Sum-Till-Now is equal to n, we include the Subset into our ans

            if(sumTillNow == n) 
            {
                ans.add(new ArrayList(subSet)); 
            }

            // Else we simply return without including the Subset

            return;
        }

        // If i becomes equal to 10, we don't need to proceed any further

        if(i == 10) 
            return ;

        // We include the i-th Number into our Sum-Till-Now & also into our Subset

        sumTillNow += i ;
        subSet.add(i) ;

        // Ask Recursion to do the rest of the task

        help(i + 1, k - 1, sumTillNow, n, subSet, ans) ;

        // Backtrack and undo the change we have done

        sumTillNow -= i ;
        subSet.remove(subSet.size()-1) ;

        // We don't include the i-th Number and ask recursion to do the rest of the Combinations

        help(i + 1, k, sumTillNow, n, subSet, ans); 

    }
    static ArrayList<ArrayList<Integer>> combinationSum3(int k, int n)
    {
        ArrayList<Integer> subSet = new ArrayList<>();
        
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        help(1, k, 0, n, subSet, ans) ;

        return ans ;
    }
}

/* 
Time Complexity: O(2^N)
Space Complexity: O(K)
*/
