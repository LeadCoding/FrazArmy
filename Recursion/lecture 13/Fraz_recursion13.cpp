
#include <bits/stdc++.h>
using namespace std;

void help(int i, vector<int> &arr, int n, vector<int> &subSet, vector<vector<int>> &powerSet, int sum, int target) {
    
    if(sum == target) {
        powerSet.push_back(subSet);
        return;
    }
    if(sum > target) return;
    if(i == n) return;

    subSet.push_back(arr[i]);
    sum += arr[i];
    help(i + 1, arr, n, subSet, powerSet, sum, target);
    subSet.pop_back();
    sum -= arr[i];

    while(i + 1 < arr.size() && arr[i] == arr[i + 1]) i++;
    help(i + 1, arr, n, subSet, powerSet, sum, target);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target) {
	vector<int> subSet;
    vector<vector<int>> powerSet;
    int sum = 0;
    sort(arr.begin(), arr.end());

    help(0, arr, n, subSet, powerSet, sum, target);
    return powerSet;
}
