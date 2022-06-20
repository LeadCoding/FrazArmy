#include <bits/stdc++.h>
using namespace std;

void help(int i, int k, int sumTillNow, int n, vector<int> &subSet, vector<vector<int>> &ans) {
    
    if(k == 0) {
        if(sumTillNow == n) {
            ans.push_back(subSet);
        }
        return;
    }
    if(i == 10) return;
    sumTillNow += i;
    subSet.push_back(i);
    help(i + 1, k - 1, sumTillNow, n, subSet, ans);
    sumTillNow -= i;
    subSet.pop_back();
    help(i + 1, k, sumTillNow, n, subSet, ans); 

}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> subSet;
    vector<vector<int>> ans;
    help(1, k, 0, n, subSet, ans);
    return ans;
}
