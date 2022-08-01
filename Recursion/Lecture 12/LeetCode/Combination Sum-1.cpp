/* The idea of this question is to return all such combinations whose individual sum is equal to Target
We use the same logic as generating Combinations - only difference is that we calculate the sum of each subset every time.
We can use an element as many times as we want
Our given vector arr[] contains only Unique Subsets that's for sure
*/

class Solution {
private :
    
void help(int i, vector<int> &arr, int B, int sumTillNow, vector<int> &subSet, vector<vector<int>> &ans) {
    
    // If our sumTillNow is equal to B(Target), we have reached a Valid Combination
    
    if(sumTillNow == B) 
    {
        ans.push_back(subSet);
        return;
    }

    // If our sumTillNow exceeds B(Target), there's no point in proceeding further
    
    if(sumTillNow > B) return;

    // If we have reached the end of arr[], we cannot go further as we don't have anymore elements
    
    if(i >= arr.size()) return;

    // We skip the i-th element 
    
    help(i + 1, arr, B, sumTillNow, subSet, ans);
    
    // We include the i-th into our sumTillNow 
    
    sumTillNow += arr[i];
    
    // We push the i-th Element into our subSet
    
    subSet.push_back(arr[i]);
    
    // We keep on the i-th Element & ask recursion to do rest of the task
    
    help(i, arr, B, sumTillNow, subSet, ans);
    
    // When we come back, we need to backtrack & undo the change
    
    sumTillNow -= arr[i];
    
    subSet.pop_back();
}    

    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
    vector<int> subSet;
        
    int sumTillNow = 0;
        
    vector<vector<int>> ans;
        
    // This sorting ensures all the elements in each Subset are also in sorted order
        
    sort(candidates.begin(), candidates.end());
        
    help(0, candidates, target, sumTillNow, subSet, ans);
        
    return ans;
}
};

/* 
Time Complexity: O(Exponential) or O(2^n)
Space Complexity: O(n+m) n for stack memory and m is the size of ans array 
*/
