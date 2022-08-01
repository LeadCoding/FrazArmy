/* This question is exactly similar to Combination Sum -I. 
The only difference is that we have duplicates inside the given vector arr[]
We need to skip the duplicate elements. Else they would generate Duplicate Combinations which we don't want
To skip the Duplicate Elements, we will sort arr[] and use a While Loop to skip all the Duplicate Elements
*/

class Solution {
private :
    
void help(int i, vector<int> &arr, int n, vector<int> &subSet, vector<vector<int>> &powerSet, int sum, int target) {
    
    // If sum is equal to target, we have reached a Valid Combination
    
    if(sum == target) 
    {
        powerSet.push_back(subSet) ;
        return;
    }
    
    // If at any moment, sum becomes greater than target, we don't need to proceed further
    
    if(sum > target) return ;
    
    // If we reach the end of arr[], we cannot go any further so we return back
    
    if(i == n) return;

    // Include the i-th Element into our Subset & Sum
    
    subSet.push_back(arr[i]) ;
    sum += arr[i] ;
    
    // Ask recursion to do rest of the task
    help(i + 1, arr, n, subSet, powerSet, sum, target) ;
    
    // Backtrack and undo the change we have done
    
    subSet.pop_back();
    sum -= arr[i];
    
    // Use the While Loop to skip all the duplicate occurrences of i-th Element
    
    while(i + 1 < arr.size() && arr[i] == arr[i + 1]) i++ ;
    
    // Don't pick the i-th Element and ask recursion to do rest of the task
    
    help(i + 1, arr, n, subSet, powerSet, sum, target) ;
}

    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
    vector<int> subSet ;
    vector<vector<int>> powerSet ;
    int sum = 0;
    int n = candidates.size() ;
    sort(candidates.begin(), candidates.end()) ;

    help(0, candidates, n, subSet, powerSet, sum, target) ;
        
    return powerSet ;
}
};

/* 
Time Complexity: O(2^N)
Space Complexity: O(N)
*/
