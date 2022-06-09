vector<int> row = { 1, 0, -1, 0 };
vector<int> col = { 0, 1, 0, -1 };

bool search(vector<vector<char>> &board, string &word, int n, int m, vector<vector<bool>> &visited, int i, int j, int currentIndex) 
{
    if (currentIndex >= word.length()) 
    {
        return true;
    }

    visited[i][j] = true;
    for (int move = 0; move < 4; move++) 
    {
        int r = j + row[move];
        int c = i + col[move];
        if (r >= 0 && c >= 0 && r < m && c < n && !visited[c][r] && word[currentIndex] == board[c][r]) 
        {
            if (search(board, word, n, m, visited, c, r, currentIndex + 1)) 
            {
                return true;
            }

        }
    }

    visited[i][j] = false;
    return false;

}

bool present(vector<vector<char>> &board, string word, int n, int m) 
{
    vector<vector<bool>> visited(n, vector<bool>(m));

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (word[0] == board[i][j]) 
            {

                if (search(board, word, n, m, visited, i, j, 1)) 
                {
                    return true;
                }

            }
        }
    }

    return false;

}