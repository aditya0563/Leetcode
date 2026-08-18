class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int count[51] = {0};
        for (int num : nums) {
            count[num]++;
        }
        if (k == n) {
            int max_val = -1;
            for (int num : nums) {
                max_val = max(max_val, num);
            }
            return max_val;
        }
        if (k == 1) {
            int max_val = -1;
            for (int num : nums) {
                if (count[num] == 1) {
                    max_val = max(max_val, num);
                }
            }
            return max_val;
        }
        int max_val = -1;
        if (count[nums[0]] == 1) {
            max_val = max(max_val, nums[0]);
        }
        if (count[nums[n - 1]] == 1) {
            max_val = max(max_val, nums[n - 1]);
        }
        return max_val;
    }
};