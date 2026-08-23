class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<vector<int>>& res) {
        if(start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            backtrack(start + 1, nums, res);
            swap(nums[start], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(0, nums, res);
        return res;
    }
};