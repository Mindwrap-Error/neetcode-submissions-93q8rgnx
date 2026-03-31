class Solution {
public:
    void sortColors(vector<int>& nums) {
        int frequency[3] = {0};
        for(int& x: nums)
        {
            frequency[x]++;
        }

        int index = 0;
        for(int i = 0; i < 3; i++)
        {
            while(frequency[i]-- > 0)
            {
                nums[index] = i;
                index++;
            }
        }
    }
};