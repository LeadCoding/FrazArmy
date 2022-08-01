void helper(vector<int> &v, int i, vector<int> &subSet, vector<vector<int>> &ans)
{
    // base condition
    if (i == v.size())
    {
        ans.push_back(subSet);
        return;
    }

    // pick the ith element
    subSet.push_back(v[i]);
    helper(v, i + 1, subSet, ans);

    // backtrack & undo the changes that were made
    subSet.pop_back();

    // skip the ith element
    helper(v, i + 1, subSet, ans);
}

vector<vector<int>> pwset(vector<int> v)
{
    vector<vector<int>> ans;
    vector<int> subSet;
    helper(v, 0, subSet, ans);
    return ans;
}

/*
    time complexity : O(2^n)
    space complexity : O(n)
*/