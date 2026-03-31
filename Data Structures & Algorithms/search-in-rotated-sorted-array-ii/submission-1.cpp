class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(target == nums[mid] || target == nums[high] || target == nums[low])
            {
                return true;
            }

            if(nums[mid] == nums[low] && nums[low] == nums[high])
            {
                low++;
                high--;
            }

            if(nums[mid] >= nums[low])
            {
                if(target <= nums[mid] && target >= nums[low])
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else if(nums[mid] <= nums[high])
            {
                if(target <= nums[high] && target >= nums[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};