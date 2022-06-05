# Approach 1 --
from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(10 ** 7)

def canPartitionKSubsetsHelper(nums, K, vis, targetSubsetSum, curSubsetSum, checkIdx):
	if (K == 0):
		return True

	if (curSubsetSum == targetSubsetSum):
		return canPartitionKSubsetsHelper(nums, K - 1, vis, targetSubsetSum, 0, 0)

	for i in range(checkIdx, len(nums)):
		if (vis[i] == False and curSubsetSum + nums[i] <= targetSubsetSum):
			vis[i] = True
			if (canPartitionKSubsetsHelper(nums, K, vis, targetSubsetSum, curSubsetSum + nums[i], i + 1)):
				return True

			vis[i] = False

	return False

def canPartitionKSubsets(nums, N, K):
	sum = 0
	maxNum = 0
	for i in range(len(nums)):
		sum += nums[i]
		maxNum = max(maxNum, nums[i])

	if (sum % K != 0 or maxNum > sum / K):
		return False

	vis = [False] * len(nums)
	return canPartitionKSubsetsHelper(nums, K, vis, sum / K, 0, 0)

def takeInput():
    N = int(stdin.readline())
    arr = list(map(int, stdin.readline().strip().split(" ")))
    K = int(stdin.readline())
    return N, arr, K


tc = int(input())
while tc > 0:
    N, arr, K = takeInput()
    ans = canPartitionKSubsets(arr, N, K)
    stdout.write(str(ans) + "\n")
    tc -= 1


# Approach 2 - 
from sys import stdin, stdout, setrecursionlimit
setrecursionlimit(10 ** 7)

def canPartitionKSubsets(arr, n, K):
    dp = [-1 for i in range((1 << n) + 1)]
    tot = 0
    for i in arr:
        tot += i

    if tot % K != 0:
        return False

    eachSum = tot // K 

    dp[0] = 0  
    for mask in range((1 << n)):
        if dp[mask] == -1:  
            continue
        for i in range(0, n):
            if not (mask & (1 << i)) and dp[mask] + arr[i] <= eachSum:
                dp[mask | (1 << i)] = dp[mask] + arr[i]
                dp[mask | (1 << i)] %= eachSum

            if dp[mask | (1 << i)] == 0 and (mask | (1 << i)) == ((1 << n) - 1):
                return True

    return False

def takeInput():
    N = int(stdin.readline())
    arr = list(map(int, stdin.readline().strip().split(" ")))
    K = int(stdin.readline())
    return N, arr, K


tc = int(input())
while tc > 0:
    N, arr, K = takeInput()
    ans = canPartitionKSubsets(arr, N, K)
    stdout.write(str(ans) + "\n")
    tc -= 1