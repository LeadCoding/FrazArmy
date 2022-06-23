#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n, vector<vector<int>> &chessBoard) {

    int tempI = i;
    while(tempI >= 0) {
        if(chessBoard[tempI][j] == 1) return false;
        tempI--;
    }

    tempI = i;
    int tempJ = j;
    while(tempI >= 0 && tempJ < n) {
        if(chessBoard[tempI][tempJ] == 1) return false;
        tempI--;
        tempJ++;
    }

    tempI = i;
    tempJ = j;
    while(tempI >= 0 && tempJ >= 0) {
        if(chessBoard[tempI][tempJ] == 1) return false;
        tempI--;
        tempJ--;
    }

    return true;

}

void help(int i, int n, vector<vector<int>> &chessBoard, vector<vector<int>> &ans) {
    if(i == n) {
        vector<int> temp;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                temp.push_back(chessBoard[j][k]);
            }
        } 
        ans.push_back(temp);
        return;
    }
    for(int j = 0; j < n; j++) {
        if(isSafe(i, j, n, chessBoard)) {
            chessBoard[i][j] = 1;
            help(i + 1, n, chessBoard, ans);
            chessBoard[i][j] = 0;
        }
    } 
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> chessBoard(n, vector<int>(n, 0));
    help(0, n, chessBoard, ans);
    return ans;
}
