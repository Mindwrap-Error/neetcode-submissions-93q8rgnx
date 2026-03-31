class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;

        int noRows = grid.size();
        int noCols = grid[0].size();

        for(int i = 0; i < noRows; i++)
        {
            for (int j = 0; j < noCols; j++)
            {
                if(grid[i][j] == 1)
                {
                    perimeter += (i + 1 >= noRows || grid[i+1][j] == 0) ? 1 : 0;
                    perimeter += (j + 1 >= noCols || grid[i][j+1] == 0) ? 1 : 0;
                    perimeter += (i - 1 < 0 || grid[i-1][j] == 0) ? 1 : 0;
                    perimeter += (j - 1 < 0 || grid[i][j-1] == 0) ? 1 : 0;
                }
            }
        }
        return perimeter;
    }
};