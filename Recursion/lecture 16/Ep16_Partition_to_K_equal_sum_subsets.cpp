// Approach 1 --
bool canPartitionKSubsetsHelper(vector<int> &nums, int K, vector<bool> &vis, int targetSubsetSum, int curSubsetSum, int checkIdx) 
{
	if (K == 0) 
    {
		return true;
	}

	if (curSubsetSum == targetSubsetSum) 
    {
		return canPartitionKSubsetsHelper(nums, K - 1, vis, targetSubsetSum, 0, 0);
	}

	for (int i = checkIdx; i < nums.size(); i++) 
    {
		if (vis[i] == false && curSubsetSum + nums[i] <= targetSubsetSum) 
        {
			vis[i] = true;
			if (canPartitionKSubsetsHelper(nums, K, vis, targetSubsetSum, curSubsetSum + nums[i], i + 1)) 
            {
				return true;
			}

			vis[i] = false;
		}
	}
	return false;
}

bool canPartitionKSubsets(vector<int> &nums, int N, int K) 
{
	int sum = 0;
	int maxNum = 0;
	for (int i = 0; i < nums.size(); i++) 
    {
		sum += nums[i];
		maxNum = max(maxNum, nums[i]);
	}

	if (sum % K != 0 || maxNum > sum / K) 
    {
		return false;
	}

    vector<bool> vis(nums.size(),false);
	return canPartitionKSubsetsHelper(nums, K, vis, sum / K, 0, 0);
}


// Approach 2 --
bool canPartitionKSubsets(vector<int>& nums, int n, int K)
{
    int dp[(1 << n) + 1];
    memset(dp, -1, sizeof dp);

    int tot = 0;
    for (int i = 0; i < nums.size(); i++) {
        tot += nums[i];
    }

    if (tot % K != 0) {
        return false;
    }

    int eachSum = tot / K;

    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == -1) {
            continue;
        }

        for (int i = 0; i <= n - 1; i++) {
            if ( !(mask & (1 << i)) &&  dp[mask] + nums[i] <= eachSum) {
                dp[mask | (1 << i)] = dp[mask] + nums[i];
                dp[mask | (1 << i)] %= eachSum;
                if (dp[mask | (1 << i)] == 0 && (mask | (1 << i)) == ((1 << n) - 1)) {
                    return true;
                }
            }

        }

    }

    return false;
}