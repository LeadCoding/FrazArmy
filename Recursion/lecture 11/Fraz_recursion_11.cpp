
void help(int i, int n, int k, vector<int> &subSet, vector<vector<int>> &ans)
{
    if (k == 0)
    {
        ans.push_back(subSet);
        return;
    }
    if (k > n - i + 1)
        return;
    if (i > n)
        return;
    // take the ith ele
    subSet.push_back(i);
    help(i + 1, n, k - 1, subSet, ans);
    // skip the ith ele
    subSet.pop_back();
    help(i + 1, n, k, subSet, ans);
}

vector<vector<int>> combinations(int n, int k)
{
    vector<int> subSet;
    vector<vector<int>> ans;
    help(1, n, k, subSet, ans);
    return ans;
}
