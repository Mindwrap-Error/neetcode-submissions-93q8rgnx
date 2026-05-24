class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for(int i = 0; i < wordDict.size(); i++)
        {
            dict.insert(wordDict[i]);
        }
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for(int i = 1; i <= n; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(dp[j] == true && dict.contains(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
