class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m < n) swap(m, n);
        long long int result = 1;
        m--;
        n--;
        for(int i = 1; i <= n; i++)
        {
            result =  result * (m + i) / i;
        }
        return (int)result;
    }
};
