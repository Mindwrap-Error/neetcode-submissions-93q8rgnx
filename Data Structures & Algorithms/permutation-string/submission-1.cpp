class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       if(s1.size() > s2.size()) return false;

        int windowSize = s1.size();

        vector<int> freq1(26);
        vector<int> freq2(26);

        for(int i = 0; i < s1.size(); i++)
        {
            freq1[s1[i] - 97]++;
            freq2[s2[i] - 97]++;
        }

        int left = 0;
        int right = s1.size() - 1;

        if(freq1 == freq2) return true;

        while(right < s2.size())
        {
            freq2[s2[left] - 97]--;
            left++;
            right++;
            if(right >= s2.size()) break;
            freq2[s2[right] - 97]++;

            if(freq1 == freq2) return true;
        }

        return false;
    }
};
