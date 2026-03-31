class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores(operations.size(), 0);
        for(const string op: operations)
        {
            if(op == "+")
            {
                int last_score = scores.back();
                int secondlast_score = scores[scores.size()-2];
                scores.push_back(last_score+secondlast_score);
            }
            else if(op == "C")
            {
                scores.pop_back();
            }
            else if (op == "D")
            scores.push_back(scores.back()*2);
            else
            {
                scores.push_back(stoi(op));
            }
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};