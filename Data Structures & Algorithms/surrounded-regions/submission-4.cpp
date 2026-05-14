class Solution {
    int m;
    int n;
public:
    bool valid(int i, int j, int m, int n)
    {
        return (i >= 0 && i < m && j < n && j >= 0);
    }

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited)
    {
        visited[i][j] = true;

        if(valid(i + 1, j, m, n) && board[i+1][j] == 'O' && !visited[i + 1][j]) dfs(i + 1, j, board, visited);
        if(valid(i - 1, j, m, n) && board[i-1][j] == 'O' && !visited[i - 1][j]) dfs(i - 1, j, board, visited);
        if(valid(i, j + 1, m, n) && board[i][j+1] == 'O' && !visited[i][j + 1]) dfs(i, j + 1, board, visited);
        if(valid(i, j - 1, m, n) && board[i][j-1] == 'O' && !visited[i][j - 1]) dfs(i, j - 1, board, visited);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < n; i++)
        {
            if(board[m-1][i] == 'O' && !visited[m-1][i]) dfs(m-1, i, board, visited);
            if(board[0][i] == 'O' && !visited[0][i]) dfs(0, i, board, visited);
        }

        for(int j = 0; j < m; j++)
        {
            if(board[j][0] == 'O' && !visited[j][0]) dfs(j,  0, board, visited);
            if(board[j][n-1] == 'O' && !visited[j][n-1]) dfs(j, n-1, board, visited);
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X'; 
            }
        }

        return;
    }
};
