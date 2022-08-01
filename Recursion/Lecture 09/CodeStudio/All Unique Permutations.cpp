#include <bits/stdc++.h>
void helper(int pos, int n, vector<int> &arr, vector<vector<int>> &ans)
{
    // If we have traversed entire arr[], we have got an Unique Permutation this push it into the ans
    if (pos >= n)
    {
        ans.push_back(arr);
    }
    unordered_set<char> m;
    for (int i = pos; i < n; i++)
    {
        // First check whether we have already taken arr[i] in our Permutation or not
        if (m.find(arr[i]) != m.end())
            continue;

        // If not we insert it in our current unordered_set
        m.insert(arr[i]);

        // We use our simple swapping logic to generate all Permutations
        swap(arr[pos], arr[i]);

        // Ask recursion to do the remaining task
        helper(pos + 1, n, arr, ans);

        // Backtrack and undo the changes
        swap(arr[pos], arr[i]);
    }
}
vector<vector<int>> uniquePermutations(vector<int> &arr, int n)
{
    // Write your code here.
    vector<vector<int>> ans;

    // Call the Recursive function to generate all the Unique Permutations
    helper(0, n, arr, ans);

    sort(ans.begin(), ans.end());
    return ans;
}

/*
    time complexity : O(N * N!)
    space complexity : O(N)
*/
