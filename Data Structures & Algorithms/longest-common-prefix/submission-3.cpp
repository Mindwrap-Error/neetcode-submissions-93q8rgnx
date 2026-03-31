class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = strs[0];
        if(strs.size() == 1)
        {
            return strs[0];
        }
        if(strs[0][0] != strs[1][0])
        {
            return "";
        }

        for(int i = 1; i < strs.size(); i++)
        {
            string tmp = "";
            for(int j = 0; j < min(strs[i].size(), answer.size()); j++)
            {
                if(strs[i][j] == answer[j])
                {
                    tmp += strs[i][j];
                }
                else
                {
                    continue;
                }
            }
            answer = tmp;
        }
        return answer;
    }
};