class Solution {
public:
    bool isValid(string s) {
        vector<char> sequence;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '{' || s[i] == '['|| s[i] == '(')
            {
                sequence.push_back(s[i]);
            }
            else
            {
                if(sequence.empty())
                {
                    return false;
                }
                else if ((s[i] == '}' && sequence.back() == '{') || (s[i] == ']' && sequence.back() == '[') || (s[i] == ')' && sequence.back() == '('))
                {
                    sequence.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }
        return sequence.empty();
    }
};
