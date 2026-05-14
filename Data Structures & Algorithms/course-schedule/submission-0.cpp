class Solution {
public:
    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& state)
    {
        state[node] = 1;

        for(int neighbour: adj[node])
        {
            if(state[neighbour] == 1) return true;

            if(state[neighbour] == 0)
            {
                if(hasCycle(neighbour, adj, state))
                {
                    return true;
                }
            }
        }

        state[node] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
        }

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++)
        {
            if(state[i] == 0)
            {
                if(hasCycle(i, adj, state)) return false;
            }
        }

        return true;
    }
};
