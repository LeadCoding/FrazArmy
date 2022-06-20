public class Solution 
{
    public static boolean present(char[][] board, String word, int n, int m) 
    {
        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (word.charAt(0) == board[i][j]) 
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

    private static final int[] row = { 1, 0, -1, 0 };
    private static final int[] col = { 0, 1, 0, -1 };

    private static boolean search(char[][] board, String word, int n, int m, boolean[][] visited, int i, int j, int currentIndex) 
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
            if (r >= 0 && c >= 0 && r < m && c < n && !visited[c][r] && word.charAt(currentIndex) == board[c][r]) 
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
}