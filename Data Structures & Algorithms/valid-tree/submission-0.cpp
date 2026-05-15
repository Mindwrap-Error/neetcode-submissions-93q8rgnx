class Solution {
public:
    void dfs(int index, vector<vector<int>>& adj, vector<bool>& visited)
    {
        visited[index] = true;

        for(int x: adj[index])
        {
            if(!visited[x]) dfs(x, adj, visited);
        }
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n, false);

        dfs(0, adj, visited);

        for(int i = 0; i < n; i++)
        {
            if(!visited[i]) return false;
        }

        return true;
    }
};
