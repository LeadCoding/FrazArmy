/*  
 NOTE:
 The Question is exactly similar to checking a Palindrome
 Only difference is that we need to create a new string which contains only AlphaNumeric characters and all alphabets shoould be in Lower Case only
*/

class Solution {    
private :
bool isPalindromeHelper(int l , int r , string &s)
{
    // While checking if our left pointer crosses our right pointer, it indicates the string is Palindrome
    
    if(l >= r)
     return true ;
    
    // At any moment if s[l] != s[r], we are sure it's not an Palindrome
    
    if(s[l] != s[r])
     return false ;
    
    // Asking recursion to do rest of the task
    
    return isPalindromeHelper(l + 1 , r - 1 , s) ;
}
    
public:
    bool isPalindrome(string s) {
        
    // We need to create a seperate string devoid of spaces and Non-Alphanumeirc Values
        
    string str = "" ;
        
    for(char ch : s)
    {
        // isalnum(ch) returns true if the character is a digit or alpbhabet else returns false
        
        if(isalnum(ch) == false)
         continue ;
        
        // If ch is equal to white space, we don't include it in our new string
        
        if(ch == ' ')
         continue ;
        
        // If ch is in Upper-Case, we can convert it in Lower Case easily by adding 32 to it's ASCII Value
        
        if(isupper(ch) )
         ch = ch + 32 ;
        
        // At the end, we push ch into our new string
        
        str.push_back(ch) ;
    
    }
      
    // If our new string is still empty, we directly return true
        
    if(str.size() == 0)
     return true ;
        
    bool ans = isPalindromeHelper(0 , str.size() - 1 , str) ;
        
    return ans ;
    
}    
};

/*  Time Complexity: O(N) 
    Space Complexity: O(N)
*/
