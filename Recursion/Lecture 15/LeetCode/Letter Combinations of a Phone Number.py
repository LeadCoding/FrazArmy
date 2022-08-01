"""
This question requries us to print all Valid Combinations of the given string digits which comprises of digits from 2 to 9.
The only thing we require extra in this question is to map all the letter combinations of the phone number to its corresponding digits.
The rest part of the question remains exactly same

# Hypothesis:
takes digits as input then appends all possible combination of the digits and the maped strings in the particular digit.

digit == string

choise diagraam:
1. 1 char can be choosen only once if it's from one number 
2. after choosing 1 char from a digit move i pointer and search for next char in digit and add all combination of the chars in the next dgit.
3. Continue it till i pointer is == len(digits) *********** BASE CASE ************* 

"""

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        def helper(i):
            
            # If i has reached till the end of digits, we have reached a Valid Combination
            # We should include it into ans[][] and return back
            
            if i == len(digits):
                
                # converting the comb [] to a string, then storing it to ans [] | As it'll be more dificult to push and pop() in a string, becuause strings are immutable in python
                
                new = ""
                for j in comb:
                    new += j
                ans.append(new)
                return
            
            # j will take care for the iterating over each chars in numCharMap.values() in a particular key "digit[i]"
            
            for j in range(len(numCharMap[digits[i]])):
            
                # picking the jth char from ith digit from the numCharMap
                
                comb.append(numCharMap[digits[i]][j])
                
                #  Ask recursion to do rest of the task
                
                helper(i+1)
                
                # Backtrack and undo the change we have already done
                
                comb.pop()
                            
        
        # As per the problem, for an empty string, we need to return an empty array
        if not digits:
            return []
        
        # To solve this question, we need to map all the letters of a particular digit with it's corresponding digit. This is done with the help of a dictionary.
        
        numCharMap = {  "2" : "abc", 
                        "3" : "def", 
                        "4" : "ghi",
                        "5" : "jkl", 
                        "6" : "mno",
                        "7" : "pqrs",
                        "8" : "tuv",
                        "9" : "wxyz"}
        
        ans = []
        comb = []
        
        helper(0)
        
        return ans
    
"""
Time Complexity: O(3^N)
Space Complexity: O(N)
"""
