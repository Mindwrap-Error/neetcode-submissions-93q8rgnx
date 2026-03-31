class Solution {
public:
    bool canShip(vector<int>& weights, int days, int cap)
    {
        int curr_days = 0;
        int curr_load = 0;

        for(int w: weights)
        {
            if(curr_load + w <= cap)
            {
                curr_load += w;
            }
            else
            {
                curr_days++;
                if(curr_days > days) return false;
                curr_load = w;
            }
        }

        return curr_days < days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
       int low = *max_element(weights.begin(), weights.end());
       int high = accumulate(weights.begin(), weights.end(), 0);

       while(low < high)
       {
        int mid = low + (high - low) / 2;
        if(canShip(weights, days, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
       }

       return low;
    }
};