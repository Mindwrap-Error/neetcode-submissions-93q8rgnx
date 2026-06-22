class Solution {
public:
    void genParen(int unclosed, string& curr, vector<string>& result, int n)
    {
        if(curr.size() == 2 * n && unclosed == 0)
        {
            result.push_back(curr);
            return ;
        }
        else if(curr.size() >= 2 * n && unclosed > 0) return;
        curr.push_back('(');
        genParen(unclosed + 1, curr, result, n);
        curr.pop_back();
        if(unclosed > 0)
        {
            curr.push_back(')');
            genParen(unclosed - 1, curr, result, n);
            curr.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
       string curr = "";
       vector<string> result;
       genParen(0, curr, result, n);
       //here the first argument represents the number of unclosed brackets.
       return result; 
    }
};
