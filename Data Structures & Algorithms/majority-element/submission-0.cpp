class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;

        for(int i = 0; i < nums.size(); i++)
        {
            if(count == 0)
            {
                candidate = nums[i];
                count++;
            }
            if(nums[i] != candidate)
            {
                count--;
            }
            if(nums[i] == candidate)
            {
                count++;
            }
        }
        return candidate;
        count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == candidate)
            {
                count++;
            }
        }
        if(count > nums.size()/2)
        {
            return candidate;
        }
    }
};