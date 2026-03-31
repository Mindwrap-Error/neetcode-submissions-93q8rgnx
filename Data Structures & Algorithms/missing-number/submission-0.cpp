class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        n = n * (n + 1) / 2;

        return n - accumulate(nums.begin(), nums.end(), 0);
    }
};
