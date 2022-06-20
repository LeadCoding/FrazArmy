#include <bits/stdc++.h>
using namespace std;

void help(int i, vector<int> &arr, int B, int sumTillNow, vector<int> &subSet, vector<vector<int>> &ans) {
    
    if(sumTillNow == B) {
        ans.push_back(subSet);
        return;
    }
    if(sumTillNow > B) return;

    if(i >= arr.size()) return;

    help(i + 1, arr, B, sumTillNow, subSet, ans);

    sumTillNow += arr[i];
    subSet.push_back(arr[i]);
    help(i, arr, B, sumTillNow, subSet, ans);
    sumTillNow -= arr[i];
    subSet.pop_back();
}

vector<vector<int>> combSum(vector<int>& ARR, int B) {
    vector<int> subSet;
    int sumTillNow = 0;
    vector<vector<int>> ans;
    sort(ARR.begin(), ARR.end());
    help(0, ARR, B, sumTillNow, subSet, ans);
    return ans;
}
