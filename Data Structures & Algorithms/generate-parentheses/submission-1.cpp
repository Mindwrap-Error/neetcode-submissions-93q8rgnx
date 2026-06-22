class Solution {
public:
    void backtrack(int openCount, int closeCount, string& curr, vector<string>& result, int n)
    {
        if(curr.size() == 2 * n)
        {
            result.push_back(curr);
            return;
        }

        if(openCount < n)
        {
            curr.push_back('(');
            backtrack(openCount + 1, closeCount, curr, result, n);
            curr.pop_back();
        }

        if(closeCount < openCount)
        {
            curr.push_back(')');
            backtrack(openCount, closeCount + 1, curr, result, n);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> result;
        backtrack(0, 0, curr, result, n);
        return result;
    }
};
