class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int dfs(int i, int j, vector<vector<int>>& grid)
    {
        if( i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        {
            return 0;
        }

        grid[i][j] = 0;
        int res = 1;
        for(int k = 0; k < 4; k++)
        {
            res+=dfs(i + directions[k][0], j + directions[k][1], grid);
        }

        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int noRows = grid.size();
        int noCols = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < noRows; i++)
        {
            for(int j = 0; j < noCols; j++)
            {
                if(grid[i][j] == 1)
                {
                    maxArea = max(maxArea, dfs(i, j, grid));
                }
            }
        }

        return maxArea;
    }
};
