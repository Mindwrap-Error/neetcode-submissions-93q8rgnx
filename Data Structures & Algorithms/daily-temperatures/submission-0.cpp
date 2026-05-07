class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);

        stack<int> s;

        for(int i = 0; i < temperatures.size(); i++)
        {
            if(s.empty()) s.push(i);
            else if(temperatures[s.top()] >= temperatures[i]) 
            {
                s.push(i);
            }
            else
            {
                while(!s.empty() && temperatures[s.top()] < temperatures[i])
                {
                    res[s.top()] = i - s.top();
                    s.pop();
                }
                s.push(i);
            }
        }

        return res;
    }
};
