class Solution {
public:
    bool hasCycle(int node, vector<vector<int>>& adj, vector<int>& state, vector<int>& result)
    {
        state[node] = 1;
        for(int neighbour: adj[node])
        {
            if(state[neighbour] == 1) return true;

            if(state[neighbour] == 0)
            {
                if(hasCycle(neighbour, adj, state, result)) return true;
            }
        }

        state[node] = 2;
        result.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> adj(numCourses
        );
        for(int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++)
        {
            if(state[i] == 0)
            {
                if(hasCycle(i, adj, state, result))
                {
                    return {};
                }   
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
