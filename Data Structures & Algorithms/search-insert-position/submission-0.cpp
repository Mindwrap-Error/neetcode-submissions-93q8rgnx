class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int first = 0, last = nums.size();
        int middle = (first+last)/2;
        while(first < last)
        {
            middle = (first+last)/2;
            if(nums[first] > target)
            return first;
            if(nums[last-1] < target)
            return last;

            if(nums[middle] == target)
            {
                return middle;
            }
            if(nums[middle] > target)
            {
                last = middle;
            }
            else
            {
                first = middle+1;
            }
        }
        /*if(nums[middle] > target)
        {
            return middle-1;
        }
        else
        {
            return middle+1;
        }*/
    }
};