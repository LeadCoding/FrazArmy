
/* The idea of this question is to return all such combinations whose individual sum is equal to Target
We use the same logic as generating Combinations - only difference is that we calculate the sum of each subset every time.
We can use an element as many times as we want
Our given array arr[] contains only Unique Subsets that's for sure
*/

class Solution 
{
    public void help(int i, int[] arr, int B, int sumTillNow, List<Integer> subSet, List<List<Integer>> ans) 
        {

        // If our sumTillNow is equal to B(Target), we have reached a Valid Combination

        if(sumTillNow == B) 
        {
            ans.add(new ArrayList(subSet));
            return;
        }

        // If our sumTillNow exceeds B(Target), there's no point in proceeding further

        if(sumTillNow > B) return;

        // If we have reached the end of arr[], we cannot go further as we don't have anymore elements

        if(i >= arr.length) return;

        // We skip the i-th element 

        help(i + 1, arr, B, sumTillNow, subSet, ans);

        // We include the i-th into our sumTillNow 

        sumTillNow += arr[i];

        // We push the i-th Element into our subSet

        subSet.add(arr[i]);

        // We keep on the i-th Element & ask recursion to do rest of the task

        help(i, arr, B, sumTillNow, subSet, ans);

        // When we come back, we need to backtrack & undo the change

        sumTillNow -= arr[i];

        subSet.remove(subSet.size()-1);
    }    
    public List<List<Integer>> combinationSum(int[] candidates, int target) 
    {
        List<Integer> subSet = new ArrayList<>();
        
        int sumTillNow = 0;

        List<List<Integer>> ans = new ArrayList<>();

        // This sorting ensures all the elements in each Subset are also in sorted order

        Arrays.sort(candidates);

        help(0, candidates, target, sumTillNow, subSet, ans);

        return ans;
    }
}

/* 
Time Complexity: O(Expoential) or O(2^n)
Space Complexity: O(n+m) n for stack memory and m = size of ans array 
*/
