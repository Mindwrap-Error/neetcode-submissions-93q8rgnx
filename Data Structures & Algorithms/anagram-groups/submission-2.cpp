class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> hashMap;
       vector<vector<string>> answer;

        for(int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            hashMap[temp].push_back(strs[i]);
        }

        for(auto const& it: hashMap)
        {
            answer.push_back(it.second);
        }
       return answer; 
    }
};
