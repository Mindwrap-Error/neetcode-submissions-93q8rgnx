class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       if(numRows == 1) return vector<vector<int>>{{1}};
       else if(numRows == 2) return vector<vector<int>>{{1}, {1, 1}};

       vector<vector<int>> result = {{1}, {1, 1}};
       for(int i = 3; i <= numRows; i++)
       {
        result.push_back(vector<int>(i, 1));
        for(int j = 1; j < i - 1; j++)
        {
            result[i - 1][j] = result[i - 2][j - 1] + result[i - 2][j];
        }
       } 
       return result;
    }
};