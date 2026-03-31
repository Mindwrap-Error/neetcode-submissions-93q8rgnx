class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();

        if(m + n == 2)
        {
            return grid[0][0];
        }

        for(int k = 1; k < n; k++)
        {
            grid[k][0] += grid[k-1][0];
        }

        for(int k = 0; k < m; k++)
        {
            grid[0][k] += grid[0][k-1];
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }

        return grid[n-1][m-1];
    }
};