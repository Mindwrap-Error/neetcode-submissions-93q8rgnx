class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        int noRows = grid.size();
        int noCols = grid[0].size();

        for(int i = 0; i < noRows; i++)
        {
            for(int j = 0; j < noCols; j++)
            {
                if(grid[i][j] == 1)
                {
                    fresh++;
                }
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(fresh > 0 && !q.empty())
        {
            int length = q.size();
            for(int i = 0; i < length; i++)
            {
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for(const auto& dir: directions)
                {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if(row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size() && grid[row][col] == 1)
                    {
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }

            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
