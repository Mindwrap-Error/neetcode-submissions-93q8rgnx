class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        for(int i = 0; i <= n; i++)
        {
            int answer = 0;
            for(int j = 0; j < 32; j++)
            {
                if((i & (1 << j)) == (1 << j)) answer++;
            }
            result[i] = answer;
        }

        return result;
    }
};
