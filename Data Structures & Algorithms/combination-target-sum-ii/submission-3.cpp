class Solution {
public:
   void generateCombos(int idx, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result, int remainingTarget)
   {
        if(remainingTarget == 0)
        {
            result.push_back(current);
            return;
        }
        else if(remainingTarget < 0 || idx >= candidates.size())
        {
            return;
        }
        current.push_back(candidates[idx]);
        generateCombos(idx + 1, candidates, current, result, remainingTarget - candidates[idx]);
        current.pop_back();
        int temp = idx;
        while(idx < candidates.size() && candidates[idx] == candidates[temp]) idx++;
        generateCombos(idx, candidates, current, result, remainingTarget);
   } 
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<int> current;
       vector<vector<int>> result;
       sort(candidates.begin(), candidates.end());
       generateCombos(0, candidates, current, result, target);
       return result; 
    }
};
