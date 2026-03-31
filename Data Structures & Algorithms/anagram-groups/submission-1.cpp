class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        vector<vector<string>> answer;
        for(int i = 0; i < strs.size(); i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            hashMap[tmp].push_back(strs[i]);
        }

        for(auto const& it: hashMap)
        {
            answer.push_back(it.second);
        }

        return answer;
    }
};
