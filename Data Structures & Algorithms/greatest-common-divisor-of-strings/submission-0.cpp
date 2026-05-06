class Solution {
public:
    string repeat(string s, int n) {
    string res = "";
    for (int i = 0; i < n; i++) res += s;
    return res;
    }

    string gcdOfStrings(string str1, string str2) {
        int l = min(str1.size(), str2.size());

        for(; l > 0; l--)
        {
            if(str1.size() % l == 0 && str2.size() % l == 0)
            {
                string prefix = str1.substr(0, l);

                if((repeat(prefix, (int)str1.size() / l) == str1) && (repeat(prefix, (int)str2.size() / l)== str2))
                {
                    return prefix;
                }
            }

        }

        return "";
    }
};