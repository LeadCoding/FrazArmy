// Approach 1 --
public class Solution {

	private static boolean canPartitionKSubsetsHelper(int[] nums, int K, boolean[] vis, int targetSubsetSum,
			int curSubsetSum, int checkIdx) {

		if (K == 0) {
			return true;
		}

		if (curSubsetSum == targetSubsetSum) {
			return canPartitionKSubsetsHelper(nums, K - 1, vis, targetSubsetSum, 0, 0);
		}

		for (int i = checkIdx; i < nums.length; i++) {
			if (vis[i] == false && curSubsetSum + nums[i] <= targetSubsetSum) {
				vis[i] = true;
				if (canPartitionKSubsetsHelper(nums, K, vis, targetSubsetSum, curSubsetSum + nums[i], i + 1)) {
					return true;
				}

				vis[i] = false;
			}

		}

		return false;
	}

	public static boolean canPartitionKSubsets(int[] nums, int n, int K) {
		int sum = 0;
		int maxNum = 0;
		for (int i = 0; i < nums.length; i++) {
			sum += nums[i];
			maxNum = Math.max(maxNum, nums[i]);
		}

		if (sum % K != 0 || maxNum > sum / K) {
			return false;
		}

		boolean[] vis = new boolean[n];
		return canPartitionKSubsetsHelper(nums, K, vis, sum / K, 0, 0);
	}

}

// Approach 2 --
public class Solution {

	public static boolean canPartitionKSubsets(int[] nums, int n, int K) {
		int[] dp = new int[(1 << n) + 1];
		for (int i = 0; i < dp.length; i++) {
			dp[i] = -1;
		}

		int tot = 0;
		for (int i = 0; i < nums.length; i++) {
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
				if ((mask & (1 << i))==0 && dp[mask] + nums[i] <= eachSum) {
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
}