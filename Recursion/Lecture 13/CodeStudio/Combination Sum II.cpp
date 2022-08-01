
#include <bits/stdc++.h>
using namespace std;

void help(int i, vector<int> &arr, int n, vector<int> &subSet, vector<vector<int>> &powerSet, int sum, int target)
{
    // base condition
    // when sum == target this means that we have reached a Valid Combination thus include it into the vector<vector<int>> powerSet
    if (sum == target)
    {
        powerSet.push_back(subSet);
        return;
    }

    // base condition
    // when sum > target this means that we are exceeding the limit of the required sum (target) therefore simply return
    if (sum > target)
        return;

    // base condition
    // if current Index (i) is exceeding the array size then return
    if (i == n)
        return;

    // pick the ith element
    subSet.push_back(arr[i]);
    sum += arr[i];

    // ask recursion to do the remaining task
    help(i + 1, arr, n, subSet, powerSet, sum, target);

    // backtrack & undo the changes that were made while picking the ith element
    subSet.pop_back();
    sum -= arr[i];

    // loop to ensure that we don't pick any other occurrences of ith element
    while (i + 1 < arr.size() && arr[i] == arr[i + 1])
        i++;

    // skip the ith element
    help(i + 1, arr, n, subSet, powerSet, sum, target);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<int> subSet;
    vector<vector<int>> powerSet;
    int sum = 0;

    // as we have to bring all the similar elements together therefore we need to sort arr[]
    // now as all the similar elements comes together therefore we will be able to ignore all the duplicate occurences of elements
    sort(arr.begin(), arr.end());
    help(0, arr, n, subSet, powerSet, sum, target);
    return powerSet;
}

/*
    time complexity : O(2^n)
    space complexity : O(n)
*/