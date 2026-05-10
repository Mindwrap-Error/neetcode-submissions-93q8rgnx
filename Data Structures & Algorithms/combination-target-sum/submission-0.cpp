class Solution {
public:
    void generateCombos(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result, int remainingTarget)
    {
        if(remainingTarget == 0)
        {
            result.push_back(current);
            return;
        }
        if(remainingTarget < 0 || index >= nums.size())
        {
            return;
        }
        current.push_back(nums[index]);
        generateCombos(index, nums, current, result, remainingTarget - nums[index]);
        current.pop_back();
        generateCombos(index + 1, nums, current, result, remainingTarget);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        generateCombos(0, nums, current, result, target);
        return result;
    }
};
