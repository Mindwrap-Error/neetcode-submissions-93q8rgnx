class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> occr(128, -1);
        int left = 0;
        int best = 0;

        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;

        for(int i = 0; i < s.size(); i++)
        {
            if(occr[s[i]] != -1 && occr[s[i]] >= left)
            {
                left = occr[s[i]] + 1; 
            }
            occr[s[i]] = i;
            best = max(best, i - left + 1);
        }

        return best;
    }
};
