row = [ 1, 0, -1, 0 ]
col = [ 0, 1, 0, -1 ]

def search(board, word, n, m, visited, i, j, currentIndex):

    if (currentIndex >= len(word)):
        return True

    visited[i][j] = True

    for move in range(4):
        r = j + row[move]
        c = i + col[move]

        if (r >= 0 and c >= 0 and r < m and c < n and visited[c][r]==False and word[currentIndex] == board[c][r]): 
            if (search(board, word, n, m, visited, c, r, currentIndex + 1)):
                return True

    visited[i][j] = False
    return False

def present(board, word, n, m):
    
    visited=[[False for i in range(m)] for j in range(n)]

    for i in range(n):
        for j in range(m):
            if (word[0] == board[i][j]):
                if (search(board, word, n, m, visited, i, j, 1)):
                    return True

    return False