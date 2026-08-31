class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        counts[0] = 1;
        int sum = 0;
        int res = 0;
        for (int num : nums) {
            sum += num;
            if (counts.find(sum - k) != counts.end()) {
                res += counts[sum - k];
            }
            counts[sum]++;
        }
        return res;
    }
};