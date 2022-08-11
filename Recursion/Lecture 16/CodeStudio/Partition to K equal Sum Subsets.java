/* This question is based on reqSum Sum problem.   
   We need to fill k buckets(using all the elements) of nums[]. Sum of each bucket should be same.
   By doing a bit maths, we can easily calculate the reqSum of each bucket, which is, (totalSum / k)
    we keep an array for sum of each partition and a boolean array to check whether an element 
    is already taken into some partition or not. 
*/

public class Solution 
{
    static boolean help(int[] nums, int subsetSum[], boolean taken[], int reqSum, int K, int n, int curIdx, int limitIdx) {

        if (subsetSum[curIdx]==reqSum) {

            /*  current index (K - 2) represents (K - 1) subsets of equal
            sum last partition will already remain with sum 'subset'*/

            if (curIdx==K - 2) return true;

            //  recursive call for next subsetition
            return help(nums, subsetSum, taken, reqSum, K, n, curIdx + 1, n - 1);
        }

        //  start from limitIdx and include elements into current partition
        for (int i=limitIdx; i >=0; i--) {

            //  if already taken, continue
            if (taken[i]) 
                continue;
            int tmp=subsetSum[curIdx]+nums[i];

            // if temp is less than subset then only include the element and call recursively
            if (tmp <=reqSum) {

                //  mark the element and include into current partition sum
                taken[i]=true;
                subsetSum[curIdx]+=nums[i];
                boolean nxt=help(nums, subsetSum, taken, reqSum, K, n, curIdx, i - 1);

                // after recursive call unmark the element and remove from subsetition sum
                taken[i]=false;
                subsetSum[curIdx] -=nums[i];

                if (nxt) return true;
            }
        }

        return false;
    }
	public static boolean canPartitionKSubsets(int[] nums, int n, int K) 
    {
        //  If K is 1, then complete array will be our answer
        if (K==1) return true;

        //  If total number of partitions are more than n, then division is not possible
        if (n < K) return false;

        // if array sum is not divisible by K then we can't divide array into K partitions
        int sum=0;
        for (int i=0; i < n; i++) sum+=nums[i];
        if (sum % K !=0) return false;

        //  the required sum of each subset = sum / K
        int reqSum=sum / K;
        int subsetSum[] = new int[K];
        boolean taken[] = new boolean[n];

        //  Initialize sum of each subset from 0
        for (int i=0; i < K; i++) subsetSum[i]=0;

        //  mark all elements as not taken
        for (int i=0; i < n; i++) taken[i]=false;

        // initialize first subset sum as last element of
        // array and mark that as taken
        subsetSum[0]=nums[n - 1];
        taken[n - 1]=true;

        //  call recursive method to check K-substitution condition
        return help(nums, subsetSum, taken, reqSum, K, n, 0, n - 1);
	}
}

/* 
Time Complexity:  O(2^(n * K))
Space Complexity: O(n)
*/
