class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int mid;

        while(low < high)
        {
            mid = low + (high - low) / 2;
            long long sum = 0;
            for(int i = 0; i < piles.size(); i++)
            {
                sum += (piles[i] + mid - 1LL) / mid; 
            }

            if(sum <= h)
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
