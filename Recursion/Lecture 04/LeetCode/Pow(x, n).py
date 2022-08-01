class Solution:
    def myPow(self, x: float, n: int) -> float:
        
        # base case
        if n == 0:
            return 1
        
        # when n is negative then this if-statement will be execute
        if n < 0:
            x = 1 / x  
            n = abs(n)
            
        temp = self.myPow(x, n // 2)  # "//" is floor divisinon operator
        
        # if n is odd then we will have to multiply x
        if n % 2 == 1:
            return temp * temp * x
        
        else:
            return temp * temp
        
""" 
Algorithm
    
time complexity : O(log n)
space complexity : O(log n)
"""
