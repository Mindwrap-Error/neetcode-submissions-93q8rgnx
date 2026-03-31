class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0, last = nums.size();
        while(first < last)
        {
        int mid = (first+last)/2;
        if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[mid] > target)
            {
                last = mid;
            }
            else{
                first = mid+1;
            }
        }
        return -1;
    }
};
