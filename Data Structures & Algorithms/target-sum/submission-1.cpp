class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        if((abs(target) > sum) || ((sum + target) & 1)) return 0;
        
        int p = (target + sum) / 2;
        target = p;

        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = target; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};
