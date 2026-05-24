class Solution {
public:
    void palins(int i, string s, int& result)
    {
        int n = s.size();
        // odd length first;
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            result++;
            l--;
            r++;
        }

        //even length
        l = i; r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            result++;
            l--;
            r++;
        }

        return;
    }

    int countSubstrings(string s) {
        int result = 0;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            palins(i, s, result);
        }
        return result;
    }
};
