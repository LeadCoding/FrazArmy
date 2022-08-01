#include <bits/stdc++.h>
void helper(int pos, string &str, vector<string> &ans)
{
    // when we have traversed the entire str, then we should put str into ans[]
    if (pos >= str.size())
    {
        ans.push_back(str);
    }

    // Iterating from currentposition till size of str and trying to generate all possible Permutations 
    for (int i = pos; i < str.size(); i++)
    {
        // swapping the ith element with the current element
        swap(str[pos], str[i]);

        // ask recursion to do the remaining task
        helper(pos + 1, str, ans);

        // backtrack & undo the changes
        swap(str[pos], str[i]);
    }
}
vector<string> generatePermutations(string &str)
{

    // to keep the final result in store
    vector<string> ans;

    helper(0, str, ans);

    // Specific to this problem because we want the strings sorted in lexicographical order
    sort(ans.begin(), ans.end());
    return ans;
}

/* 
    time complexity : O(n * n!)
    space complexity : O(n)
*/