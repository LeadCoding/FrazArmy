void help(int i, int n, int k, vector<int> &subSet, vector<vector<int>> &ans)
{
    // base condition
    if (k == 0)
    {
        ans.push_back(subSet);
        return;
    }

    // if the required element (k) is greater than the remaining element (n - i + 1) in that case return because we are in the wrong direction & there is no point going any further down in this direction
    if (k > n - i + 1)
        return;
        
    if (i > n)
        return;

    // pick the ith element
    subSet.push_back(i);

    // ask recursion to do the remaining task
    help(i + 1, n, k - 1, subSet, ans);

    // backtrack & undo the changes that has been made
    subSet.pop_back();

    // skip the ith element
    help(i + 1, n, k, subSet, ans);
}

vector<vector<int>> combinations(int n, int k)
{
    vector<int> subSet;
    vector<vector<int>> ans;
    help(1, n, k, subSet, ans);
    return ans;
}

/*
    time complexity : O(2^n)
    space complexity : O(n)
*/
