class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for(int i = 0; i < times.size(); i++)
        {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        const int INF = 1e9;
        vector<int> dist(n + 1, INF);

        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty())
        {
            auto[t, edge] = pq.top();
            pq.pop();

            if(t > dist[edge]) continue;

            for(const auto& u: adj[edge])
            {
                int v = u.first;
                int time = u.second;

                if(dist[edge] + time < dist[v])
                {
                    dist[v] = dist[edge] + time;
                    pq.push({dist[v], v});
                }
            }
        }

        int max_time = 0;
        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INF) return -1;
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }
};
