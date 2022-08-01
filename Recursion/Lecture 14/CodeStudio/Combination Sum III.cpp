void help(int i, int k, int sumTillNow, int n, vector<int> &subSet, vector<vector<int>> &ans)
{
    // base condition
    // if the sumTillNow becomes greater than n, then we don't need to proceed further
    if (sumTillNow > n)
        return;

    // base condition
    // if k becomes equal to zero(0) , then check if the sumTillNow is equal to n or not
    if (k == 0)
    {
        // if the sumTillNow is equal to n, then include the subset into ans[][]
        if (sumTillNow == n)
        {
            ans.push_back(subSet);
        }

        // else we simply return without including the subset
        return;
    }

    // base condition
    // if i becomes equal to 10, then we don't need to proceed any further
    if (i == 10)
        return;

    // pick the ith element
    sumTillNow += i;
    subSet.push_back(i);

    // ask recursion to do the rest of the task
    help(i + 1, k - 1, sumTillNow, n, subSet, ans);

    // backtrack and undo the changes that have been done
    sumTillNow -= i;
    subSet.pop_back();

    // skip ith element
    help(i + 1, k, sumTillNow, n, subSet, ans);
}
vector<vector<int>> combinationSum3(int k, int n)
{
    // Write your code here.
    vector<int> subSet;
    vector<vector<int>> ans;
    help(1, k, 0, n, subSet, ans);
    return ans;
}

/*
    time complexity: O(2^K)
    space complexity: O(K)
*/