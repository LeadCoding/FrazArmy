#include <bits/stdc++.h>
void helper(int i, vector<int> &arr, vector<int> &subset, vector<vector<int>> &ans)
{
    // when we have traversed the entire arr[], then we should put arr into ans[]
    if (i >= arr.size())
    {
        ans.push_back(subset);
        return;
    }

    // pick the ith element
    subset.push_back(arr[i]);

    // picked ith element and recursion will find the remaining subsets with ith element
    helper(i + 1, arr, subset, ans);

    // firstly, we need to backtrack and undo the changes that we have made
    subset.pop_back();

    // ensure we don't pick any other occurrences ofi-th element in order to generate Unique Subsets 
    while (i + 1 < arr.size() && arr[i] == arr[i + 1]) i++;

    // currentIndex will now point to the Last Occurrence of ith Element
    // we ignored ith element and now recursion will do find the remaining subsets without the ith element
    // skip the ith element
    helper(i + 1, arr, subset, ans);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> subset;

    // to ensure our logic work,we need a sorted array
    sort(arr.begin(), arr.end());
    helper(0, arr, subset, ans);

    // this is specific to the given problem, they wanted each subset in sorted order
    sort(ans.begin(), ans.end());
    return ans;
}

/*
    time complexity : O(2^n)
    space complexity : O(n)
*/
