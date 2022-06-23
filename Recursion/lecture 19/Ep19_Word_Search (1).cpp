#include<bits/stdc++.h>
using namespace std;

bool search(int i, int j, vector<vector<char>> &board, string &word, int k, int n, int m) {
    
    if(k == word.size()) return true;
    if(i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k]) return false;
    char ch = board[i][j];
    board[i][j] = '#';
    bool op1 = search(i + 1, j, board, word, k + 1, n, m);
    bool op2 = search(i - 1, j, board, word, k + 1, n, m);
    bool op3 = search(i, j + 1, board, word, k + 1, n, m);
    bool op4 = search(i, j - 1, board, word, k + 1, n, m);
    board[i][j] = ch;

    return (op1 || op2 || op3 || op4);

}

bool present(vector<vector<char>> &board, string word, int n, int m) {
    // Write your code here
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++) {
            if(board[i][j] == word[0]) {
                if(search(i, j, board, word, 0, n, m)) return true;
            }
        } 
    }
    return false;
}
