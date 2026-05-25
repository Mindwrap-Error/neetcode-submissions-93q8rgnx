class Solution {
public:
    bool makeSum(int idx, vector<int>& nums, int target)
    {
        if(target == 0) return true;
        if(target < 0 || idx >= nums.size()) return false;
    
        return makeSum(idx + 1, nums, target - nums[idx]) || makeSum(idx + 1, nums, target);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum & 1) return false;
        int toMake = sum / 2;

        return makeSum(0, nums, toMake);
    }
};
