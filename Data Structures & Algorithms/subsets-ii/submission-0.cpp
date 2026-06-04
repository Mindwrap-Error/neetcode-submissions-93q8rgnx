class Solution {
public:
    void generateSubsets(int idx, vector<int>& nums, vector<int>& curr, vector<vector<int>>& result)
    {
        if(idx >= nums.size())
        {
            result.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        generateSubsets(idx + 1, nums, curr, result);
        curr.pop_back();
        int temp = idx;
        while(idx < nums.size() && nums[idx] == nums[temp]) idx++;
        generateSubsets(idx, nums, curr, result);
    } 

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<int> current;
       vector<vector<int>> result;
       sort(nums.begin(), nums.end());
       generateSubsets(0, nums, current, result);
       return result; 
    }
};
