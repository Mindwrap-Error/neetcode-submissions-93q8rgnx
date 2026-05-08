class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int maxi = 0;

        while(left < right) 
        {
            int curr = min(heights[right], heights[left]) * (right - left);
            maxi = max(maxi, curr);

            if(heights[left] > heights[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return maxi;
    }
};

//i think the idea is to keep increasing the local maximum. so 
//we begin at left and right pointers at 0 and end()

/*
we then take that area and check whether right-- or left++ is greater
then we switch to that all until left < right
*/
