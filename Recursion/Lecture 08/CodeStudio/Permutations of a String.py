def generatePermutations(str):    
    
    # Swap API | As sting in python is imutable we have to take use of extra space using an list to swap the indices, 
    def swap(i, j, s):
        # Converting string to a list of string[i] where 0<= i <= len(s)-1
        arr = list(s)
        # Swaping in the list
        arr[i], arr[j] = arr[j], arr[i]
        # concatinating the swaped indece to a empty string
        s = ""
        for i in arr:
            s += i
        return s
    
    def helper(pos, str, ans, n):
        
        # If we have reached the end of str, we have found a Valid Permutations of str
        if pos >= len(str):
            # appending a copy of str, else it wold be passed by referemced, 
            # any change to str will change the appended ans. Don't worry about the extra space, Garbage 
            # collector will handel the extra space
            ans.append(str[:])
            return
        
        # Otherwise we iterate over all the other elements and try to generate Permutations by swapping str[pos] with str[i]
        
        for i in range(pos, len(str)):
            
            # We create one Unique Permutation by swapping str[i] with str[pos]
            
            str = swap(pos, i, str)

            # And we ask Recursion to handle rest of the task
            
            helper(pos+1, str, ans, n)
            
            # But after we come back, we must backtrack and undo the changes we have done
            
            str = swap(pos, i, str)
    
    ans = []
    n = len(str)
    helper(0, str, ans, n)
    return sorted(ans)
        
"""
Time Complexity  : O(N * N!)
Space Complexity : O(N)
"""
