class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited)
    {
        if(visited[i][j] || grid[i][j] == '0') return;
        if(grid[i][j] == '1') visited[i][j] = true;

        if(i < grid.size() - 1) dfs(i+1, j, grid, visited);
        if(i > 0) dfs(i-1, j, grid, visited);
        if(j < grid[0].size() - 1) dfs(i, j+1, grid, visited);
        if(j > 0) dfs(i, j-1, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int noRows = grid.size();
        int noCols = grid[0].size();
        vector<vector<bool>> visited(noRows, vector<bool>(noCols, false));
        int count = 0;
        for (int i = 0; i < noRows; i++)
        {
            for (int j = 0; j < noCols; j++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(i, j, grid, visited);
                    count++;
                }
            }
        }

        return count;
    }
};
