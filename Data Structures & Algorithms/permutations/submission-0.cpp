class Solution {
public:
    void generatePerms(vector<int>& nums, vector<int>& curr, vector<vector<int>>& result, vector<bool>& taken)
    {
        if(curr.size() == nums.size())
        {
            result.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(taken[i] == true) continue;
            else
            {
                curr.push_back(nums[i]);
                taken[i] = true;
                generatePerms(nums, curr, result, taken);
                curr.pop_back();
                taken[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
       vector<int> curr;
       vector<vector<int>> result; 
       vector<bool> taken(nums.size(), false);
       generatePerms(nums, curr, result, taken);
       return result;
    }
};
