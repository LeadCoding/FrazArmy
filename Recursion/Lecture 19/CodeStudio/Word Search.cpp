/* In this problem, we need to search if a given word exists inside a board[][] of characters
From one cell, we can move into it's 4 adjacent cells in the following directions - Down , Right , Up , Left
We cannot use one cell for more than once. Thus, backtracking comes into the picture
*/

bool search(int i , int j , int n , int m , vector<vector<char>> &board , string &word , int k)
{
    // If k is equal to the given word's length, it means every character of word is present inside board[][], so we return true
    
    if(k == word.size() )
       return true ;
    
    // If we are moving outside the board's boundary or if board[i][j] is not equal to word[k] , we return false
    
    if(i < 0 || j < 0 || i == n || j == m  || board[i][j] != word[k])
        return false ;
    
    // We store the Character present in the current Cell inside ch variable 
    
    char ch = board[i][j] ;
    
    // We change board[i][j] to # so that we don't visit the Same Cell again
    
    board[i][j] = '#' ;
    
    // We move in Downward direction
    
    bool op1 = search(i + 1 , j , n , m , board , word , k + 1) ;
    
    // We move in Rightward direction
    
    bool op2 = search(i , j + 1 , n , m , board , word , k + 1) ;
    
    // We move in Upward direction
    
    bool op3 = search(i - 1 , j , n , m , board , word , k + 1) ;
    
    // We move in Leftward direction
    
    bool op4 = search(i , j - 1 , n , m , board , word , k + 1) ;
    
    // We backtrack and change the value of board[i][j] to it's original character stored in ch variable
    
    board[i][j] = ch ;
    
    // As we need to find the word, no matter from which direction we get it, so we return (op1 OR op2 OR op3 OR op4)
    
    return op1 || op2 || op3 || op4 ;
}


bool present(vector<vector<char>> &board, string word, int n, int m) 
{
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            // We start checking only if board[i][j] matches with word[0]
            
            if(board[i][j] == word[0] )
            {
                // If our search results return True, we directly return true 
                
                if(search(i , j , n , m , board , word , 0) )
                    return true ;
            }
        }
    }
    
    // Otherwise, if we searched the entire matrix and still didn't find the word, we return false 
    
    return false ;
}

/*
Time Complexity:  O(N * M * 4^K)
Space Complexity: O(K)
K = word.size()
*/
