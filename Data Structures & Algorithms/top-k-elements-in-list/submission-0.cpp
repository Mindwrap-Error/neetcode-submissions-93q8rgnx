class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // aim for O N time and O N space 
        unordered_map<int, int> freq;
        for(int& n: nums)
        {
            freq[n]++;
        }

        vector<vector<int>> buckets(nums.size()+1);
        for(const auto& entry: freq)
        {
            buckets[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for(int i = buckets.size()-1; i > 0; i--)
        {
            for(int n: buckets[i])
            {
                res.push_back(n);
                if(res.size() == k)
                {
                    return res;
                }
            }
        }
        return res;
    }
};
