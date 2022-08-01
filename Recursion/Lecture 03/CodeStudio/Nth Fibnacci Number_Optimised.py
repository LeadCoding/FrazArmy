def fib(n):
    
    # Base case
    if n < 2:
        return n
    
    # memoization | searching for "n" in memo, if available retriving it will save time. 
    # it'll save redundant calculations
    if n in memo:
        return memo[n]
    
    # storing calculated fibonaci numbers in memo, if it's not previously calculated
    memo[n-1] = fib(n-1)
    memo[n-2] = fib(n-2)
    
    # Formula for nth fibonachi number is, fib(n) = fib(n-1) + fib(n-2)
    return memo[n-1] + memo[n-2]
      
n = int(input())
 # memo is a dictionary in python | it's refered as a Hashmap is other lang
memo = {}
 # calling the function
print(fib(n))

"""
ALgorithm 
Time complexity : O(2**n)
Space complexity : O(n)

MEMOIZING
1. We have to create A dictionary: with key & value pair as follow | Key == n -> value == fib(n)
2. store the pair in dictionary for each recursive calls for fib(n) | memo[n] = fin(n)
3. At the begining of fib function after Base case, To avoid redundant calculation of fib(n) 
   search for key() -> n if already stored in "memo", If found return that value. 
   
EXAMPLE | To View redundant calculation in a recursive tree
Link >> https://realpython.com/fibonacci-sequence-python/
"""
   
