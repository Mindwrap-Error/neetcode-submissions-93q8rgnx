class Solution {
public:
    int reachIdx(vector<int>& nums, int goal)
    {
        int currBest = -1;
        for(int i = goal-1; i >= 0; i--)
        {
            if(goal - i <= nums[i]) currBest = max(currBest, goal - i);
        }

        return currBest;
    }

    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        int res = 0;
        for(int i = nums.size() - 1; ;)
        {
            i -= reachIdx(nums, i);
            res++;
            if(i == 0) break;
        }

        return res;
    }
};
