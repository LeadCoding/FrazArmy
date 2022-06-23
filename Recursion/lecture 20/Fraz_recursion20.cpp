#include <bits/stdc++.h>
using namespace std;

void help(int i, int j, int n, vector<vector<int>> &arr, string &path, vector<string> &ans) {
    if(i < 0 || j < 0 || i == n || j == n || arr[i][j] == 0) {
        return;
    }
    else if(i == n - 1 && j == n - 1) {
        ans.push_back(path);
        return;
    }
    else {
        arr[i][j] = 0;

        path.push_back('D');
        help(i + 1, j, n, arr, path, ans);
        path.pop_back();
        
        path.push_back('L');
        help(i, j - 1, n, arr, path, ans);
        path.pop_back();

        path.push_back('R');
        help(i, j + 1, n, arr, path, ans);
        path.pop_back();

        path.push_back('U');
        help(i - 1, j, n, arr, path, ans);
        path.pop_back(); 
        
        arr[i][j] = 1;
    }
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    string path;
    help(0, 0, n, arr, path, ans);  
    return ans;
}
