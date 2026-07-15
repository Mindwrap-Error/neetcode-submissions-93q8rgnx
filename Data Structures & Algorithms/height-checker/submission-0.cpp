class Solution {
public:
    int heightChecker(vector<int>& heights) {
       vector<int> tmp = heights;
       int count = 0;
       sort(heights.begin(), heights.end());
       for(int i = 0; i < heights.size(); i++)
       {
        if(heights[i] != tmp[i]) count++;
       } 
       return count;
    }
};