class Solution {
public:
    int minDistance(string word1, string word2) {
       int n = word1.size();
       int m = word2.size();

       vector<int> dp(m + 1);
       for(int i = 1; i <= m; i++)
       {
        dp[i] = i;
       } 

       for(int i = 1; i <= n; i++)
       {
        int prev_diag = dp[0];
        dp[0] = i;

        for(int j = 1; j <= m; j++)
        {
            int temp = dp[j];
            if(word1[i - 1] == word2[j - 1]) dp[j] = prev_diag;
            else
            dp[j] = 1 + min({dp[j], dp[j-1], prev_diag});

            prev_diag = temp;
        }
       }
       return dp[m];
    }
};
