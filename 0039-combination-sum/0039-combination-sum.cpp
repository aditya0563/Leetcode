class Solution {
public:
    void backtrack(int idx, int target, vector<int>& curr, vector<vector<int>>& res, const vector<int>& candidates) {
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        if(target < 0) return;
        for(int i = idx; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            backtrack(i, target - candidates[i], curr, res, candidates);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(0, target, curr, res, candidates);
        return res;
    }
};