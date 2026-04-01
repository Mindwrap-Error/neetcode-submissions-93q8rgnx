class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for(int& a: asteroids)
        {
            while(a < 0 && !stk.empty() && stk.back() > 0)
            {
                int diff = a + stk.back();
                if(diff < 0)
                {
                    stk.pop_back();
                }
                else if(diff > 0)
                {
                    a = 0;
                }
                else
                {
                    a = 0;
                    stk.pop_back();
                }
            }

            if(a != 0)
            {
                stk.push_back(a);
            }
        }

        return stk;
    }
};