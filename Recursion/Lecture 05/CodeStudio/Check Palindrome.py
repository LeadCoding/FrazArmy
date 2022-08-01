def isPalindrome(s: str) -> bool:
        
    # helper function to check for palindrome
    def isPalindromeHelper(l, r, s):
        
        # Base case, checking if the left pointer crosses the right pointer, or overlaps then it's a palindrome
        if l >= r:
            return True
        
        # at any moment if the s[left] != s[right] stop and return Fasle
        if s[l] != s[r]:
            return False
        
        return isPalindromeHelper(l+1, r-1, s)
    
    # Recursive call
    return isPalindromeHelper(0, len(s)-1, s)
    
"""
Algorithm
Tc : O(n/2)
Sc : O(1) || O(n/2) stack memory

"""
