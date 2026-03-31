class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<vector<int>> trustScores(n, vector<int>(2, 0));

        for(int i = 0; i < trust.size(); i++)
        {
            trustScores[trust[i][0] - 1][0]++;
            trustScores[trust[i][1] - 1][1]++;
        }

        for(int i = 0; i < n; i++)
        {
            if(trustScores[i][0] == 0 && trustScores[i][1] == n - 1)
            {
                return i + 1;
            }
        }

        return -1;
    }
};