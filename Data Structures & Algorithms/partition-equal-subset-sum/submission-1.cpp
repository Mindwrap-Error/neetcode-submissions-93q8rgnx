class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum & 1) return false;
        int toMake = sum / 2;
        vector<bool> dp(toMake + 1, false);
        dp[0] = true;

        for(int num: nums)
        {
            for(int j = toMake; j >= num; j--)
            {
                if(dp[j-num] == true) dp[j] = true;
            }
        }
        return dp[toMake];
    }
};
