class Solution {
public:

    int reachIdx(vector<int>& nums, int goal)
    {
        for(int i = goal - 1; i >= 0; i--)
        {
            if(goal - i <= nums[i]) return i;
        }

        return -1;
    }

    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;

        for(int i = nums.size() - 1; ;)
        {
            if(reachIdx(nums, i) == -1) return false;
            i = reachIdx(nums, i);
            if(i == 0) return true;
        }
    }
};
