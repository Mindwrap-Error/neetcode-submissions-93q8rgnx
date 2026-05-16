class Solution {
public:
    int find(int x, vector<int>& link)
    {
        while(x != link[x]) x = link[x];
        return x;
    }

    bool same(int a, int b, vector<int>& link)
    {
        return find(a, link) == find(b, link);
    }

    void unite(int a, int b, vector<int>& link, vector<int>& size)
    {
        a = find(a, link);
        b = find(b, link);

        if(size[b] < size[a]) swap(a, b);

        link[a] = b;
        size[b] += size[a];
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adj;
        int cost = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj.push_back({dist, i, j});
            }
        }

        sort(adj.begin(), adj.end());

        vector<int> link(n);
        for(int i = 0; i < n; i++)
        {
            link[i] = i;
        }
        vector<int> size(n, 1);

        for(int i = 0; i < adj.size(); i++)
        {
            if(!same(adj[i][1], adj[i][2], link))
            {
                unite(adj[i][2], adj[i][1], link, size);
                cost += adj[i][0];
            }
        }

        return cost;
    }
};
