class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double max_so_far = nums[0];
        double min_so_far = nums[0];
        double res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) swap(max_so_far, min_so_far);
            max_so_far = max((double)nums[i], max_so_far * nums[i]);
            min_so_far = min((double)nums[i], min_so_far * nums[i]);
            res = max(res, max_so_far);
        }
        return res;
    }
};