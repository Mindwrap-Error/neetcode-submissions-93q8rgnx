class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int INF = 1e9;
        int res = nums[0];
        int mini = nums[0];
        int maxi = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int maxP = nums[i] * maxi;
            int minP = nums[i] * mini;
            maxi = max(nums[i], max(maxP, minP)); 
            mini = min(nums[i], min(maxP, minP));

            res = max(res, max(mini, maxi));
        }
        return res;
    }
};
