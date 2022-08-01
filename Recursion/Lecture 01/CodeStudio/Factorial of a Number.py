# Your code goes here
# this function fac() will return us the factorial of the number n
def fac(n):
    if n == 0:
        return 1
        
    # recursion call
    return n*fac(n-1)  


n = int(input())
if n < 0:
    print("Error")
else:
    print(fac(n))


""" 
    time complexity: O(n)
    space complexity: O(n) 
"""

