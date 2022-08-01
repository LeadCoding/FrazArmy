from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(10 ** 7)

"""
This question is based on reqSum Sum problem.   
We need to fill k buckets(using all the elements) of nums[]. Sum of each bucket should be same.
By doing a bit maths, we can easily calculate the reqSum of each bucket, which is, (totalSum / k)
we keep an array for sum of each partition and a boolean array to check whether an element 
is already taken into some partition or not.

"""

def canPartitionKSubsets(arr, n, K):
    
    def helper(taken, reqSum, curIdx, limitIdx):
        
        if subsetSum[curIdx] == reqSum:
            
            #  current index (K - 2) represents (K - 1) subsets of equal sum last partition will already remain with sum 'subset'
            
            if curIdx == K-2:
                return True
            
            # recursive call for next subsetition
            
            return helper(taken, reqSum, curIdx+1,n-1)
        
        # start from limitIdx and include elements into current partition
        
        for i in range(limitIdx, -1, -1):
            
            # if already taken, continue
            if taken[i]:
                continue
            tmp = subsetSum[curIdx]+arr[i]
            
            # if temp is less than subset then only include the element and call recursively
            if tmp <= reqSum:
                
                # mark the element and include into current partition sum
                taken[i] = True
                subsetSum[curIdx] += arr[i]
                nxt = helper(taken, reqSum, curIdx, i-1)
                
                # after recursive call unmark the element and remove from subsetition sum
                taken[i] = False
                subsetSum[curIdx] -= arr[i]
                
                if nxt:
                    return True
                
        return False
        
    
    # canPartitionKSubsets() scope varaibles 
    
    #  If K is 1, then complete array will be our answer
    
    if K == 1:
        return True
    
    # If total number of partitions are more than N, then division is not possible
    
    if n < K:
        return False
    # if array sum is not divisible by K then we can't divide array into K partitions
    
    arrSum = 0
    for i in range(len(arr)):
        arrSum += arr[i]
    
    if arrSum % K != 0:
        return False
    
    # the required sum of each subset = sum / K
    
    reqSum = arrSum // K
    
    # Initialize sum of each subset from 0
    
    subsetSum = [0 for i in range(K+1)]
    
    # mark all elements as not taken
    
    taken = [False for i in range(n)]
    
    # initialize first subset sum as last element of
    # array and mark that as taken
    subsetSum[0] = arr[n-1]
    taken[n-1] = True
    
    # call recursive method to check K-substitution condition
    
    return helper(taken, reqSum, 0, n-1)
    
"""
Time Complexity:  O(2^(N * K))
Space Complexity: O(N)
"""

# Taking input using fast I/0.
def takeInput():
    N = int(stdin.readline())
    arr = list(map(int, stdin.readline().strip().split(" ")))
    K = int(stdin.readline())
    return N, arr, K

# Main.
tc = int(input())
while tc > 0:
    N, arr, K = takeInput()
    ans = canPartitionKSubsets(arr, N, K)
    stdout.write(str(ans) + "\n")
    tc -= 1
