#include <bits/stdc++.h>
using namespace std;

void help(int i, vector<int> &arr, int B, int sumTillNow, vector<int> &subSet, vector<vector<int>> &ans)
{
    // base condition
    // if sumTillNow == required sum (B) this means that we have reached a Valid Combination thus include it into the vector<vector<int>> ans
    if (sumTillNow == B)
    {
        ans.push_back(subSet);
        return;
    }

    // base condition
    // if sumTillNow > required sum (B) this means that we are exceeding the limit of required sum therefore simply return
    if (sumTillNow > B)
        return;

    // base condition
    // if current Index (i) is exceeding the array size then return
    if (i >= arr.size())
        return;

    // skip the ith element
    help(i + 1, arr, B, sumTillNow, subSet, ans);

    // pick the ith element
    sumTillNow += arr[i];
    subSet.push_back(arr[i]);

    // ask recursion to do the remaining task
    help(i, arr, B, sumTillNow, subSet, ans);

    // backtrack & undo the changes that were made while picking the ith element
    sumTillNow -= arr[i];
    subSet.pop_back();
}

vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    vector<int> subSet;
    int sumTillNow = 0;
    vector<vector<int>> ans;

    // as elements in each combination need to be sorted, therefore we are sorting ARR[] vector to ensure that our combinations are also generated in sorted manner
    sort(ARR.begin(), ARR.end());
    help(0, ARR, B, sumTillNow, subSet, ans);
    return ans;
}

/*
Time Complexity: O(Exponential)
Space Complexity: O(TargetSum) {Recursive Stack Space} 
*/
