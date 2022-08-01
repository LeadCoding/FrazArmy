class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        def isPalindromeHelper(l, r, s):
            
            # Base case, checking if the left pointer crosses the right pointer, or overlaps then it's a palindrome
            if l >= r:
                return True
            
            # at any moment if the s[left] != s[right] stop and return Fasle
            if s[l] != s[r]:
                return False
            
            return isPalindromeHelper(l+1, r-1, s)
        
        charString = ""
        
        for char in s:
            
            # remoes value of indices other then character or digit
            if char.isalnum() == False:
                continue
                
            # skipping spaces    
            if char == " ":
                continue
                
            # converting upperCase to lowerCase
            if char.isupper():
                char = char.lower()
                
            # creating string only with characters by string concatination
            charString += char
        
        # recursive function call
        ans = isPalindromeHelper(0, len(charString)-1, charString)
        
        return ans
    
"""
Algorithm
Tc : O(n)
Sc : O(n)
"""