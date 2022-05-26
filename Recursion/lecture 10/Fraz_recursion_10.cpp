#include<bits/stdc++.h>
void helper(vector<int> &v, int i, vector<int> &subSet, vector<vector<int>> &ans)
{
    if (i == v.size())
    {
        ans.push_back(subSet);
        return;
    }
    // include the ith element
    subSet.push_back(v[i]);
    helper(v, i + 1, subSet, ans);
    // not including the ith element
    subSet.pop_back();
    while (i + 1 < v.size() && v[i] == v[i + 1])
        i++;
    helper(v, i + 1, subSet, ans);
}


vector<vector<int>> uniqueSubsets(int n, vector<int> &v)
{
    vector<vector<int>> ans;
    vector<int> subSet;
    // sorting before calling the function 
    sort(v.begin(),v.end());
    helper(v, 0, subSet, ans);
    sort(ans.begin(),ans.end());
    return ans;
}
