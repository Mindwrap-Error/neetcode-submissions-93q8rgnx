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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> link(n + 1);
        vector<int> size(n + 1, 1);

        for(int i = 0; i <= n; i++)
        {
            link[i] = i;
        }

        for(int i = 0; i < edges.size(); i++)
        {
            if(same(edges[i][0], edges[i][1], link))
            {
                return edges[i];
            }
            else
            {
                unite(edges[i][0], edges[i][1], link, size);
            }
        }
    }
};
