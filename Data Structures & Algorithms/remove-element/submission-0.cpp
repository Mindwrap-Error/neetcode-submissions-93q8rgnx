class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int k = 0;
       for(int i = 0; i < nums.size(); i++)
       {
        if(nums[i] != val) {k++;}
       } 
        vector<int> tmp;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
            {
                tmp.push_back(nums[i]);
            }
        }
        nums = tmp;
        return nums.size();
    }
};