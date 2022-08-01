def fib(n):
    
    # Base case
    if n == 0:
        return 0
    if n == 1 or n == 2:
        return 1
    
    
    
    ans1 = fib(n -1)  # recursion call that will give us the (n-1)th fibo number
    ans2 = fib(n - 2) # recursion call that will give us the (n-2)th fibo number
    return ans1 + ans2     # will return the addition of (n-1)th & (n-2)th fibo number which is the nth fibo number
    
n = int(input())
print(fib(n)) # calling the function

"""ALgorithm 
Time complexity : O(2**n)
Space complexity : O(n)
"""
