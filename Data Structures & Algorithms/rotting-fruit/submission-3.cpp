class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int noRows = grid.size();
        int noCols = grid[0].size();
        int fresh = 0;

        queue<pair<int, int>> rotten;

        for (int i = 0; i < noRows; i++)
        {
            for (int j = 0; j < noCols; j++)
            {
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
                else if (grid[i][j] == 2)
                {
                    rotten.push({i, j});
                }
            }
        }

        if (fresh == 0)
        {
            return 0;
        }

        int count = 0;

        while (!rotten.empty())
        {
            int levelSize = rotten.size();
            bool rottenNow = false;

            for (int i = 0; i < levelSize; i++)
            {
                int a = rotten.front().first;
                int b = rotten.front().second;
                rotten.pop();

                if (a > 0 && grid[a - 1][b] == 1)
                {
                    grid[a - 1][b] = 2;
                    rotten.push({a - 1, b});
                    fresh--;
                    rottenNow = true;
                }

                if (b > 0 && grid[a][b - 1] == 1)
                {
                    grid[a][b - 1] = 2;
                    rotten.push({a, b - 1});
                    fresh--;
                    rottenNow = true;
                }

                if (a < noRows - 1 && grid[a + 1][b] == 1)
                {
                    grid[a + 1][b] = 2;
                    rotten.push({a + 1, b});
                    fresh--;
                    rottenNow = true;
                }

                if (b < noCols - 1 && grid[a][b + 1] == 1)
                {
                    grid[a][b + 1] = 2;
                    rotten.push({a, b + 1});
                    fresh--;
                    rottenNow = true;
                }
            }

            if (rottenNow)
            {
                count++;
            }
        }

        if (fresh == 0)
        {
            return count;
        }
        return -1;
    }
};
