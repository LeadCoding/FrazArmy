def pow(X, N):

    # base case
    if N == 0:
        return 1
    
    # recurssion call
    temp = pow(X, N//2) 
    
    # if N is odd then we will have to multiply x
    if N%2 == 1:
        return temp*temp*X
    
    return temp*temp

"""
Algorithm 

time complexity : O(log n)
space complexity : O(log n)
"""
