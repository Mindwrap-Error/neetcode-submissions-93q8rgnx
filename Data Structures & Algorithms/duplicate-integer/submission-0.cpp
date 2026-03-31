class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> frequency;
        for(int i = 0; i < nums.size(); i++)
        {
            if(frequency[nums[i]] == 0)
            {
                frequency[nums[i]]++;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};