class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = -1, votes1 = 0;
        int candidate2 = -1, votes2 = 0;

        for(auto x: nums)
        {
            if(x == candidate1) votes1++;
            else if(x == candidate2) votes2++;
            else if(votes1 == 0) {candidate1 = x; votes1 = 1;}
            else if(votes2 == 0) {candidate2 = x; votes2 = 1;}
            else {votes1--; votes2--;}
        }

        int cnt1 = 0, cnt2 = 0;
        for(auto x: nums)
        {
            if(x == candidate1) cnt1++;
            if(x == candidate2) cnt2++;
        }

        vector<int> result;
        int threshold = nums.size() / 3;

        if(cnt1 > threshold) result.push_back(candidate1);
        if(cnt2 > threshold && (candidate1 != candidate2)) result.push_back(candidate2);

        return result;
    }
};