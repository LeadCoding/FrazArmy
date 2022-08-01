/* This problem asks us to find the Max Length of Concatenated strings present inside arr[]
All the concatenated strings should have unique characters
*/

class Solution {
private:
    
bool compare(vector<int> &selected, string &currString)
{
    // Before checking with selected[], we need to check if currString has repeating characters or Not

    // This is done using selfCheck vector which checks if currString has repeating characters or Not
    
    vector<int> selfCheck(26, 0); 
    
    for (int i = 0; i < currString.size(); i++)
    {
        // As all the characters are present in LowerCase, we can use currString[i] - 'a' to map every character to a corresponding index (as discussed thoroughly in the lecture)
      
        // If selfCheck[currString[i] - 'a'] is already taken, it means currString has repeating characters
        
        if (selfCheck[currString[i] - 'a'] == 1)
            return false ;

        // Else we mark all the characters inside SelfCheck as 1
        
        selfCheck[currString[i] - 'a'] = 1 ;
    }

    // The second Loop ensures whether the characters of currString has already been selected or not
    
    for (int i = 0; i < currString.size(); i++)
    {
        // If currString[i] - 'a' is already taken, it means we cannot take currString, thus we return false
        
        if (selected[currString[i] - 'a'] == 1)
            return false ;
    }

    
    // At the end, if currString doesn't contain repeating characters AND it's characters have already not been taken yet, we return true indicating currString can be chosen now
    
    return true ;
}


int help(int i, vector<string> &arr, vector<int> &selected, int len)
{
    // If we reach till the end of arr[], we need to return the max Length we have taken till now
    
    if (i == arr.size() )
    {
        return len ;
    }

    string currString = arr[i] ;

    // If currString contains Duplicate Characters or it's characters have already been taken, we have no option but to skip curr String and move to next Index
    
    if (compare(selected, currString) == false)
    {
        // skip the currString
        return help(i + 1, arr, selected, len) ;
    }

    // Else we have two options, One to include CurrString OR another option is to Skip CurrString
    
    else
    {
        // If we pick the currString, all it's characters must be marked as taken in selected [] vector
        
        for (int j = 0; j < currString.size(); j++)
        {
            selected[currString[j] - 'a'] = 1 ;
        }

        // Increase the length by currString.size() 
        
        len += currString.size() ;

        // Ask Recursion to do rest of task
        
        int op1 = help(i + 1, arr, selected, len) ; 

        // Backtrack and unmark all the characters of currString as NOT TAKEN in selected[] vector
        
        for (int j = 0; j < currString.size(); j++)
        {
            selected[currString[j] - 'a'] = 0 ;
        }

        // As we are not including currString, we should decrease len by currString.size()
        
        len -= currString.size() ;

        // Ask recursion to do rest of the task
        
        int op2 = help(i + 1, arr, selected, len) ;

        // Lastly, we will return the max of (op1 , op2) whichever brings the Longest Length
        
        return max(op1, op2) ;
    }
}

public:
    int maxLength(vector<string>& arr) {
        
    // selected [] vector will keep track of all the characters which have been taken yet
        
    vector<int> selected(26, 0) ; 

    return help(0, arr, selected, 0);
        
}
};

/*
    Time Complexity:  O(K * 2^N)
    Space Complexity: O(N)
*/
