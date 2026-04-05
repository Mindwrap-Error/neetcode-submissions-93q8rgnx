class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, bool> isPresent;

        for(int i = 0; i < nums.size(); i++)
        {
            isPresent[nums[i]] = true;
        }

        for(int i = 1; i < INT_MAX; i++)
        {
            if(isPresent[i] == false)
            {
                return i
                ;
            }
        }
    }
};