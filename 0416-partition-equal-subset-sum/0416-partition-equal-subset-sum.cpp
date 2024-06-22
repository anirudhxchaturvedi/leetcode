class Solution {
public:
    bool subsetSum(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;  // There's always a way to get sum 0, by picking no elements

        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // If the total sum is odd, it's not possible to partition into two equal subsets
        if (sum % 2 != 0) {
            return false;
        }

        // Check if there's a subset with sum equal to half of total sum
        return subsetSum(nums, sum / 2);
    }
};
